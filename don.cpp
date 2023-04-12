#include "don.h"

Don::Don(int id_don,QString nom_don , QString prenom_don,QString cin_don  , QString type_don , QString taille , QString date_v , int quantite)
{
this->id_don=id_don;
this->nom_don=nom_don;
this->prenom_don=prenom_don;
this->cin_don=cin_don;
this->type_don=type_don;
this->taille=taille;
this->date_v=date_v;
this->quantite=quantite;

}

bool Don::ajouter_don()
{
       QSqlQuery query;
       QString res =QString::number(id_don);
       QString res1 =QString::number(quantite);
       query.prepare("insert into DONS (id_don, nom_don , prenom_don, cin_don, taille, date_v, quantite , type_don )" "values(:id_don, :nom_don , :prenom_don, :cin_don, :taille, :date_v, :quantite , :type_don)");


     query.bindValue(":id_don",res);
     query.bindValue(":quantite",res1);
     query.bindValue(":nom_don",nom_don);
     query.bindValue(":prenom_don",prenom_don);
     query.bindValue(":cin_don",cin_don);
     query.bindValue(":taille",taille);
     query.bindValue(":date_v",date_v);
     query.bindValue(":type_don",type_don);


     return query.exec();

}

 bool Don::supprimer_don(int id_don)
 {
     QSqlQuery query;
     QString res = QString::number(id_don);
     query.prepare("Delete from  DONS where id_don= :id_don" );
     query.bindValue(":id_don",res);
     return query.exec();
 }

 QSqlQueryModel * Don::afficher_don()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select id_don , nom_don , prenom_don, cin_don , type_don ,taille , date_v , quantite from DONS");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_du_don"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom du donateur"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom du donateur"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cin du donateur"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Type de don"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("Taille"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("Date de validitée"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("Quantité"));

     return model;
 }

 bool Don::modifier_don(int id_don)
 {

 QSqlQuery query;

 QString res=QString::number(id_don);
 QString res1 = QString::number(quantite);

 query.prepare("UPDATE DONS SET nom_don=:nom_don,prenom_don=:prenom_don,cin_don=:cin_don,type_don=:type_don,date_v=:date_v,taille=:taille,quantite=:quantite WHERE id_don=:id_don;");

 query.bindValue(":id_don",res);
 query.bindValue(":quantite",res1);
 query.bindValue(":nom_don",nom_don);
 query.bindValue(":prenom_don",prenom_don);
 query.bindValue(":cin_don",cin_don);
 query.bindValue(":type_don",type_don);
 query.bindValue(":date_v",taille);
 query.bindValue(":taille",date_v);

 return query.exec();

 }

QSqlQueryModel * Don::trieAsc()
 {
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select id_don , nom_don , prenom_don, cin_don , type_don ,taille , date_v , quantite from DONS order by nom_don ASC");
    afficher_don();

    return model;
 }

QSqlQueryModel * Don::trieDesc()
 {
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select id_don , nom_don , prenom_don, cin_don , type_don ,taille , date_v , quantite from DONS order by nom_don DESC");
   afficher_don();
    return model;
 }

QSqlQueryModel * Don::recherche_don( QString type_don ,QString nom_don )
 {
     QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();

    query.prepare("select id_don , nom_don , prenom_don, cin_don , type_don ,taille , date_v , quantite from DONS where type_don = :type_don or nom_don = :nom_don ;");
    query.bindValue(":type_don",type_don );
    query.bindValue(":nom_don",nom_don );

    if(query.exec())
    {
        model->setQuery(query);
   afficher_don();
}

    return model;
 }



int Don::vetement()
 {

   QSqlQuery query;
       query.prepare("SELECT count(*)  FROM dons WHERE type_don = 'Vetement'");
       query.exec();
       query.next();
       int count = query.value(0).toInt();
       return count;
 }

int Don::nourriture()
 {
    QSqlQuery query;
        query.prepare("SELECT count(*)  FROM dons WHERE type_don = 'Nourriture'");
        query.exec();
        query.next();
        int count = query.value(0).toInt();
        return count;
 }

int Don::calculer_type(QString type_don)
{
      QSqlQuery query;

      query.prepare("select * from dons where (type_don = :type_don)");
      query.bindValue(":type_don", type_don);

   query.exec();
      int total = 0;
      while (query.next()) {
        total++;
      }
return total;}



