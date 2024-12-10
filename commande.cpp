#include "commande.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>

// Constructeur par défaut
Commande::Commande()
{
    this->idCommande = 0;
    this->dateCommande = "";
    this->statut = "";
    this->modePaiement = "";
}

// Constructeur avec paramètres
Commande::Commande(int id, const QString &date, const QString &statut, const QString &modePaiement)
{
    this->idCommande = id;
    this->dateCommande = date;
    this->statut = statut;
    this->modePaiement = modePaiement;
}

// Getters
int Commande::getIdCommande() const {
    return this->idCommande;
}

QString Commande::getDateCommande() const {
    return this->dateCommande;
}

QString Commande::getStatut() const {
    return this->statut;
}

QString Commande::getModePaiement() const {
    return this->modePaiement;
}

// Setters
void Commande::setIdCommande(int id) {
    this->idCommande = id;
}

void Commande::setDateCommande(const QString &date) {
    this->dateCommande = date;
}

void Commande::setStatut(const QString &statut) {
    this->statut = statut;
}

void Commande::setModePaiement(const QString &modePaiement) {
    this->modePaiement = modePaiement;
}

// Ajouter une commande dans la base de données
bool Commande::ajouterCommande() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur : La base de données n'est pas ouverte.";
        return false;
    }

    if (!db.transaction()) {
        qDebug() << "Erreur : Impossible de démarrer une transaction : " << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO GB_COMMANDE (ID_COMMANDE, STATUT, MODE_PAIEMENT, DATE_COMMANDE_STR) "
                  "VALUES (:ID_COMMANDE, :STATUT, :MODE_PAIEMENT, :DATE_COMMANDE_STR)");
    query.bindValue(":ID_COMMANDE", idCommande);
    query.bindValue(":STATUT", statut);
    query.bindValue(":MODE_PAIEMENT", modePaiement);
    query.bindValue(":DATE_COMMANDE_STR", dateCommande);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout de la commande : " << query.lastError().text();
        db.rollback();
        return false;
    }

    if (!db.commit()) {
        qDebug() << "Erreur : Impossible de valider la transaction : " << db.lastError().text();
        db.rollback();
        return false;
    }

    qDebug() << "Commande ajoutée avec succès dans la base de données.";
    return true;
}

// Modifier une commande
bool Commande::modifierCommande() {
    QSqlQuery query;
    query.prepare("UPDATE GB_COMMANDE SET STATUT = :statut, MODE_PAIEMENT = :modePaiement, DATE_COMMANDE_STR = :date "
                  "WHERE ID_COMMANDE = :id");

    query.bindValue(":id", idCommande);
    query.bindValue(":statut", statut);
    query.bindValue(":modePaiement", modePaiement);
    query.bindValue(":date", dateCommande);

    if (query.exec()) {
        qDebug() << "Commande modifiée avec succès!";
        return true;
    } else {
        qDebug() << "Erreur lors de la modification de la commande: " << query.lastError();
        return false;
    }
}


bool Commande::supprimer(int id)
{
    QSqlQuery query;

    // Prepare the DELETE query
    query.prepare("DELETE FROM GB_COMMANDE WHERE ID_COMMANDE = :ID_COMMANDE");

    // Bind the ID parameter
    query.bindValue(":ID_COMMANDE", id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de la commande : " << query.lastError().text();
        return false;
    }

    return true;
}



// Rechercher une commande par ID
bool Commande::rechercherCommande(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM GB_COMMANDE WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        idCommande = query.value("ID_COMMANDE").toInt();
        dateCommande = query.value("DATE_COMMANDE_STR").toString();  // Updated column name
        statut = query.value("STATUT").toString();
        modePaiement = query.value("MODE_PAIEMENT").toString();

        qDebug() << "Commande trouvée!";
        return true;
    } else {
        qDebug() << "Commande non trouvée ou erreur de la recherche: " << query.lastError();
        return false;
    }
}

QSqlQueryModel* Commande::trierCommande(const QString& order) {

    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Construct the query dynamically based on the provided order
    QString queryString = "SELECT * FROM GB_COMMANDE ORDER BY STATUT " + order;
    query.prepare(queryString);

    // Execute the query
    if (query.exec()) {
        model->setQuery(query);
        qDebug() << "Requête exécutée avec succès.";
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
    }

    return model;
}

QSqlQueryModel* Commande::afficherCommande()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Define the query to fetch all data from the GB_COMMANDE table
    model->setQuery("SELECT * FROM GB_COMMANDE");

    // Set custom headers for the columns
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE_PAIEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_COMMANDE_STR"));

    return model;
}
int Commande::countByStatut(const QString &statut)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GB_COMMANDE WHERE statut = :statut");
    query.bindValue(":statut", statut);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return 0;  // Retourner 0 en cas d'erreur
    }

    if (query.next()) {
        return query.value(0).toInt();
    }

    return 0;  // Retourner 0 si aucun résultat trouvé
}
