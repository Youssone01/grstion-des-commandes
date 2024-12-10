#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>


#include <QMainWindow>
#include "commande.h" // Inclusion de la classe Commande pour l'intégration avec l'interface

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT




public:
    explicit MainWindow(QWidget *parent = nullptr); // Constructeur
    ~MainWindow(); // Destructeur

private slots:
    // Slots pour gérer les interactions avec l'interface utilisateur
    void on_Ajouter_clicked();        // Ajouter une commande
    void on_supprimerbutton_clicked(); // Supprimer une commande
    void on_modifierbutton_clicked();  // Modifier une commande
    void on_chercher_clicked();       // Rechercher une commande
    void on_trierbutton_clicked();    // Trier les commandes
    void on_pdfButton_clicked();      // Exporter les commandes en PDF

    void on_Afficher_clicked();

    void on_Quitter_clicked();

    void on_afficherStatistiques_clicked();


private:
    Ui::MainWindow *ui;
    // Déclaration du QChartView
    // Interface utilisateur générée par Qt Designer

};

#endif // MAINWINDOW_H
