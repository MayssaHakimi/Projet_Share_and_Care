#include "beneficiaire.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QLoggingCategory>
#include <QDateTime>
#include <QFileDialog>




Beneficiaire::Beneficiaire(int id_ben , QString nom_ben ,QString prenom_ben,QString lieu_ben,int age_ben, int nb_mf,QString type_demande_ben,int cin_ben,int telephone_ben )
{

    this->id_ben=id_ben;
    this->nom_ben=nom_ben;
    this->prenom_ben=prenom_ben;
    this->lieu_ben=lieu_ben;
    this->age_ben=age_ben;
    this->nb_mf=nb_mf;
    this->type_demande_ben=type_demande_ben;
    this->cin_ben=cin_ben;
    this->telephone_ben=telephone_ben;




}
//getters
int Beneficiaire:: getId_ben(){return id_ben;}
QString Beneficiaire::getNom_ben(){return nom_ben;}
QString Beneficiaire::getPrenom_ben(){return prenom_ben;}
QString Beneficiaire::getLieu_ben(){return lieu_ben;}
int Beneficiaire::getAge_ben(){return age_ben;}
int Beneficiaire::getNb_mf(){return nb_mf;}
QString Beneficiaire::getType_demande_ben(){return type_demande_ben;}
QString Beneficiaire::getDate_ajout_ben(){return date_ajout_ben;}
int Beneficiaire::getCin_ben(){return cin_ben;}
int Beneficiaire::getTelephone_ben(){return telephone_ben;}
//setters
void Beneficiaire::SetId_ben(int id_ben){this->id_ben=id_ben;}
void Beneficiaire::SetNom_ben(QString nom_ben){this->nom_ben=nom_ben;}
void Beneficiaire::SetPrenom_ben(QString prenom_ben){this->prenom_ben=prenom_ben;}
void Beneficiaire::SetLieu_ben(QString lieu_ben){this->lieu_ben=lieu_ben;}
void Beneficiaire::SetAge_ben(int age_ben){this->age_ben=age_ben;}
void Beneficiaire::SetNb_mf(int nb_mf){this->nb_mf=nb_mf;}
void Beneficiaire::SetType_demande_ben(QString type_demande_ben){this->type_demande_ben=type_demande_ben;}
void Beneficiaire::SetDate_ajout_ben(QString ate_ajout_ben){this->date_ajout_ben=ate_ajout_ben;}
void Beneficiaire::SetCin_ben(int cin_ben){this->cin_ben=cin_ben;}
void Beneficiaire::SetTelephone_ben(int telephone_ben){this->telephone_ben=telephone_ben;}

bool Beneficiaire::ajouter()
{

    QSqlQuery query;
    QString res= QString::number(id_ben);
    QString res1= QString::number(age_ben);
    QString res2= QString::number(nb_mf);
    QString res3= QString::number(cin_ben);
    QString res4= QString::number(telephone_ben);

    query.prepare(" INSERT INTO beneficiaire (id_ben, nom_ben, prenom_ben,lieu_ben, age_ben, nb_mf, type_demande_ben, cin_ben, telephone_ben) values(:id_ben, :nom_ben, :prenom_ben,:lieu_ben, :age_ben, :nb_mf , :type_demande_ben, :cin_ben, :telephone_ben);");


            query.bindValue(":id_ben",res);
            query.bindValue(":nom_ben",nom_ben);
            query.bindValue(":prenom_ben",prenom_ben);
            query.bindValue(":lieu_ben",lieu_ben);
            query.bindValue(":age_ben",res1);
            query.bindValue(":nb_mf",res2);
            query.bindValue(":type_demande_ben",type_demande_ben);
            query.bindValue(":cin_ben",res3);
            query.bindValue(":telephone_ben",res4);

            return query.exec();

}

QSqlQueryModel * Beneficiaire::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("select * from beneficiaire");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("LIEU"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("AGE"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NB MF"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE DEMANDE"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("DATE AJOUT"));
     model->setHeaderData(8,Qt::Horizontal,QObject::tr("TEL"));

    return model;
}

bool Beneficiaire::supprimer(int id_ben)
{
    QSqlQuery query;
    QString res=QString::number(id_ben);

    query.prepare("Delete from beneficiaire where id_ben= :id_ben");
    query.bindValue(":id_ben",res);
    return query.exec();
}

bool Beneficiaire::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id_ben);
    QString res1 = QString::number(age_ben);
    QString res2 = QString::number(nb_mf);
    QString res3 = QString::number(cin_ben);
    QString res4 = QString::number(telephone_ben);

    query.prepare("UPDATE beneficiaire SET nom_ben=:nom_ben, prenom_ben=:prenom_ben, lieu_ben=:lieu_ben, age_ben=:age_ben, nb_mf=:nb_mf, type_demande_ben=:type_demande_ben, cin_ben=:cin_ben, telephone_ben=:telephone_ben WHERE id_ben=:id_ben");
    query.bindValue(":nom_ben", nom_ben);
    query.bindValue(":prenom_ben", prenom_ben);
    query.bindValue(":lieu_ben", lieu_ben);
    query.bindValue(":age_ben", res1);
    query.bindValue(":nb_mf", res2);
    query.bindValue(":type_demande_ben", type_demande_ben);
    query.bindValue(":cin_ben", res3);
    query.bindValue(":telephone_ben", res4);
    query.bindValue(":id_ben", res);

    return query.exec();
}

QSqlQueryModel* Beneficiaire::tri()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM beneficiaire ORDER BY nom_ben ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NB MF"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE DEMANDE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE AJOUT"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TEL"));

    return model;
}



