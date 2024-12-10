#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QSqlQueryModel>
#include <QModelIndex>

class GB_COMMANDE {
public:
    int countByStatut(const QString &statut);
    // Méthode pour compter les commandes par statut
    // Ajoutez d'autres méthodes nécessaires pour la gestion des commandes
};
// Définition de la classe Commande
class Commande
{
public:
    // Constructeurs
    Commande(); // Constructeur par défaut
    Commande(int id, const QString &date, const QString &statut, const QString &modePaiement); // Constructeur avec paramètres

    // Accesseurs et mutateurs
    int getIdCommande() const;
    void setIdCommande(int id);

    QString getDateCommande() const;
    void setDateCommande(const QString &date);

    QString getStatut() const;
    void setStatut(const QString &statut);

    QString getModePaiement() const;
    void setModePaiement(const QString &modePaiement);

    // Opérations CRUD et autres fonctionnalités
    bool ajouterCommande(); // Ajouter une commande
    bool modifierCommande(); // Modifier une commande existante
    bool supprimer(int id); // Supprimer une commande par son ID
    bool rechercherCommande(int id); // Rechercher une commande par ID
    QSqlQueryModel* trierCommande(const QString& order);
    QSqlQueryModel* afficherCommande(); // Afficher toutes les commandes

private:
    // Attributs de la classe
    int idCommande; // ID unique de la commande
    QString statut; // Statut de la commande
    QString modePaiement; // Mode de paiement
    QString dateCommande; // Date de la commande
};

#endif // COMMANDE_H
