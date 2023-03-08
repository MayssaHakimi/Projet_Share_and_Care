#ifndef GESTIONLIVRAISON_H
#define GESTIONLIVRAISON_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Gestionlivraison
{
public:

    int cin_liv;
    QString nom_liv;
    QString prenom_liv;
    QString Date_liv;
    QString Adresse_liv;
   QString Objet;
    int telephone;
    Gestionlivraison();
    Gestionlivraison (QString , QString , QString, QString, QString , int, int   );
    int getID_livraison();
    void setID_livraison (int);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
private:
     int ID_livraison;
};

#endif // GESTIONLIVRAISON_H
