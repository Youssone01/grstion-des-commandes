#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QPieSeries>
#include <QPieSlice>
#include <QColor>
#include <QChart>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Commande.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QBrush>
#include <QColor>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Assurez-vous que les champs sont vides et configurés avec des placeholders
    ui->lineEdit_id->clear();  // Vider le champ
    ui->lineEdit_date->clear();  // Vider le champ
    ui->lineEdit_statut->clear();  // Vider le champ
    ui->lineEdit_paiement->clear();  // Vider le champ
    // Refresh the table view after deletion
    Commande commande;
    QSqlQueryModel *model = commande.afficherCommande();
    ui->tableView->setModel(model);


    // Connexion des actions (si vous avez ces boutons)
    connect(ui->supprimerbutton, &QPushButton::clicked, this, &MainWindow::on_supprimerbutton_clicked);
    connect(ui->Ajouter, &QPushButton::clicked, this, &MainWindow::on_Ajouter_clicked);
    connect(ui->modifierbutton, &QPushButton::clicked, this, &MainWindow::on_modifierbutton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_supprimerbutton_clicked()
{
    // Retrieve the ID from the QLineEdit named 'supp'
    QString idText = ui->supp->text();

    // Check if the input is valid and not empty
    if (idText.isEmpty()) {
        qDebug() << "Erreur : Aucun ID spécifié dans le champ de saisie.";
        return;
    }

    bool ok;
    int id = idText.toInt(&ok); // Convert the text to an integer

    // Ensure the conversion to integer was successful
    if (!ok) {
        qDebug() << "Erreur : L'ID entré n'est pas un nombre valide.";
        return;
    }

    // Create an instance of the Commande class
    Commande commande;

    // Call the supprimer function with the ID
    if (commande.supprimer(id)) {
        qDebug() << "Commande supprimée avec succès!";

        // Refresh the display after deletion
        QSqlQueryModel *model = commande.afficherCommande(); // Use afficherCommande to update the data
        ui->tableView->setModel(model); // Apply the updated model to the table view

        // Clear the QLineEdit after successful deletion
        ui->supp->clear();
    } else {
        qDebug() << "Erreur lors de la suppression de la commande!";
    }
}

void MainWindow::on_Ajouter_clicked()
{
    // Récupération des données entrées par l'utilisateur
    int id = ui->lineEdit_id->text().toInt();
    QString date = ui->lineEdit_date->text();
    QString statut = ui->lineEdit_statut->text();
    QString modePaiement = ui->lineEdit_paiement->text();

    // Vérification que l'ID est valide
    if (id <= 0) { // Un ID négatif ou nul est invalide
        QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre entier positif !");
        return;
    }

    // Vérification du format de la date
    QDate parsedDate = QDate::fromString(date, "yyyy-MM-dd"); // Exemple : 2024-01-01
    if (!parsedDate.isValid()) {
        QMessageBox::warning(this, "Erreur", "La date est invalide ! Utilisez le format AAAA-MM-JJ.");
        return;
    }

    // Vérification que tous les champs sont remplis
    if (statut.isEmpty() || modePaiement.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Création d'une instance de Commande
    Commande cmd(id, date, statut, modePaiement);

    // Tentative d'ajout de la commande
    if (cmd.ajouterCommande()) {
        QMessageBox::information(this, "Succès", "Commande ajoutée avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la commande ! Veuillez vérifier les données ou la connexion à la base de données.");
    }
}


void MainWindow::on_modifierbutton_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString date = ui->lineEdit_date->text();
    QString statut = ui->lineEdit_statut->text();
    QString modePaiement = ui->lineEdit_paiement->text();

    Commande cmd(id, date, statut, modePaiement);
    if (cmd.modifierCommande()) {
        QMessageBox::information(this, "Succès", "Commande modifiée avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de la commande !");
    }
}


void MainWindow::on_chercher_clicked()
{
    int id = ui->lineEdit_rechercher_id->text().toInt();
    Commande cmd;

    if (cmd.rechercherCommande(id)) {
        ui->lineEdit_id->setText(QString::number(cmd.getIdCommande()));
        ui->lineEdit_date->setText(cmd.getDateCommande());
        ui->lineEdit_statut->setText(cmd.getStatut());
        ui->lineEdit_paiement->setText(cmd.getModePaiement());

        QMessageBox::information(this, "Succès", "Commande trouvée !");
    } else {
        QMessageBox::warning(this, "Erreur", "Commande non trouvée !");
    }
}


void MainWindow::on_pdfButton_clicked()
{
    // Check if the checkbox is checked
    if (!ui->checkboxListe->isChecked()) {
        QMessageBox::warning(this, "Export PDF", "Veuillez cocher la case 'Liste' avant d'exporter.");
        return;
    }

    // Create a PDF file
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF", "", "*.pdf");
    if (filePath.isEmpty())
        return;

    // Add ".pdf" extension if missing
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive))
        filePath += ".pdf";

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300); // High-quality resolution

    QPainter painter(&pdfWriter);
    int yPos = 50; // Starting Y position for drawing text
    const int rowHeight = 70; // Height between rows for larger spacing
    const int col1 = 50;      // X position for column 1 (ID)
    const int col2 = 150;     // X position for column 2 (Statut)
    const int col3 = 350;     // X position for column 3 (Mode de Paiement) - Increased space
    const int col4 = 900;     // X position for column 4 (Date) - Adjusted to prevent overlap

    // Title
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(200, yPos, "Liste des Commandes");
    yPos += 50;

    // Date of export
    painter.setFont(QFont("Arial", 10));
    painter.drawText(400, yPos, "Date : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    yPos += 50;

    // Table headers
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(col1, yPos, "ID");
    painter.drawText(col2, yPos, "Statut");
    painter.drawText(col3, yPos, "Mode de Paiement");
    painter.drawText(col4, yPos, "Date");
    yPos += rowHeight;

    // Fetch data from the database
    QSqlQuery query;
    query.prepare("SELECT ID_COMMANDE, STATUT, MODE_PAIEMENT, DATE_COMMANDE_STR FROM GB_COMMANDE");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données: " + query.lastError().text());
        return;
    }

    // Write data to the PDF with larger gaps
    painter.setFont(QFont("Arial", 10));
    while (query.next()) {
        // Properly align data columns
        painter.drawText(col1, yPos, query.value(0).toString());     // ID_COMMANDE
        painter.drawText(col2, yPos, query.value(1).toString());     // STATUT
        painter.drawText(col3, yPos, query.value(2).toString());     // MODE_PAIEMENT
        painter.drawText(col4, yPos, query.value(3).toString());     // DATE_COMMANDE_STR

        yPos += rowHeight; // Add spacing for the next row
    }

    QMessageBox::information(this, "Export PDF", "PDF exporté avec succès : " + filePath);
}

void MainWindow::on_trierbutton_clicked()
{
    // Create an instance of Commande
    Commande commande;

    // Determine the sort order based on the selected radio button
    QString sortOrder;
    if (ui->radioButtonASC->isChecked()) {
        sortOrder = "ASC"; // Ascending order
    } else if (ui->radioButtonDESC->isChecked()) {
        sortOrder = "DESC"; // Descending order
    } else {
        qDebug() << "Aucun bouton de tri sélectionné.";
        return; // Exit if no sort option is selected
    }

    // Get the sorted model
    QSqlQueryModel* sortedModel = commande.trierCommande(sortOrder);

    // Set the sorted model to the QTableView
    ui->tableView->setModel(sortedModel);

    qDebug() << "Affichage des commandes triées par statut en ordre " << sortOrder;
}


void MainWindow::on_Afficher_clicked()
{
    // Create an instance of the Commande class
    Commande commande;

    // Use the afficherCommande method to retrieve the data
    QSqlQueryModel *model = commande.afficherCommande();

    // Check if the model is valid
    if (model) {
        // Set the model for the QTableView
        ui->tableView->setModel(model);

        // Optional: Display a message in the debug console
        qDebug() << "Affichage des commandes réussi!";
    } else {
        // If the model is null, log an error message
        qDebug() << "Erreur lors de l'affichage des commandes!";
    }

}


void MainWindow::on_Quitter_clicked()
{
    // Confirm before exiting the application
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quitter", "Voulez-vous vraiment quitter?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit(); // Exit the application
    } else {
        // Do nothing, let the user stay in the application
        qDebug() << "Action quitter annulée par l'utilisateur.";
    }
}



int Commande::countByStatut(const QString &statut) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GB_COMMANDE WHERE statut = :statut");
    query.bindValue(":statut", statut);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return 0;  // Retourner 0 en cas d'erreur
    } else {
        if (query.next()) {
            return query.value(0).toInt();
        }
    }
    return 0; // En cas d'absence de résultat
}

void MainWindow::on_afficherStatistiques_clicked()
{
    // Supprimer les anciens widgets (graphique) dans le label
    QList<QWidget*> childWidgets = ui->label_stat->findChildren<QWidget*>();
    for (QWidget* childWidget : childWidgets) {
        childWidget->deleteLater();
    }

    // Masquer le label avant de le réafficher
    ui->label_stat->clear();
    ui->label_stat->hide();

    // Appeler la méthode statique countByStatut de la classe Commande
    int statut1 = Commande::countByStatut("en cours");   // Statut "en cours"
    int statut2 = Commande::countByStatut("vendue");     // Statut "vendue"
    int statut3 = Commande::countByStatut("retour");     // Statut "retour"

    int total = statut1 + statut2 + statut3;

    // Calcul des pourcentages
    float x = (total != 0) ? (statut1 * 100.0f) / total : 0.0f;
    float x1 = (total != 0) ? (statut2 * 100.0f) / total : 0.0f;
    float x2 = (total != 0) ? (statut3 * 100.0f) / total : 0.0f;

    // Ajuster les pourcentages pour s'assurer qu'ils totalisent 100%
    float totalPercentage = x + x1 + x2;
    if (totalPercentage != 100.0f && total != 0) {
        float correction = 100.0f - totalPercentage;
        x += correction;  // Appliquer la correction à l'un des segments (généralement le plus grand)
    }

    // Créer les labels pour les segments du graphique avec leurs pourcentages
    QString ch1 = QString("En cours %1%").arg(QString::number(x, 'f', 2));
    QString ch2 = QString("Vendue %2%").arg(QString::number(x1, 'f', 2));
    QString ch3 = QString("Retour %3%").arg(QString::number(x2, 'f', 2));

    // Créer la série de graphique à secteurs
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);  // Créer un donut plutôt qu'un simple secteur

    // Ajouter les segments avec les données calculées
    QPieSlice *slice = series->append(ch1, x);
    slice->setLabelVisible();
    slice->setLabelColor(QColor(Qt::black));
    slice->setBrush(QColor(255, 119, 178)); // Bleu clair pour "En cours"

    QPieSlice *slice1 = series->append(ch2, x1);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor(Qt::black));
    slice1->setBrush(QColor(204, 0, 102)); // Bleu moyen pour "Vendue"

    QPieSlice *slice2 = series->append(ch3, x2);
    slice2->setLabelVisible();
    slice2->setLabelColor(QColor(Qt::black));
    slice2->setBrush(QColor(153, 0, 76)); // Bleu foncé pour "Retour"

    // Créer un graphique avec la série de secteurs
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Définir la couleur de fond du graphique
    QBrush backgroundBrush(QColor(187, 93, 87, 0));  // Transparent
    chart->setBackgroundBrush(backgroundBrush);

    // Créer un QChartView pour afficher le graphique
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setFixedSize(ui->label_stat->size());  // Fixer la taille du graphique au widget parent
    chartview->setParent(ui->label_stat);  // Définir le parent du graphique

    // Appliquer un style au widget
    ui->label_stat->setStyleSheet("background:transparent; color:white; ");
    ui->label_stat->show();  // Afficher le graphique
}
