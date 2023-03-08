#include "gestionlivraison.h"
#include <QSqlQuery>
#include <QtDebug>

Gestionlivraison::Gestionlivraison()
{
  /*   ID_livraison=0;
     cin_liv=0;
     nom_liv="";
     prenom_liv="";
    date_liv=QDate::currentDate();
     Date_liv ="";
     Adresse_liv="";
     Objet="";
     telephone =0;*/
}
Gestionlivraison::Gestionlivraison (QString nom_liv, QString prenom_liv, QString Date_liv, QString Adresse_liv, QString Objet, int telephone , int cin_liv)
{

 this ->nom_liv=nom_liv;
 this->prenom_liv=prenom_liv;
 this->Date_liv=Date_liv;
 this->Adresse_liv=Adresse_liv;
 this->Objet=Objet;
 this->telephone=telephone;
 this ->cin_liv=cin_liv;
 }
 int Gestionlivraison::getID_livraison()
 {
     return ID_livraison;
 }
 void Gestionlivraison::setID_livraison(int ID_livraison)
 {

  this->ID_livraison =ID_livraison;
 }
bool Gestionlivraison::ajouter()
{

QSqlQuery query;
/*QString ID_livraison_string=QString::number(ID_livraison);*/

QString res=QString::number(cin_liv);
QString telephone_string=QString::number(telephone);

      query.prepare("INSERT INTO livraison (ID_livraison , cin_liv, nom_liv , prenom_liv , Date_liv , Adresse_liv , Objet  , telephone  ) "
                    "VALUES (:ID_livraison, :cin_liv, :nom_liv, :prenom_liv, :Date_liv , :Adresse_liv, :Objet, :telephone)");
      /*query.bindValue(":id", 1001);*/
      query.bindValue("ID_livraison_string", 1);
      query.bindValue("cin_liv_string", res);
      query.bindValue("nom_liv", nom_liv);
      query.bindValue("prenom_liv", prenom_liv);
       query.bindValue("Date_liv", Date_liv);
       query.bindValue("Adresse_liv", Adresse_liv);
      query.bindValue("Objet", Objet);
     query.bindValue("telephone_string", telephone_string);



     return  query.exec();

}
bool Gestionlivraison::supprimer(int cin_liv)
{
QSqlQuery query;
QString res=QString::number(cin_liv);

query.prepare("delete from table livraison where cin =:" );
query.bindValue(":cin_liv ", res);

return  query.exec();



}








