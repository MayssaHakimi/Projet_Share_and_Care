#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "don.h"
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QVBoxLayout>
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPrinter>

#include <QtNetwork/QNetworkAccessManager>
#include <QUrlQuery>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtWidgets>
#include <QtCore/qobject.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <iostream>
#include <string>
#include <memory>
#include <QtNetwork>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 #include <QtNetwork>
#include <QDateTime>
#include <QSslSocket>


QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //arduino
    int ret=Adon.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< Adon.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<Adon.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(Adon.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).


    //////////////////////////////////////////////
    ui->lineEdit_2->setValidator(new QIntValidator(0,999999999,this));
    ui->tab_affiche_2->setModel(Do.afficher_don());
     on_pushButton_22_clicked();
     on_pushButton_23_clicked();
//controle de vetement
     ui->comboBox->addItem("Vetement");
        ui-> comboBox->addItem("Nourriture");
     QObject::connect(ui->comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), [=](const QString &text) {
             if (text == "Vetement") {
                 ui->dateEdit->setDisabled(true);
             } else {
                ui->dateEdit->setEnabled(true);
             }
         });
 //controle de taille
     QObject::connect(ui->comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), [=](const QString &text) {
             if (text == "Nourriture") {
                 ui->comboBox_2->setDisabled(true);
             } else {
                ui->comboBox_2->setEnabled(true);
             }
         });

          //controle de nom
         QRegExpValidator *validator = new QRegExpValidator(QRegExp("[A-Za-z ]+"),ui->lineEdit); // Création du validateur
         ui->lineEdit->setValidator(validator);
          //controle de prenom
          QRegExpValidator(QRegExp("[A-Za-z ]+"),ui->lineEdit_3); // Création du validateur
         ui->lineEdit_3->setValidator(validator);







QSqlQuery query;
query.exec("SELECT id_don FROM DONS");

while (query.next()) {
    QString id_don = query.value(0).toString();
    ui->comboBox_3->addItem(id_don);

}


connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));
ui->lineEdit->clear();;
ui->lineEdit_3->clear();;
ui->lineEdit_2->clear();;

ui->dateEdit->clear();;
ui->spinBox->clear();;
ui->spinBox_2->clear();

statistique_don();
// chat

ui->lineEdit_6->setFocusPolicy(Qt::StrongFocus);
ui->textEdit_2->setFocusPolicy(Qt::NoFocus);
ui->textEdit_2->setReadOnly(true);
ui->listWidget->setFocusPolicy(Qt::NoFocus);

connect(ui->lineEdit_6, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
connect(ui->lineEdit_6, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
connect(&client, SIGNAL(newMessage(QString,QString)),
        this, SLOT(appendMessage(QString,QString)));
connect(&client, SIGNAL(newParticipant(QString)),
        this, SLOT(newParticipant(QString)));
connect(&client, SIGNAL(participantLeft(QString)),
        this, SLOT(participantLeft(QString)));

myNickName = client.nickName();
newParticipant(myNickName);
tableFormat.setBorder(0);
QTimer::singleShot(10 * 1000, this, SLOT(showInformation()));

}

MainWindow::~MainWindow()
{  QSslSocket socket;
    if (socket.isOpen())
    {
      socket.close();
    }
    delete ui;
}


void MainWindow::appendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;

    QTextCursor cursor(ui->textEdit_2->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, tableFormat);
    table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
    table->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar = ui->textEdit_2->verticalScrollBar();
    bar->setValue(bar->maximum());
}

void MainWindow::returnPressed()
{
    QString text = ui->lineEdit_6->text();
    if (text.isEmpty())
        return;

    if (text.startsWith(QChar('/'))) {
        QColor color = ui->textEdit_2->textColor();
        ui->textEdit_2->setTextColor(Qt::red);
        ui->textEdit_2->append(tr("! Unknown command: %1")
                         .arg(text.left(text.indexOf(' '))));
        ui->textEdit_2->setTextColor(color);
    } else {
        client.sendMessage(text);
        appendMessage(myNickName, text);
    }

    ui->lineEdit_6->clear();
}

void MainWindow::newParticipant(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QColor color = ui->textEdit_2->textColor();
    ui->textEdit_2->setTextColor(Qt::gray);
    ui->textEdit_2->append(tr("* %1 has joined").arg(nick));
    ui->textEdit_2->setTextColor(color);
    ui->listWidget->addItem(nick);
}

void MainWindow::participantLeft(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QList<QListWidgetItem *> items = ui->listWidget->findItems(nick,
                                                           Qt::MatchExactly);
    if (items.isEmpty())
        return;

    delete items.at(0);
    QColor color = ui->textEdit_2->textColor();
    ui->textEdit_2->setTextColor(Qt::gray);
    ui->textEdit_2->append(tr("* %1 has left").arg(nick));
    ui->textEdit_2->setTextColor(color);
}

void MainWindow::showInformation()
{
    if (ui->listWidget->count() == 1) {
        QMessageBox::information(this, tr("Chat"),
                                 tr("Launch several instances of this "
                                    "program on your local network and "
                                    "start chatting!"));
    }
}






void MainWindow::send_sms()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        QString response = QString::fromUtf8(reply->readAll());
        qDebug() << "Response: " << response;
        qDebug() << "SMS envoyé avec succès !";
        reply->deleteLater();
    });

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC6b2316ab038b93972d30b2342f18eff1/Messages.json");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("From", "+15732843399"); // votre numéro Twilio
    params.addQueryItem("MessagingServiceSid", "MG7d2ddea98fe438f60aa5bbe1ac6bbb1d");

    params.addQueryItem("To", "+21697336009"); // le numéro de téléphone du destinataire
    params.addQueryItem("Body", "Un don a été supprimé !");

    url.setQuery(params);
    QByteArray data = url.toEncoded(QUrl::RemoveFragment);

    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg("AC6b2316ab038b93972d30b2342f18eff1").arg("0ee64390dcf947717c204aa570d0c40b").toUtf8()).toBase64());
    QNetworkReply *reply = manager->post(request, data);

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error: " << reply->errorString();
    }

}






void MainWindow::on_pushButton_3_clicked()
{
     int id_don=ui->spinBox_2->text().toInt();
    QString nom_don=ui->lineEdit->text();
    QString prenom_don=ui->lineEdit_3->text();
    QString cin_don=ui->lineEdit_2->text();
    QString type_don=ui->comboBox->currentText();
    QString taille=ui->comboBox_2->currentText();
    QString date_v=ui->dateEdit->text();
    int quantite=ui->spinBox->text().toInt();

    Don D (id_don,nom_don ,prenom_don , cin_don, type_don, taille, date_v, quantite);

    bool test=D.ajouter_don();


    if (test)
   {


        ui->comboBox_3->clear();

        QSqlQuery query;
        query.exec("SELECT id_don FROM DONS");

        while (query.next()) {
            QString id_don = query.value(0).toString();
            ui->comboBox_3->addItem(id_don);
        }

        connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

        ui->tab_affiche_2->setModel(Do.afficher_don());

        ui->lineEdit->clear();;
        ui->lineEdit_3->clear();;
        ui->lineEdit_2->clear();;
        ui->dateEdit->clear();;
        ui->spinBox->clear();;
        ui->spinBox_2->clear();

        QMessageBox::information(nullptr , QObject::tr("Bien") , QObject::tr("Ajout effectué"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr , QObject::tr("Erreur") , QObject::tr("Ajout n'est pas effectué "),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_20_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id_don FROM DONS");

    while (query.next()) {
        QString id_don = query.value(0).toString();
        ui->comboBox_3->addItem(id_don);
    }

    connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

     int id_don=ui->comboBox_3->currentText().toInt();
    bool test=Do.supprimer_don( id_don);



     if (test)
    {   send_sms();

         ui->tab_affiche_2->setModel(Do.afficher_don());

         ui->comboBox_3->clear();
         QSqlQuery query;
         query.exec("SELECT id_don FROM DONS");

         while (query.next()) {
             QString id_don = query.value(0).toString();
             ui->comboBox_3->addItem(id_don);
         }

         connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

         ui->lineEdit->clear();;
         ui->lineEdit_3->clear();;
         ui->lineEdit_2->clear();;
         ui->dateEdit->clear();;
         ui->spinBox->clear();;
         ui->spinBox_2->clear();





             QMessageBox::information(nullptr , QObject::tr("Bien") , QObject::tr("Suppression effectuée"),QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr , QObject::tr("Erreur") , QObject::tr("Suppression n'est pas effectuée "),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_19_clicked()
{
    QString nom_don=ui->lineEdit->text();
    QString prenom_don=ui->lineEdit_3->text();
    QString cin_don=ui->lineEdit_2->text();
    QString type_don=ui->comboBox->currentText();
    QString taille=ui->comboBox_2->currentText();
    QString date_v=ui->dateEdit->text();
    int quantite=ui->spinBox->text().toInt();
    int id_don=ui->comboBox_3->currentText().toInt();

    Don D (id_don,nom_don ,prenom_don , cin_don, type_don, taille, date_v, quantite);

    bool test=D.modifier_don(id_don);


    if (test)
   {   ui->tab_affiche_2->setModel(Do.afficher_don());
        ui->comboBox_3->clear();
        QSqlQuery query;
        query.exec("SELECT id_don FROM DONS");

        while (query.next()) {
            QString id_don = query.value(0).toString();
            ui->comboBox_3->addItem(id_don);
        }

        connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

        ui->lineEdit->clear();;
        ui->lineEdit_3->clear();;
        ui->lineEdit_2->clear();;
        ui->dateEdit->clear();;
        ui->spinBox->clear();;
        ui->spinBox_2->clear();
        QMessageBox::information(nullptr , QObject::tr("Bien") , QObject::tr("Modification effectuée"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr , QObject::tr("Erreur") , QObject::tr("Modification n'est pas effectuée "),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->tab_affiche_2->setModel(Do.trieAsc());
}

void MainWindow::on_pushButton_23_clicked()
{
     ui->tab_affiche_2->setModel(Do.trieDesc());

}


void MainWindow::on_pushButton_7_clicked()
{
              ui->tab_affiche_2->setModel(Do.recherche_don(ui->lineEdit_8->text(),ui->lineEdit_8->text()));
}

void MainWindow::statistique_don()
{
            QBarSet *set0 = new QBarSet("Vetement");
            QBarSet *set1 = new QBarSet("Nourriture");


      //   *set0 << Do.getVetement()<< 0 << 0;
       //     *set1 << 0 << Do.getNourriture();

           *set0 <<  Do.calculer_type("Vetement")<< 0 << 0;
            *set1 << 0 << Do.calculer_type("Nourriture") ;

            QBarSeries *series = new QBarSeries();
            series->append(set0);
            series->append(set1);


            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Statistique");
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTheme(QChart::ChartThemeBrownSand);

            QStringList categories;
            categories << "Vetement"
                            << 0 << "Nourriture";

                  QBarCategoryAxis *axis = new QBarCategoryAxis();
                  axis->append(categories);
                  chart->createDefaultAxes();
                  chart->setAxisX(axis, series);



                  chart->legend()->setVisible(true);
                  chart->legend()->setAlignment(Qt::AlignBottom);

                  QChartView *chartview = new QChartView(chart);
                  chartview->setRenderHint(QPainter::Antialiasing);




//chart->legend()->hide();




//setMinimumSize(800, 600);

                 // QGridLayout *mainLayout = new QGridLayout;
                  QGridLayout *mainLayout = new QGridLayout(ui->frame);

                  mainLayout->addWidget(chartview, 1, 1);

                 //  ui->frame->setLayout(mainLayout);
                 chartview->setMinimumSize(681, 331);
                 chartview->resize(681, 331);
                 chartview->setParent(ui->frame);

chartview->show();





}




void MainWindow::on_comboBox_3_currentIndexChanged(const QString& id_don)
{
    QSqlQuery query;
        query.prepare("SELECT nom_don, prenom_don, cin_don, type_don, taille, date_v, quantite FROM DONS WHERE id_don = :id_don");
        query.bindValue(":id_don", id_don);

        if (query.exec() && query.next()) {
            QString nom_don = query.value(0).toString();
            QString prenom_don = query.value(1).toString();
            QString cin_don = query.value(2).toString();
            QString type_don = query.value(3).toString();
            QString taille = query.value(4).toString();
            QString date_v = query.value(5).toString();
            int quantite = query.value(6).toInt();
             int id_don =query.value(7).toInt();

            ui->lineEdit->setText(nom_don);
            ui->lineEdit_3->setText(prenom_don);
            ui->lineEdit_2->setText(cin_don);
            ui->comboBox->setCurrentText(type_don);
            ui->comboBox_2->setCurrentText(taille);
            ui->dateEdit->setDate(QDate::fromString(date_v, "yyyy-MM-dd"));
            ui->spinBox->setValue(quantite);
            ui->spinBox_2->setValue(id_don);
        }
    }





//PDF
void MainWindow::on_pushButton_24_clicked()
{
    QSqlQueryModel model;
          model.setQuery("select  nom_don , prenom_don, cin_don , type_don ,taille , date_v , quantite from DONS");

           QString html = "<table  border='2'> <thead> <tr>  <th>Nom de donateur</th> <th>Prenom de donateur</th> <th> CIN de donateur</th> <th> Type de don</th> <th> Taille </th><th> Date de validité </th> <th> Quantité </th> </tr> </thead><tbody > ";


          for (int i = 0; i < model.rowCount(); ++i) {


                       QString quantite = model.record(i).value("quantite").toString();
                                QString taille = model.record(i).value("taille").toString();
                                 QString cin_donateur = model.record(i).value("cin_don").toString();
                                   QString  type_don = model.record(i).value(" type_don").toString();
                                     QString date_v = model.record(i).value("date_v").toString();
                                             QString nom_don = model.record(i).value("nom_don").toString();
              QString prenom_don = model.record(i).value("prenom_don").toString();
   html += "<tr >   <td>"+nom_don+"</td> <td>"+prenom_don+"</td><td>"+cin_donateur+"</td><td>"+type_don+"</td><td>"+taille+"</td><td>"+date_v+"</td> <td>"+quantite+"</td></tr>";
          }
       html+="</tbody></table>";
       QString strStream;
       QTextStream out(&strStream);

       const int rowCount = ui->tab_affiche_2->model()->rowCount();
       const int columnCount = ui->tab_affiche_2->model()->columnCount();

       out <<  "<html>\n"
           "<head>\n"

           "<meta Content=\"Text/html; charset=Windows-1251\">\n"



           <<  QString("<title>%1</title>\n").arg("strTitle")
           <<  "</head>\n"
           "<body bgcolor=#dfabc9 link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
           "<center>  <img src='C:/unnamed.png'></img>  <H1>Liste des dons </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

       // headers
       out << "<thead><tr bgcolor=#ba7191> <th>Numero</th>";
      for (int column = 0; column < columnCount; column++)
           if (!ui->tab_affiche_2->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tab_affiche_2->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++)
       {
           out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
           for (int column = 0; column < columnCount; column++)
           {
              if (!ui->tab_affiche_2->isColumnHidden(column))
               {
                   QString data = ui->tab_affiche_2->model()->data(ui->tab_affiche_2->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }
       out <<  "</table> </center>\n"
           "</body>\n"
           "</html>\n";

         QTextDocument document;
         document.setHtml(html);
       QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty())
       {
           fileName.append(".pdf");
       }

         QPrinter printer(QPrinter::PrinterResolution);
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setOutputFileName("Fiche.pdf");
      // QPrinter printer (QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

         document.print(&printer);
       QTextDocument doc;
       doc.setHtml(strStream);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);
}



void MainWindow::on_pushButton_10_clicked()
{
statistique_don();
}

// arduino
//vetement
void MainWindow::on_pushButton_9_clicked()
{int vet = Do.getVetement();
    if (vet==0)
     {Adon.write_to_arduino("0");}
    else Adon.write_to_arduino("1");
}
//nourriture
void MainWindow::on_pushButton_11_clicked()
{
    int nourr = Do.getNourriture();

        if (nourr==0)
         {Adon.write_to_arduino("2");}
        else Adon.write_to_arduino("3");
}
///////////////////////////////////////::::::::::
