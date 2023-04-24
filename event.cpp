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

    query.prepare("INSERT INTO EVENEMENT (ID_EVE, NOM_EVE,nom_equipe,nom_organisateur,nbre_participent,date_eve,tache_eve) "
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
    model->setQuery("SELECT * FROM EVENEMENT");
    return model;
}
bool Event:: supprimer(int id)
{
    QSqlQuery query;
    query.prepare("delete from EVENEMENT where ID_EVE=:id");
    query.bindValue(":id",id);
    return  query.exec();
}
bool Event::existance(QString id)
{
    QMessageBox msgBox;
    QSqlQuery query;
    int count=0;
    query.prepare("SELECT * FROM EVENEMENT WHERE ID_EVE= ?");
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
QSqlQueryModel * Event::rechercher(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from EVENEMENT where NOM_EVE like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_eve "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_eve"));

    return model;
}
QSqlQueryModel* Event::trie(int a)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    switch(a){
  case 1 :
    model->setQuery("select * from EVENEMENT ORDER BY DATE_EVE asc");
break;
  case 2 :
         model->setQuery("select * from EVENEMENT ORDER BY ID_EVE asc");
        break;
  case 3 :
        model->setQuery("select * from EVENEMENT ORDER BY NOM_EVE asc");
        break;
    }
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_eve"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_eve"));

    return model;
}
QChart *Event::statistique_chart()
{
    QSqlQuery query0,query1,query2,query3,query4;

        qreal c1_1=0,c1_2=0,c1_3=0,c1_4=0;

        int totale=0;

        query0.prepare("SELECT * FROM EVENEMENT");
        query0.exec();

        query1.prepare("SELECT * FROM EVENEMENT WHERE nom_organisateur='imen'");
        query1.exec();

        query2.prepare("SELECT * FROM EVENEMENT WHERE nom_organisateur='rami'");
        query2.exec();

        query3.prepare("SELECT * FROM EVENEMENT WHERE nom_organisateur='sami'");
        query3.exec();

        query4.prepare("SELECT * FROM EVENEMENT WHERE nom_organisateur='samir'");
        query4.exec();



        while (query0.next()){totale++;}

        while (query1.next()){c1_1++;}
        while (query2.next()){c1_2++;}
        while (query3.next()){c1_3++;}
        while (query4.next()){c1_4++;}

        //totale=totale/2;

        QBarSet *set0 = new QBarSet("imen");
        QBarSet *set1 = new QBarSet("rami");
        QBarSet *set2 = new QBarSet("sami");
        QBarSet *set3 = new QBarSet("samir");

        *set0 << c1_1;
        *set1 << c1_2;
        *set2 << c1_3;
        *set3 << c1_4;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistique des organisateurs par rapport aux evenements");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTheme(QChart::ChartThemeBrownSand);//changer couleur

        //QStringList nom_organisateur = {"imen", "rami", "sami", "samir"};
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        //axisX->append(nom_organisateur);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,totale);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QPalette pal = qApp->palette();
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
        qApp->setPalette(pal);

        return chart;
    }

/*// This function sets a reminder to show a message box with the given reminder text at the given date and time
void setReminder(const QString &reminderText, const QDateTime &reminderDateTime)
{
    // Calculate the time difference between the current time and the reminder time
    qint64 timeDiff = QDateTime::currentDateTime().msecsTo(reminderDateTime);

    // If the reminder time is in the past, show an error message and return
    if (timeDiff < 0) {
        QMessageBox::critical(nullptr, "Error", "The reminder time is in the past.");
        return;
    }

    // Create a timer object that will trigger the reminder at the specified time
    QTimer *timer = new QTimer(nullptr);
    timer->setSingleShot(true);
    timer->setInterval(timeDiff);
    QObject::connect(timer, &QTimer::timeout, [=]() {
        QMessageBox::information(nullptr, "Reminder", reminderText);
        timer->deleteLater(); // Cleanup the timer object
    });
    // Start the timer
      timer->start();
  }

*/
QString Event::notif()
{
    QString notif = "";
    QDate b = QDate::currentDate();
    QString datestring = b.toString();
    QString query = QString("SELECT nom_eve FROM EVENNEMENT WHERE date_eve = %1").arg(datestring);
       QSqlQuery sqlQuery;
       sqlQuery.prepare(query);
        if (sqlQuery.exec()) {
            if (sqlQuery.next()) {
           notif = sqlQuery.value(0).toString();
            }
        } else {
            qDebug() << "Error executing SQL query: " << sqlQuery.lastError().text();
        }
        return notif;
}
