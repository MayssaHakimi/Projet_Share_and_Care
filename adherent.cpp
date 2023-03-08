#include "adherent.h"

Adherent::Adherent(QString nom_adh ,QString prenom_adh,QString cin_adh,QString identifiant ,QString mdp_adh,QString img ,QString date_emb ,QString fct_adh)
{

    this->nom_adh=nom_adh ;
    this->prenom_adh=prenom_adh ;
    this->cin_adh=cin_adh ;
    this->identifiant=identifiant ;
    this->mdp_adh=mdp_adh ;
    this->img=img ;
    this->date_emb=date_emb ;
    this->fct_adh=fct_adh ;

}
bool Adherent::ajouter_adh()
{

    QSqlQuery query;
    QString res =QString::number(id_adh);
    query.prepare("insert into Adherent (id_adh, nom_adh , prenom_adh, cin_adh, identifiant, mdp_adh, img , date_emb , fct_adh)" "values(:id_adh, :nom_adh, :prenom_adh, :cin_adh, :identifiant, :mdp_adh, :img , :date_emb, :fct_adh)");


query.bindValue(":id_adh",res);
  query.bindValue(":nom_adh",nom_adh);
   query.bindValue(":prenom_adh",prenom_adh);
  query.bindValue(":cin_adh",cin_adh);
  query.bindValue(":identifiant",identifiant);
  query.bindValue(":mdp_adh",mdp_adh);
  query.bindValue(":img",img);
  query.bindValue(":date_emb",date_emb);
  query.bindValue(":fct_adh",fct_adh);
  return query.exec();

}
bool Adherent::supprimer_adh(int id_adh)
{
    QSqlQuery query;
    QString res =QString::number(id_adh);
     query.prepare("Delete from Adherent where id_adh= :id_adh");

     query.bindValue(":id_adh",res);

     return query.exec();

}
QSqlQueryModel * Adherent::afficher_adh()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("Select * from Adherent");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_Adhérent"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Adhérent"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_Adhérent"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cin_Adhérent"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("Mdp_Adhérent"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("Img_Adhérent"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Date_D'embauche"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("Fonction_Adhérent"));
return model;
}


bool Adherent::modifier_adh(int id_adh)
{

QSqlQuery query;

QString res =QString::number(id_adh);

query.prepare("UPDATE Adherent SET nom_adh=:nom_adh,prenom_adh=:prenom_adh,cin_adh=:cin_adh,identifiant=:identifiant,mdp_adh=:mdp_adh,img=:img,date_emb=:date_emb,fct_adh=:fct_adh WHERE id_adh=:id_adh;");

query.bindValue(":id_adh",res);
query.bindValue(":nom_adh",nom_adh);
query.bindValue(":prenom_adh",prenom_adh);
  query.bindValue(":cin_adh",cin_adh);
  query.bindValue(":identifiant",identifiant);
  query.bindValue(":mdp_adh",mdp_adh);
  query.bindValue(":img",img);
  query.bindValue(":date_emb",date_emb);
  query.bindValue(":fct_adh",fct_adh);

return query.exec();

}
QSqlQueryModel * Adherent::tri_adh_asc()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("Select * from Adherent order by (to_date ( date_emb , 'dd/mm/yy')) asc;");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_Adhérent"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Adhérent"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_Adhérent"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cin_Adhérent"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Mdp_Adhérent"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Img_Adhérent"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Date_D'embauche"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Fonction_Adhérent"));
    return model;

}
QSqlQueryModel * Adherent::tri_adh_desc()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("Select * from Adherent order by (to_date ( date_emb , 'dd/mm/yy')) desc;");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_Adhérent"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Adhérent"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_Adhérent"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cin_Adhérent"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Mdp_Adhérent"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Img_Adhérent"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Date_D'embauche"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Fonction_Adhérent"));
    return model;

}
QSqlQueryModel * Adherent::recherche_adh(QString fct_adh)
{
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();
    query.bindValue(":fct_adh",fct_adh);
    model->setQuery("Select * from Adherent where fct_adh=:fct_adh;");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_Adhérent"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Adhérent"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_Adhérent"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cin_Adhérent"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Mdp_Adhérent"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Img_Adhérent"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Date_D'embauche"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Fonction_Adhérent"));
    return model;

}
