#ifndef GESTIONLIVRAISON_H
#define GESTIONLIVRAISON_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QtGui>
#include <QPainter>

class Gestionlivraison
{
public:
    QString cin_liv;
    QString nom_liv;
    QString prenom_liv;
    QDate Date_liv;
    QString Adresse_liv;
   QString Objet;
    QString telephone;
    Gestionlivraison();
    Gestionlivraison (int ,QString , QString , QString, QDate, QString , QString, QString   );
    int getID_LIVRAISON() const;
    void setID_LIVRAISON (int);
    bool ajouter();
    bool supprimer(int);
    int calculerStatistiques(QDate date_liv);
    bool modifier(int);
    bool existe(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString motCle);
    QSqlQueryModel * trie();
      void PDF();
    //bool comparer_date_livraison( const Gestionlivraison& livraison1, const Gestionlivraison& livraison2);
    //void trie(Gestionlivraison* tab_liv, int taille_tab_liv);

private:
     int ID_LIVRAISON;
};

#endif // GESTIONLIVRAISON_H
