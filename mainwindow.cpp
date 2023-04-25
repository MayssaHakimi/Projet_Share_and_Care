#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "beneficiaire.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QLoggingCategory>
#include <QDateTime>
#include "smtp.h"
#include "smtp.cpp"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPrinter>

  #include <QtWidgets/QApplication>
  #include <QtWidgets/QMainWindow>
  #include <QtCharts/QChartView>
  #include <QtCharts/QSplineSeries>
 #include <QtCharts/QCategoryAxis>
  #include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QBarCategoryAxis>
#include <QVBoxLayout>

#include"arduino.h"



MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   //arduino
       int ret=Aben.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< Aben.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<Aben.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(Aben.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).

     ui->lineEdit_id->setValidator(new QIntValidator(0, 99999999, this));
     ui->lineEdit_cin->setValidator(new QIntValidator(0, 99999999, this));
     ui->lineEdit_tel->setValidator(new QIntValidator(10000000, 99999999, this));
     ui->tab_aff->setModel(Bo.afficher());



}

MainWindow::~MainWindow()
{
   delete ui;
}




//ajout
void MainWindow::on_pushButton_clicked()
{
    int id_ben=ui->lineEdit_id->text().toInt();
    QString nom_ben=ui->lineEdit_nom->text();
    QString prenom_ben=ui->lineEdit_prenom->text();
    QString lieu_ben=ui->lineEdit_lieu->text();
    int age_ben=ui->spinBox_age->text().toInt();
    int nb_mf=ui->spinBox_nb->text().toInt();
    QString type_demande_ben=ui->lineEdit_td->text();
    int cin_ben=ui->lineEdit_cin->text().toInt();
    int telephone_ben=ui->lineEdit_tel->text().toInt();
 Beneficiaire B( id_ben , nom_ben , prenom_ben, lieu_ben, age_ben, nb_mf, type_demande_ben, cin_ben, telephone_ben);
 bool test=B.ajouter();
    if(test)
    {
        ui->tab_aff->setModel(Bo.afficher());
        QMessageBox::information(nullptr,QObject::tr("not OK"),
                                 QObject::tr("ajout avec succes\n"
                                            "cliquez sur Annuler pour quitter."));

        QFile file ("C:/Users/Mohamed Amine/Desktop/ben/history.txt");

        if (!file.open(QFile::WriteOnly  | QFile::Append))
            {
            QMessageBox::warning(this, "title","file  not open");
            }
        QTextStream out (&file);

         QDate datenow = QDate::currentDate();
        QString datenowst=datenow.toString();
        QTime timenow= QTime::currentTime();
            QString timenowst=timenow.toString();

        //QString  text  = ui->history->toPlainText();
        out << "--------------------------------------------------------------------------------------\n""Ajout d'un beneficiaire  " << id_ben << "  le  " << datenowst << "  à l'heure   " << timenowst << "\n" ;
        file.flush();
        file.close ();

    }
    else

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout non effectue\n"
                                            "cliquez sur Annuler pour quitter."));

}
//suppression

void MainWindow::on_pushButton_2_clicked()
{
    int id_ben=ui->lineEdit_id->text().toInt();
    bool test=Btmp.supprimer(id_ben);
        if(test)
        {
            ui->tab_aff->setModel(Bo.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("supression effectue\n"
                                                "cliquez sur Annuler pour quitter."));
            QFile file ("C:/Users/Mohamed Amine/Desktop/ben/history.txt");

            if (!file.open(QFile::WriteOnly  | QFile::Append))
                {
                QMessageBox::warning(this, "title","file  not open");
                }
            QTextStream out (&file);

             QDate datenow = QDate::currentDate();
            QString datenowst=datenow.toString();
            QTime timenow= QTime::currentTime();
                QString timenowst=timenow.toString();

            //QString  text  = ui->history->toPlainText();
            out << "--------------------------------------------------------------------------------------\n""Supression du beneficiaire " << id_ben << "  le  " << datenowst << "  à l'heure   " << timenowst << "\n" ;
            file.flush();
            file.close ();

        }
        else

            QMessageBox::information(nullptr,QObject::tr("not OK"),
                                     QObject::tr("Suppression non effectue\n"
                                                "cliquez sur Annuler pour quitter."));

        }




//affichage
void MainWindow::on_pushButton_3_clicked()
{
    int id_ben=ui->lineEdit_id->text().toInt();
    QString nom_ben=ui->lineEdit_nom->text();
    QString prenom_ben=ui->lineEdit_prenom->text();
    QString lieu_ben=ui->lineEdit_lieu->text();
    int age_ben=ui->spinBox_age->text().toInt();
    int nb_mf=ui->spinBox_nb->text().toInt();
    QString type_demande_ben=ui->lineEdit_td->text();
    int cin_ben=ui->lineEdit_cin->text().toInt();
    int telephone_ben=ui->lineEdit_tel->text().toInt();
    Beneficiaire B( id_ben , nom_ben , prenom_ben, lieu_ben, age_ben, nb_mf, type_demande_ben, cin_ben, telephone_ben);
    bool test=B.modifier();
    if(test)
    {
        ui->tab_aff->setModel(Bo.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectue\n"
                                            "cliquez sur Annuler pour quitter."));

        QFile file ("C:/Users/Mohamed Amine/Desktop/ben/history.txt");

        if (!file.open(QFile::WriteOnly  | QFile::Append))
            {
            QMessageBox::warning(this, "title","file  not open");
            }
        QTextStream out (&file);

         QDate datenow = QDate::currentDate();
        QString datenowst=datenow.toString();
        QTime timenow= QTime::currentTime();
            QString timenowst=timenow.toString();

        //QString  text  = ui->history->toPlainText();
        out << "--------------------------------------------------------------------------------------\n""Modification d'un beneficiaire  " << id_ben << "  le  " << datenowst << "  à l'heure   " << timenowst << "\n" ;
        file.flush();
        file.close ();
    }
    else

        QMessageBox::information(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("modification non effectue\n"
                                            "cliquez sur Annuler pour quitter."));


}







void MainWindow::on_pushButton_tri_clicked()
{
    QSqlQueryModel* sortedModel = B.tri();
    ui->tab_aff->setModel(sortedModel);
}
void MainWindow::on_pushButton_tri_2_clicked()
{
    QSqlQueryModel* sortedModel = B.tri2();
    ui->tab_aff->setModel(sortedModel);
}
void exportToPdf(QTableView* view, const QString& filename)
{
    QPdfWriter writer(filename);
    QPainter painter(&writer);
    view->render(&painter);
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QString strStream;
       QTextStream out(&strStream);

       const int rowCount = ui->tab_aff->model()->rowCount();
       const int columnCount = ui->tab_aff->model()->columnCount();

       out <<  "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           <<  QString("<title>%1</title>\n").arg("strTitle")
           <<  "</head>\n"
           "<body bgcolor=#f8dced link=#5000A0>\n"
            //path
           //     "<align='right'> " << datefich << "</align>"
           "<center> <img src='C:/jklm.png'> </img>  <H1>Liste Des beneficiaires </H1></br></br><table border=0.5 cellspacing=0 >\n";

       // headers
       out << "<thead><tr bgcolor=#ba7191> <th>Numero</th>";
       for (int column = 0; column < columnCount; column++)
           if (!ui->tab_aff->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tab_aff->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++)
       {
           out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
           for (int column = 0; column < columnCount; column++)
           {
               if (!ui->tab_aff->isColumnHidden(column))
               {
                   QString data = ui->tab_aff->model()->data(ui->tab_aff->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }
       out <<  "</table> </center>\n"
           "</body>\n"
           "</html>\n";

       QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty())
       {
           fileName.append(".pdf");
       }

       QPrinter printer (QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       doc.setHtml(strStream);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);
       }



void MainWindow::on_pushButton_rech_clicked()
{
    QString searchValue = ui->lineEdit_search->text();

    if (searchValue.isEmpty()) {
        ui->tab_aff->setModel(B.afficher());
    } else {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(QString("SELECT * FROM beneficiaire WHERE (nom_ben LIKE '%%1%') OR (id_ben LIKE '%%1%')OR (prenom_ben LIKE '%%1%')OR (lieu_ben LIKE '%%1%')OR (age_ben LIKE '%%1%')").arg(searchValue));
        ui->tab_aff->setModel(model);

    }

}


void MainWindow::on_histbouton_clicked()
{
    QFile file ("C:/Users/Mohamed Amine/Desktop/ben/history.txt");

       if (!file.open(QFile::ReadOnly  | QFile::Text))
           {
           QMessageBox::warning(this, "title","file  not open");
           }
       QTextStream in (&file);
       QString  text  = in.readAll();
       ui->plainTextEdit->setPlainText(text);

       file.close();
}




void MainWindow::on_mailbutt_clicked()
{
    Smtp* smtp = new Smtp("lefi.amine@esprit.tn", "popamqoxierydzbe", "smtp.gmail.com", 465 , 1500000);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            smtp->sendMail("lefi.amine@esprit.tn", ui->mail->text() , ui->subject->text(),ui->msg->toPlainText());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Mail envoyé"));
}
 QT_CHARTS_USE_NAMESPACE


void MainWindow::on_statbutton_clicked()
{
    QBarSet *set0 = new QBarSet("bebe");
    QBarSet *set1 = new QBarSet("enfant");
    QBarSet *set2 = new QBarSet("jeune");
     QBarSet *set3 = new QBarSet("adulte");
     QBarSet *set4 = new QBarSet("vieux");
     set0->setBrush(QColor(66, 44, 48));
     set1->setBrush(QColor(157, 183, 94));
     set2->setBrush(QColor(196,170, 157));
     set3->setBrush(QColor(223, 171, 201));
     set4->setBrush(QColor(186, 113, 145));
    int nb0=0;
    QSqlQuery query0("select * from beneficiaire where age_ben BETWEEN 0 AND 3");// calculer le nombre de type avis=parfait
    while(query0.next())
    {
        nb0++;
    }
    int nb1=0;
    QSqlQuery query1("select * from beneficiaire where age_ben BETWEEN 3 AND 13");
    while(query1.next())
    {
        nb1++;
    }
    int nb2=0;
    QSqlQuery query2("select * from beneficiaire where age_ben BETWEEN 13 AND 18");
    while(query2.next())
    {
        nb2++;
    }
    int nb3=0;
    QSqlQuery query3("select * from beneficiaire where age_ben BETWEEN 18 AND 55");
    while(query3.next())
    {
        nb3++;
    }

    int nb4=0;
    QSqlQuery query4("select * from beneficiaire where age_ben BETWEEN 55 AND 200");
    while(query4.next())
    {
        nb4++;
    }
  *set0 << nb0 ;
  *set1 << nb1 ;
  *set2 << nb2 ;
   *set3 << nb3 ;
   *set4 << nb4 ;


//![1]

//![2]
    QBarSeries *series = new QBarSeries();
     series->append(set0);
     series->append(set1);
     series->append(set2);
     series->append(set3);
     series->append(set4);

//![2]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("age-ben");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "age_ben";

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
int nb=0;
QSqlQuery query("select * from beneficiaires ");
while(query.next())//Retrieves the next record in the result,
{
   nb++;
}

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,nb);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    QGridLayout *mainLayout = new QGridLayout(ui->stats);

                      mainLayout->addWidget(chartView, 1, 1);

                     //  ui->frame->setLayout(mainLayout);
                     chartView->setMinimumSize(681, 331);
                     chartView->resize(681, 331);
                     chartView->setParent(ui->stats);

    chartView->show();
   /* QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

   chartView->resize(1000,500);
    chartView->show();*/
    //ui->stats->setLayout(new QVBoxLayout);
   // ui->stats->layout()->addWidget(chartView);

   //ui->stats->resize(500,400);
}





void MainWindow::on_aff_clicked()
{
    int id_ben=ui->lineEdit_id->text().toInt();
    QString nom_ben=ui->lineEdit_nom->text();
    QString prenom_ben=ui->lineEdit_prenom->text();
    QString lieu_ben=ui->lineEdit_lieu->text();
    int age_ben=ui->spinBox_age->text().toInt();
    int nb_mf=ui->spinBox_nb->text().toInt();
    QString type_demande_ben=ui->lineEdit_td->text();
    int cin_ben=ui->lineEdit_cin->text().toInt();
    int telephone_ben=ui->lineEdit_tel->text().toInt();
    Beneficiaire B( id_ben , nom_ben , prenom_ben, lieu_ben, age_ben, nb_mf, type_demande_ben, cin_ben, telephone_ben);
    bool test=B.modifier();
    if(test)
    {
        ui->tab_aff->setModel(Bo.afficher());


    }

}


void MainWindow::on_alarmbutton_clicked()
{
    QSqlQuery query;
    int id_ben=ui->line_edit_mdp->text().toInt();
       query.prepare("SELECT * FROM beneficiaire WHERE id_ben = :id_ben");
       query.bindValue(":id_ben", id_ben);
       if (!query.exec())
       {
           qWarning() << "Failed to execute query.";

       }

       // Check if the query returned any rows
       if (query.next())
       {
           // Password exists in the database
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("mot de passe valide"));
           Aben.write_to_arduino("1");
       }
       else
       {
           // Password does not exist in the database
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("mot de passe invalide"));
           Aben.write_to_arduino("0");
       }
}


