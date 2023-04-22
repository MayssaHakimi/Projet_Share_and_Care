#ifndef BENEFICIAIRE_H
#define BENEFICIAIRE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QLoggingCategory>

class Beneficiaire
{
private:
    QString nom_ben, prenom_ben, lieu_ben, type_demande_ben, date_ajout_ben;
    int id_ben, age_ben, nb_mf, cin_ben, telephone_ben;
public:
    //constructeurs
    Beneficiaire(){}
    Beneficiaire(int  , QString ,QString ,QString ,int , int ,QString ,int ,int);
    //Getters
    int getId_ben();
    QString getNom_ben();
    QString getPrenom_ben();
    QString getLieu_ben();
    int getAge_ben();
    int getNb_mf();
    QString getType_demande_ben();
    QString getDate_ajout_ben();
    int getCin_ben();
    int getTelephone_ben();

    //setters
    void SetId_ben(int);
    void SetNom_ben(QString);
    void SetPrenom_ben(QString);
    void SetLieu_ben(QString);
    void SetAge_ben(int);
    void SetNb_mf(int);
    void SetType_demande_ben(QString);
    void SetDate_ajout_ben(QString);
    void SetCin_ben(int);
    void SetTelephone_ben(int);

    //fonctionnalites de base relatives a lentite Beneficiare
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * trouver(int id);
    QSqlQueryModel * tri();
    QSqlQueryModel * tri2();
    void exportToPdf();


};

#endif // BENEFICIAIRE_H
