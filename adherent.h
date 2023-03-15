#ifndef ADHERENT_H
#define ADHERENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>


class Adherent
{
    private :

    int id_adh ;
    QString nom_adh ;
    QString prenom_adh ;
  QString cin_adh ;
    QString identifiant ;
    QString mdp_adh;

    QString date_emb;
    QString fct_adh ;

public:
    Adherent() {};
    Adherent(int,QString,QString,QString,QString,QString,QString,QString);
int getId_adh(){return id_adh ;}
    QString getNom_adh(){return nom_adh;}
    QString getPrenom_adh(){return prenom_adh;}
    QString getCin_adh(){return cin_adh;}
    QString getIdentifiant(){return identifiant;}
    QString getMdp_adh(){return mdp_adh;}
    QString getFct_adh(){return fct_adh;}

    QString getDate_emb(){return date_emb;}
    void setId_adh(int id) {id_adh = id ;}

    void setNom_adh(QString n) {nom_adh = n ;}
    void setPrenom_adh(QString p) {prenom_adh = p ;}

    void setCin_adh(QString c) {cin_adh = c ;}

    void setIdentifiant(QString ide) {identifiant = ide ;}

    void setMdp_adh(QString m) {mdp_adh = m ;}

    void setFct_adh(QString f) {fct_adh = f ;}



    void setDate_emb(QString d) {date_emb= d ;}

bool ajouter_adh();
QSqlQueryModel * afficher_adh();
bool supprimer_adh(int);
bool modifier_adh(int);
QSqlQueryModel * tri_adh_asc();
QSqlQueryModel * tri_adh_desc();
QSqlQueryModel * recherche_adh(QString);
int RH();
int RRB();
int DCF();
int RL();
int RE();
};

#endif // ADHERENT_H
