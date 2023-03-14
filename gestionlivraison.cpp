#include "gestionlivraison.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Gestionlivraison::Gestionlivraison()
{
  /*   ID_LIVRAISON=0;
     cin_liv=0;
     nom_liv="";
     prenom_liv="";
    date_liv=QDate::currentDate();
     Date_liv ="";
     Adresse_liv="";
     Objet="";
     telephone =0;*/
}
Gestionlivraison::Gestionlivraison (int ID_LIVRAISON ,QString cin_liv , QString nom_liv, QString prenom_liv, QString Date_liv, QString Adresse_liv, QString Objet, QString telephone )
{
   this->ID_LIVRAISON=ID_LIVRAISON;
this ->cin_liv=cin_liv;
 this ->nom_liv=nom_liv;
 this->prenom_liv=prenom_liv;
 this->Date_liv=Date_liv;
 this->Adresse_liv=Adresse_liv;
 this->Objet=Objet;
 this->telephone=telephone;

 }
 int Gestionlivraison::getID_LIVRAISON()
 {
     return ID_LIVRAISON;
 }
 void Gestionlivraison::setID_LIVRAISON(int ID_LIVRAISON)
 {

  this->ID_LIVRAISON =ID_LIVRAISON;
 }
bool Gestionlivraison::ajouter()
{

QSqlQuery query;

//QString res=QString::number(cin_liv);
QString ID_LIVRAISON_string=QString::number(ID_LIVRAISON);
query.prepare("insert into LOLITA.LIVRAISON (ID_LIVRAISON,CIN_LIV,NOM_LIV,PRENOM_LIV ,DATE_LIV,ADRESSE_LIV,TELEPHONE,OBJET)""values (:ID_LIVRAISON, :CIN_LIV, :NOM_LIV, :PRENOM_LIV , :DATE_LIV, :ADRESSE_LIV, :TELEPHONE, :OBJET)" );

 query.bindValue(0, ID_LIVRAISON_string);
   query.bindValue(1, cin_liv);
   query.bindValue(2, nom_liv);
   query.bindValue(3, prenom_liv);
   query.bindValue(4, Date_liv);
   query.bindValue(5, Adresse_liv);
   query.bindValue(6, telephone);
   query.bindValue(7, Objet);

   return query.exec();

}
bool Gestionlivraison::supprimer(int ID_LIVRAISON)
{
QSqlQuery query;
//QString res=QString::number(ID_LIVRAISON);

query.prepare("delete from LOLITA.LIVRAISON where ID_LIVRAISON =:ID_LIVRAISON" );
//query.bindValue(":ID_LIVRAISON ", res);
query.bindValue(0, ID_LIVRAISON);

return  query.exec();


}



QSqlQueryModel* Gestionlivraison::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

model->setQuery("SELECT*  FROM LOLITA.LIVRAISON ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifient "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Objet"));

return  model;

}

bool Gestionlivraison::modifier(int ID_LIVRAISON)
{

    QString ID_LIVRAISON_string=QString::number(ID_LIVRAISON);

        QSqlQuery  query;
    query.prepare("UPDATE LOLITA.LIVRAISON SET ID_LIVRAISON=:ID_LIVRAISON , CIN_LIV =:CIN_LIV , NOM_LIV =:NOM_LIV , PRENOM_LIV =:PRENOM_LIV  ,ADRESSE_LIV = :ADRESSE_LIV,TELEPHONE =:TELEPHONE ,OBJET =:OBJET where ID_LIVRAISON =:ID_LIVRAISON" );

  query.bindValue(":ID_LIVRAISON", ID_LIVRAISON_string);
      query.bindValue(":CIN_LIV", cin_liv);
      query.bindValue("NOM_LIV", nom_liv);
       query.bindValue(":TELEPHONE", telephone);
       query.bindValue(":ADRESSE_LIV", Adresse_liv);
      query.bindValue(":PRENOM_LIV", prenom_liv);
    //  query.bindValue(":DATE_LIV ", Date_liv);
      query.bindValue(":OBJET", Objet);

    return query.exec();


}




