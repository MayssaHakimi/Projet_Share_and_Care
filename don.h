#ifndef DON_H
#define DON_H
#include <QtSql>
#include <iostream>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Don
{
private:
    int id_don;
    QString nom_don;
    QString prenom_don;
    QString cin_don;
    QString type_don;
    QString taille;
    int quantite ;
    QString date_v;
int count = 0;
public:
    Don(){

    }
    Don(int,QString , QString ,QString , QString , QString ,QString , int );
    QString getNom_don(){return nom_don ;}
    QString getPrenom_don(){return prenom_don ;}
    QString getCin_don(){return cin_don ;}
    QString getType_don(){return type_don ;}
    QString getTaille(){return taille ;}
    QString getDate_v(){return date_v ;}
    int getQuantite(){return quantite ;}
    int getId_don(){return id_don ;}

    void setNom_don(QString nd){nom_don=nd;}
    void setPrenom_don(QString pd){prenom_don=pd;}
    void setCin_don(QString cd){cin_don=cd;}
    void setType_don(QString td){type_don=td;}
    void setDate_v(QString dd){date_v=dd;}
    void setTaille(QString ta){taille=ta;}
    void setQuantite(int quantite){this->quantite=quantite;}
    void setId_don(int id_don){this->id_don=id_don;}

    bool ajouter_don();
    bool supprimer_don(int);
    QSqlQueryModel * afficher_don();
    bool modifier_don(int );
    QSqlQueryModel * trieAsc();
    QSqlQueryModel * trieDesc();
    QSqlQueryModel * recherche_don(QString  ,QString);
    int calculer_type(QString type_don) ;

    int getVetement(){return  count ;}
    int getNourriture(){return count ;}
    void setVetement(int count){this->count=count;}
    void setNourriture(int count){this->count=count;}
private:
    int vetement( );
    int nourriture( );


};

#endif // DON_H
