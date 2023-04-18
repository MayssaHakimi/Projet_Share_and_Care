#include "adherent.h"

Adherent::Adherent(int id_adh,QString nom_adh ,QString prenom_adh,QString cin_adh,QString identifiant ,QString mdp_adh,QString date_emb ,QString fct_adh)
{
this->id_adh=id_adh;
    this->nom_adh=nom_adh ;
    this->prenom_adh=prenom_adh ;
    this->cin_adh=cin_adh ;
    this->identifiant=identifiant ;
    this->mdp_adh=mdp_adh ;
    this->date_emb=date_emb ;
    this->fct_adh=fct_adh ;

}
bool Adherent::ajouter_adh()
{

    QSqlQuery query;
    QString res =QString::number(id_adh);

    query.prepare("insert into Adherent (id_adh, nom_adh , prenom_adh, cin_adh, identifiant, mdp_adh, date_emb , fct_adh)" "values(:id_adh, :nom_adh, :prenom_adh, :cin_adh, :identifiant, :mdp_adh, :date_emb, :fct_adh)");


query.bindValue(":id_adh",res);
  query.bindValue(":nom_adh",nom_adh);
   query.bindValue(":prenom_adh",prenom_adh);
  query.bindValue(":cin_adh",cin_adh);
  query.bindValue(":identifiant",identifiant);
  query.bindValue(":mdp_adh",mdp_adh);
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
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cin"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Fonction"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("Mdp"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("D.Embauche"));

return model;
}


bool Adherent::modifier_adh(int id_adh)
{

QSqlQuery query;

QString res =QString::number(id_adh);


query.prepare("UPDATE Adherent SET nom_adh=:nom_adh,prenom_adh=:prenom_adh,cin_adh=:cin_adh,identifiant=:identifiant,mdp_adh=:mdp_adh, date_emb=:date_emb,fct_adh=:fct_adh WHERE id_adh=:id_adh;");

query.bindValue(":id_adh",res);
query.bindValue(":nom_adh",nom_adh);
query.bindValue(":prenom_adh",prenom_adh);
  query.bindValue(":cin_adh",cin_adh);
  query.bindValue(":identifiant",identifiant);
  query.bindValue(":mdp_adh",mdp_adh);

  query.bindValue(":date_emb",date_emb);
  query.bindValue(":fct_adh",fct_adh);

return query.exec();

}
QSqlQueryModel * Adherent::tri_adh_asc()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("Select * from Adherent order by (to_date ( date_emb , 'dd/mm/yy')) asc;");
   afficher_adh();
    return model;

}
QSqlQueryModel * Adherent::tri_adh_desc()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("Select * from Adherent order by (to_date ( date_emb , 'dd/mm/yy')) desc;");
    afficher_adh();
    return model;

}
QSqlQueryModel * Adherent::recherche_adh(QString fct_adh)
{
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();
   query.prepare(" Select * from Adherent where fct_adh=:fct_adh; ");
    query.bindValue(":fct_adh",fct_adh);
    if (query.exec()) {
            model->setQuery(query);
            afficher_adh();
        }
        return model;

}
int Adherent::RH()
 {

     QSqlQuery query;
             query.prepare("SELECT count(*)  FROM adherent WHERE fct_adh = 'RH'");
             query.exec();
             query.next();
             int count = query.value(0).toInt();
             return count;
 }
int Adherent::RRB()
 {


     QSqlQuery query;
             query.prepare("SELECT count(*)  FROM adherent WHERE fct_adh = 'Responsable Relations Beneficiaires'");
             query.exec();
             query.next();
             int count = query.value(0).toInt();
             return count;


 }
int Adherent::DCF()
 {

     QSqlQuery query;
                  query.prepare("SELECT count(*)  FROM adherent WHERE fct_adh = 'Directeur collet de Fonds'");
                  query.exec();
                  query.next();
                  int count = query.value(0).toInt();
                  return count;


 }
int Adherent::RL()
 {

     QSqlQuery query;
                  query.prepare("SELECT count(*)  FROM adherent WHERE fct_adh = 'Responsable Livraison'");
                  query.exec();
                  query.next();
                  int count = query.value(0).toInt();
                  return count;

 }
int Adherent::RE()
 {

     QSqlQuery query;
                  query.prepare("SELECT count(*)  FROM adherent WHERE fct_adh = 'Responsable Evenement'");
                  query.exec();
                  query.next();
                  int count = query.value(0).toInt();
                  return count;


 }
 QString Adherent::authen_nom(QString mdp_adh)
{
QSqlQuery query;
query.prepare("SELECT identifiant FROM adherent WHERE mdp_adh= :mdp_adh");
query.bindValue(":mdp_adh",mdp_adh);
query.exec();
query.next();
    QString m_username = query.value(0).toString();

return m_username;
}
QString  Adherent::authen_mdp(QString mdp_adh)
{
    QSqlQuery query;
    query.prepare("SELECT mdp_adh FROM adherent WHERE mdp_adh= :mdp_adh");
    query.bindValue(":mdp_adh",mdp_adh);
    query.exec();
    query.next();
        QString m_password = query.value(0).toString();

    return m_password ;


}















