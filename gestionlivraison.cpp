#include "gestionlivraison.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QtSql>
#include "mainwindow.h"

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
Gestionlivraison::Gestionlivraison (int ID_LIVRAISON ,QString cin_liv , QString nom_liv, QString prenom_liv, QDate Date_liv, QString Adresse_liv, int Objet, QString telephone , float Latitude , float Longitude )
{
 this->ID_LIVRAISON=ID_LIVRAISON;
this ->cin_liv=cin_liv;
 this ->nom_liv=nom_liv;
 this->prenom_liv=prenom_liv;
 this->Date_liv=Date_liv;
 this->Adresse_liv=Adresse_liv;
 this->Objet=Objet;
 this->telephone=telephone;
 this->Latitude=Latitude;
 this->Longitude=Longitude;
 }
 int Gestionlivraison::getID_LIVRAISON() const
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
  QString ID_LIVRAISON_string = QString::number(ID_LIVRAISON);
  QString ID_OBJET_string = QString::number(Objet);

  QString Latitude_string = QString::number(Latitude);
  QString Longitude_string = QString::number(Longitude);
  QDate Date_liv = QDate::currentDate();
  QString dateString = Date_liv.toString("dd/MM/yyyy");
  qDebug() << "Date string:" << dateString;
  query.prepare("INSERT INTO MAYSSA.LIVRAISON (ID_LIVRAISON, CIN_LIV, NOM_LIV, PRENOM_LIV, DATE_LIV, ADRESSE_LIV, TELEPHONE, OBJET, LATITUDE, LONGITUDE) "
                "VALUES (:ID_LIVRAISON, :CIN_LIV, :NOM_LIV, :PRENOM_LIV, TO_DATE(:DATE_LIV, 'dd/MM/yyyy'), :ADRESSE_LIV, :TELEPHONE, :OBJET, :LATITUDE, :LONGITUDE)");
  query.bindValue(":ID_LIVRAISON", ID_LIVRAISON_string);
  query.bindValue(":CIN_LIV", cin_liv);
  query.bindValue(":NOM_LIV", nom_liv);
  query.bindValue(":PRENOM_LIV", prenom_liv);
  query.bindValue(":DATE_LIV", dateString);
  query.bindValue(":ADRESSE_LIV", Adresse_liv);
  query.bindValue(":TELEPHONE", telephone);
  query.bindValue(":OBJET", ID_OBJET_string);
  query.bindValue(":LATITUDE", Latitude_string);
  query.bindValue(":LONGITUDE", Longitude_string);
  return query.exec();
 }
bool Gestionlivraison::supprimer(int ID_LIVRAISON)
{
QSqlQuery query;
//QString res=QString::number(ID_LIVRAISON);

query.prepare("delete from MAYSSA.LIVRAISON where ID_LIVRAISON =:ID_LIVRAISON" );
//query.bindValue(":ID_LIVRAISON ", res);
query.bindValue(0, ID_LIVRAISON);

return  query.exec();


}

QSqlQueryModel* Gestionlivraison::afficher ()
{
    QString motCle;
    QSqlQueryModel* model = new QSqlQueryModel();

    QString query = "SELECT * FROM MAYSSA.LIVRAISON";
    if (!motCle.isEmpty()) {
        query += QString(" WHERE Nom LIKE '%%1%' OR Prenom LIKE '%%1%' OR Adresse LIKE '%%1%'").arg(motCle);
    }
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifient"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Objet"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Latitude"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Longitude"));

    return model;
}
/*QSqlQueryModel* Gestionlivraison::afficher()
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

return  model;*/
/* QSqlQueryModel* model=new QSqlQueryModel();

    if(nom_liv.isEmpty()){
        model->setQuery("SELECT * FROM LOLITA.LIVRAISON");
    } else {
        QSqlQuery query;
        query.prepare("SELECT * FROM LOLITA.LIVRAISON WHERE Nom = :nom");
        query.bindValue(":nom", nom_liv);
        query.exec();
        model->setQuery(query);
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Objet"));

    return  model;
}*/

bool Gestionlivraison::modifier(int ID_LIVRAISON)
{
    QString ID_OBJET_string = QString::number(Objet);
    QString ID_LIVRAISON_string=QString::number(ID_LIVRAISON);
    QDate Date_liv = QDate::currentDate();
QString dateString = Date_liv.toString("dd-MMM-yyyy");
        QSqlQuery  query;
    query.prepare("UPDATE MAYSSA.LIVRAISON SET ID_LIVRAISON=:ID_LIVRAISON , CIN_LIV =:CIN_LIV , NOM_LIV =:NOM_LIV , PRENOM_LIV =:PRENOM_LIV  ,ADRESSE_LIV = :ADRESSE_LIV,TELEPHONE =:TELEPHONE ,OBJET =:OBJET where ID_LIVRAISON =:ID_LIVRAISON" );

  query.bindValue(":ID_LIVRAISON", ID_LIVRAISON_string);
      query.bindValue(":CIN_LIV", cin_liv);
      query.bindValue("NOM_LIV", nom_liv);
       query.bindValue(":TELEPHONE", telephone);
       query.bindValue(":ADRESSE_LIV", Adresse_liv);
      query.bindValue(":PRENOM_LIV", prenom_liv);
    //  query.bindValue(":DATE_LIV ", Date_liv);
      query.bindValue(":OBJET", ID_OBJET_string);

    return query.exec();


}

bool Gestionlivraison::existe(int ID_LIVRAISON)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM MAYSSA.LIVRAISON WHERE ID_LIVRAISON = :ID_LIVRAISON");
    query.bindValue(":ID_LIVRAISON", ID_LIVRAISON);
    if(query.exec() && query.next())
        return true;
    return false;
}


QSqlQueryModel* Gestionlivraison::rechercher(QString motCle)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM MAYSSA.LIVRAISON WHERE (nom_liv LIKE :motCle) OR (prenom_liv LIKE :motCle) OR (Adresse_liv LIKE :motCle) OR (Objet LIKE :motCle) OR (CIN_LIV LIKE :motCle)");
    query.bindValue(":motCle", "%" + motCle + "%");
    query.exec();
    model->setQuery(query);
    return model;
}

/*int Gestionlivraison::calculerStatistiques(QDate date_liv)
{
    QSqlQuery query;
    QString dateString = date_liv.toString("yyyy-MM-dd");
    query.prepare("SELECT COUNT(*) FROM LOLITA.LIVRAISON WHERE Date_liv = :date_liv");
    query.bindValue(":date_liv", dateString);

    if(query.exec() && query.next())
    {
        return query.value(0).toInt();
    }
    else
    {
        return -1; // Erreur lors de l'exécution de la requête
    }
}*/
/*bool Gestionlivraison::comparer_date_livraison(const Gestionlivraison& livraison1, const Gestionlivraison& livraison2)
{
    QDate date1 = livraison1.Date_liv;
    QDate date2 = livraison2.Date_liv;
    int days = date1.daysTo(date2);
    return days > 0;
}

// fonction pour trier le tableau en ordre décroissant en fonction de la date de livraison
void Gestionlivraison::trie(Gestionlivraison* tab_liv, int taille_tab_liv) {
    std::sort(tab_liv, tab_liv + taille_tab_liv, comparer_date_livraison);
}*/
QSqlQueryModel * Gestionlivraison::trie()
{

   /* QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM LOLITA.LIVRAISON ORDER BY NOM_LIV ASC");

           q->exec();
           model->setQuery(*q);
           return model;*/
     QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM MAYSSA.LIVRAISON ORDER BY NOM_LIV ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifient"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Objet"));

    return model;

}
void Gestionlivraison::PDF()
{
    QPdfWriter pdf("D:/pdf.pdf");

    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1100,1200,"LISTES DES LIVREURS");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",14));



    QImage image("D:/logo.png");
    painter.drawImage(10, 20, image); // Insérer l'image à côté du titre

    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial",11));
    painter.drawText(200,3300,"CIN");
    painter.drawText(1300,3300,"NOM");
    painter.drawText(2700,3300,"PRENOM");
    painter.drawText(4000,3300,"Date");
    painter.drawText(6500,3300,"Adresse");
    // painter.drawText(7700,3300,"mail_per");


    QSqlQuery query;
    query.prepare("select * from MAYSSA.LIVRAISON");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(1).toString());
        painter.drawText(1300,i,query.value(2).toString());
        painter.drawText(2700,i,query.value(3).toString());
        painter.drawText(4000,i,query.value(4).toString());
        painter.drawText(6500,i,query.value(5).toString());
        painter.drawText(7700,i,query.value(6).toString());

        i = i + 500;

    }

    //QString s ="Tunis le "+ QDate::currentDate().toString();
    painter.drawText(500,450,"Tunis le " + QDate::currentDate().toString());
    painter.setFont(QFont("Arial",15));

}
QList<QDate> Gestionlivraison::getLivraisonsCalendrier()
{
    QList<QDate> livraisons;
    QSqlQuery query;
    query.prepare("SELECT TO_CHAR(Date_liv, 'YYYY-MM-DD') FROM MAYSSA.LIVRAISON");
    if(query.exec())
    {
        while(query.next())
        {
            QString date_liv_str = query.value(0).toString();
            QDate date_liv = QDate::fromString(date_liv_str, "yyyy-MM-dd");
            livraisons.append(date_liv);
        }
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
    }
    return livraisons;
}
/*QVector<QVector<QString>> Gestionlivraison::getStatsLivraisonByDate()
{
     QSqlQuery query;
    QVector<QVector<QString>> stats;

    // Exécution de la requête SQL pour récupérer les statistiques de livraison par date
    //QSqlQuery query((db);
    query.prepare("SELECT TO_CHAR(Date_liv, 'YYYY-MM-DD') AS date_livraison, COUNT(*) AS nb_livraisons FROM LOLITA.LIVRAISON  WHERE TO_CHAR(Date_liv, 'YYYY-MM-DD') BETWEEN '2023-04-01' AND '2023-04-30' GROUP BY TO_CHAR(Date_liv, 'YYYY-MM-DD');");
    if(!query.exec()){
        qDebug() << "Erreur lors de l'exécution de la requête SQL : " << query.lastError().text();
    }
    while(query.next()){
        QVector<QString> row;
        row.append(query.value(0).toString());
        row.append(query.value(1).toString());
        stats.append(row);
    }

    return stats;
}*/
/*void Gestionlivraison::afficherStatistiques() {
    mainWindow->afficherStatistiques();
}*/
