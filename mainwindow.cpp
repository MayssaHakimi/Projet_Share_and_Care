#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"

#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView_2->setModel(ev.afficher());
       on_ajouter_clicked();
       QChart *chart = new QChart();

                    chart=ev.statistique_chart();

                   QChartView *chartview = new QChartView(chart,ui->frame_3);

                   //chartview->resize(500,250);

                   chartview->setRenderHint(QPainter::Antialiasing);





                   QGridLayout *mainLayout = new QGridLayout(ui->frame_3);

                   mainLayout->addWidget(chartview, 1, 1);

                  //  ui->frame->setLayout(mainLayout);
                  chartview->setMinimumSize(500,250);
                  chartview->resize(500,250);
                  chartview->setParent(ui->frame_3);

 chartview->show();


                   QString notif = ev.notif();
                   if (notif == "")
                   {
                       ui->notif->hide();
                       ui->xx->hide();
                   }else
                       ui->notif->setText("event is :"+notif);

                   int ret=Ard.connect_arduino();
                       switch(ret){
                       case(0):qDebug()<<"arduino is available and connected to: "<< Ard.getarduino_port_name();
                       break;
                       case(1):qDebug()<<"arduino is available but not connected to "<< Ard.getarduino_port_name();
                       break;
                       case(-1):qDebug()<<"arduino is not available ";
                       }
                       QObject::connect(Ard.getserial(),SIGNAL(readyRead()),this,SLOT(detect()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::detect(){
    data1=Ard.read_from_arduino();
    if (data1=="2"){
        QMessageBox::information(nullptr, QObject::tr("Mouvement"),
                                 QObject::tr("quelq'un passe par cette zone."), QMessageBox::Ok);
    }
}
void MainWindow::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    QString nom_eve=ui->nom_eve->text();
    QString nom_eq=ui->nom_eq->text();
    QString nom_org = ui->nom_org->text();
    int np=ui->np->text().toInt();
    QString tache= ui->tache->text();
    QDate date_eve=ui->date->date();

    QString cin= QString::number(id);
    Event e(id, nom_eve,nom_eq,nom_org,np,date_eve,tache);


    if(e.existance(cin))

        {
            bool test=e.ajouter();
            if(test)
            {
                ui->tableView_2->setModel(ev.afficher());

                QMessageBox::information(nullptr, QObject::tr("ajout effuctué"),  QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout n'est pas effuctué"),QObject::tr("connection failed.\n"  "Click Cancel to exit."), QMessageBox::Cancel);

}}

void MainWindow::on_modifier_2_clicked()
{
    int id=ui->id->text().toInt();
    QString nom_eve=ui->nom_eve->text();
    QString nom_eq=ui->nom_eq->text();
    QString nom_org = ui->nom_org->text();
    int np=ui->np->text().toInt();
    QString tache= ui->tache->text();
    QDate date_eve=ui->date->date();
    QString date_e = date_eve.toString();
    QString cin= QString::number(id);
    QString nbp= QString::number(np);
    Event e(id, nom_eve,nom_eq,nom_org,np,date_eve,tache);
   QSqlQuery q;
   q.prepare("UPDATE EVENEMENT set id_eve = '"+cin+"' , nom_eve = '"+nom_eve+"' , nom_equipe = '"+nom_eq+"' , nom_organisateur = '"+nom_org+"' , nbre_participent ='"+nbp+"' , date_eve = '"+date_e+"' , tache_eve ='"+tache+"' where id_eve = '"+cin+"' ");
 if (q.exec())
 {
     ui->tableView_2->setModel(ev.afficher());

     QMessageBox::information(nullptr, QObject::tr("modification effuctué"),  QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);


}
else
QMessageBox::critical(nullptr, QObject::tr("modification n'est pas effuctué"),QObject::tr("connection failed.\n"  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_2_clicked()
{
     int id=ui->id->text().toInt();
     Event e;
     bool test;
     test=e.supprimer(id);
     if (test)
     {
         ui->tableView_2->setModel(ev.afficher());

         QMessageBox::information(nullptr, QObject::tr("supprision effuctué"),  QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
    QMessageBox::critical(nullptr, QObject::tr("supprision n'est pas effuctué"),QObject::tr("connection failed.\n"  "Click Cancel to exit."), QMessageBox::Cancel);

    }



void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
 QString v=ui->tableView_2->model()->data(index).toString();
 QSqlQuery q;
 q.prepare("select * from EVENEMENT where id_eve = '"+v+"'");
 if (q.exec())
 {
     while(q.next())
     {
         ui->id->setText(q.value(0).toString());
         ui->nom_eve->setText(q.value(1).toString());
          ui->nom_eq->setText(q.value(2).toString());
           ui->nom_org->setText(q.value(3).toString());
            ui->np->setValue(q.value(4).toInt());
             ui->date->setDate(q.value(5).toDate());
              ui->tache->setText(q.value(6).toString());
     }
 }
 else
 QMessageBox::critical(nullptr, QObject::tr("view n'est pas effuctué"),QObject::tr("connection failed.\n"  "Click Cancel to exit."), QMessageBox::Cancel);

}
/*QString reminderText = "";
QDateTime reminderDateTime = QDateTime::currentDateTime().addDays(1); // Set the reminder for tomorrow
setReminder(reminderText, reminderDateTime);
*/

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if (arg1 == "tri par date")
        ui->tableView_2->setModel(ev.trie(1));
    else if (arg1 == "tri par id")
        ui->tableView_2->setModel(ev.trie(2));
    else if (arg1 == "tri par nom")
        ui->tableView_2->setModel(ev.trie(3));
}

void MainWindow::on_rechercher_clicked()
{
    QString v=ui->recherche->text();
    ui->tableView_2->setModel(ev.rechercher(v));
}

void MainWindow::on_savetopdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty())
            {
                fileName.append(".pdf");
            }
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);
            QTextDocument d;
            QPdfWriter pdf(fileName);
            QPainter painter(&pdf);
            int i = 4000;
            painter.setPen(Qt::red);//titre
            painter.setFont(QFont("Cambria", 30));
            painter.drawText(1700,1200,"LISTES DES EVENEMENTS");
            painter.setPen(Qt::black);
            painter.setFont(QFont("Cambria",14));
            painter.drawRect(0,3000,9600,500);
            painter.setFont(QFont("Cambria",11));
            painter.drawText(200,3300,"ID_EVE");
            painter.drawText(1300,3300,"NOM_EVE");
            painter.drawText(2700,3300,"NOM_EQUIPE");
            painter.drawText(4000,3300,"NOM_ORGANISATEUR");
            painter.drawText(5300,3300,"NBRE_PARTICIPENT");
            painter.drawText(6600,3300,"DATE_EVE");
            painter.drawText(7900,3300,"TACHE_EVE");
            QSqlQuery query;
            query.prepare("select * from EVENEMENT");
            query.exec();
            while (query.next())
            {
                painter.drawText(200,i,query.value(0).toString());
                painter.drawText(1300,i,query.value(1).toString());
                painter.drawText(2700,i,query.value(2).toString());
                painter.drawText(4000,i,query.value(3).toString());
                painter.drawText(5300,i,query.value(4).toString());
                painter.drawText(6600,i,query.value(5).toString());
                painter.drawText(7900,i,query.value(6).toString());
                i = i + 500;
            }

            d.print(&printer);
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QString dateString = date.toString();

     QString query = QString("SELECT DO FROM TO_DO WHERE DATE_TO_DO = %1").arg(dateString);
       QSqlQuery sqlQuery;  sqlQuery.prepare(query);
        if (sqlQuery.exec()) {
            if (sqlQuery.next()) {
              ui->TO_DO->setText( sqlQuery.value(0).toString());
            }else
                ui->TO_DO->setText("");
        } else {
            qDebug() << "Error executing SQL query: " << sqlQuery.lastError().text();
        }

        qDebug() << "Selected Date: " << dateString;
}

void MainWindow::on_save_clicked()
{
    QString TODO = ui->TO_DO->toPlainText();
        QDate selectedDate = ui->calendarWidget->selectedDate();
        QString dateString = selectedDate.toString();

        QSqlQuery query;

        query.prepare("INSERT INTO TO_DO (DO,DATE_TO_DO) "
                      "VALUES (:text, :date )");

        query.bindValue(":text",TODO);
        query.bindValue(":date", dateString);


        query.exec();
}

void MainWindow::on_xx_clicked()
{
    ui->xx->hide();
    ui->notif->hide();
}

void MainWindow::on_pushButton_clicked()
{
    QChart *chart = new QChart();

                 chart=ev.statistique_chart();

                QChartView *chartview = new QChartView(chart,ui->frame_3);

                //chartview->resize(500,250);

                chartview->setRenderHint(QPainter::Antialiasing);





                QGridLayout *mainLayout = new QGridLayout(ui->frame_3);

                mainLayout->addWidget(chartview, 1, 1);

               //  ui->frame->setLayout(mainLayout);
               chartview->setMinimumSize(671,251);
               chartview->resize(671,251);
               chartview->setParent(ui->frame_3);

chartview->show();
}
