#ifndef GESTIONLIVRAISON_H
#define GESTIONLIVRAISON_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QtGui>
#include <QPainter>
#include <QDate>
#include <QList>
#include <QSqlQuery>
#include <QVector>
class Gestionlivraison
{
public:
    QString cin_liv;
    QString nom_liv;
    QString prenom_liv;
    QDate Date_liv;
    QString Adresse_liv;
   int Objet;
    QString telephone;
   float Latitude;
    float Longitude;
    Gestionlivraison();
    Gestionlivraison (int ,QString , QString , QString, QDate, QString , int, QString ,float , float  );
    int getID_LIVRAISON() const;
    void setID_LIVRAISON (int);
    bool ajouter();
    bool supprimer(int);
    QMap<QString, int> statistiquesParDate(QDate date);
    bool modifier(int);
    bool existe(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString motCle);
    QSqlQueryModel * trie();
      void PDF();
    QList<QDate> getLivraisonsCalendrier();
QVector<QVector<QString>> getStatsLivraisonByDate();
    void afficherStatistiques();


private:
     int ID_LIVRAISON;

};

#endif // GESTIONLIVRAISON_H
