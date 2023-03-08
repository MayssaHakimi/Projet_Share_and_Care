#include "event.h"
Event::Event()
{

}
Event::Event(int id,QString nom_eve,QString nom_eq,QString nom_org,int np,QDate date_eve,QString tache)
{
this->id=id;
this->np=np;
this->tache=tache;
this->nom_eq=nom_eq;
this->nom_eve=nom_eve;
this->nom_org=nom_org;
this->date_eve=date_eve;
}
bool Event::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString np_string=QString::number(np);

    query.prepare("INSERT INTO EVENEMENT (id, nom_eve,nom_eq,nom_org,np,date_eve,tache) "
                  "VALUES (:id, :nom_eve, :nom_eq ,:nom_org,:np,:date_eve,:tache)");

    query.bindValue(":id",id_string);
    query.bindValue(":nom_eve", nom_eve);
    query.bindValue(":nom_eq", nom_eq);
    query.bindValue(":nom_org", nom_org);
    query.bindValue(":np", np_string);
    query.bindValue(":date_eve", date_eve);
    query.bindValue(":tache", tache);

    return  query.exec();
}
QSqlQueryModel * Event::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EVENEMENTS");
    return model;
}
bool Event:: supprimer(int id)
{
    QSqlQuery query;
    query.prepare("delete from EVENEMENTS where ID_EVE=:id");
    query.bindValue(":id",id);
    return  query.exec();
}
bool Event::existance(QString id)
{
    QMessageBox msgBox;
    QSqlQuery query;
    int count=0;
    query.prepare("SELECT * FROM EVENEMENTS WHERE ID_EVE= ?");
    query.addBindValue(id);
    if(query.exec() )
    {
        while (query.next())
        {
            count ++;
        }
        if(count==1)
        {
            msgBox.setText("id deja existe");
            msgBox.exec();
            return 0;
        }

    }
    return 1;
}
