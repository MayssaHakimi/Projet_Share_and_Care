#ifndef GESTIONLIVRAISON_H
#define GESTIONLIVRAISON_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Gestionlivraison
{
public:

    QString cin_liv;
    QString nom_liv;
    QString prenom_liv;
    QString Date_liv;
    QString Adresse_liv;
   QString Objet;
    QString telephone;
    Gestionlivraison();
    Gestionlivraison (int ,QString , QString , QString, QString, QString , QString, QString   );
    int getID_LIVRAISON();
    void setID_LIVRAISON (int);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();
private:
     int ID_LIVRAISON;
};

#endif // GESTIONLIVRAISON_H
