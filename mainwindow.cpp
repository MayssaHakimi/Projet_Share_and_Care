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


#include <QtCore/qobject.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <iostream>
#include <string>
#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <QDateTime>
#include <QSslSocket>

//#include "twilio.hh"

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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



statistique_don();

QSqlQuery query;
query.exec("SELECT id_don FROM DONS");

while (query.next()) {
    QString id_don = query.value(0).toString();
    ui->comboBox_3->addItem(id_don);








   // chat
  QSslSocket socket;
    // Check for SSL support.  If SSL support is not available, show a
    // message to the user describing what to do to enable SSL support.
    if (QSslSocket::supportsSsl())
    {
      ui->pushButton_9->setEnabled(true);
    }
    else
    {
      QString noSslMsg = QString("%1\n%2")
          .arg("*** Your version of Qt does support SSL ***")
          .arg("You must obtain a version of Qt that has SSL"
               "support enabled.  If you believe that your "
               "version of Qt has SSL support enabeld, you may "
               "need to install the OpenSSL run-time libraries.");

      ui->textEdit->setText(noSslMsg);
    }

    // QSslSocket emits the encrypted() signal after the encrypted connection is established
    connect(&socket, SIGNAL(encrypted()), this, SLOT(connectedToServer()));

    // Report any SSL errors that occur
    connect(&socket, SIGNAL(sslErrors(const QList<QSslError> &)), this, SLOT(sslErrors(const QList<QSslError> &)));

    connect(&socket, SIGNAL(disconnected()), this, SLOT(connectionClosed()));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
    connect(&socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError()));



}


connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));
ui->lineEdit->clear();;
ui->lineEdit_3->clear();;
ui->lineEdit_2->clear();;

ui->dateEdit->clear();;
ui->spinBox->clear();;
ui->spinBox_2->clear();

}

MainWindow::~MainWindow()
{  QSslSocket socket;
    if (socket.isOpen())
    {
      socket.close();
    }
    delete ui;
}

/*void MainWindow::send_sms()
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
    params.addQueryItem("Body", "Ceci est un SMS de test !");

    url.setQuery(params);
    QByteArray data = url.toEncoded(QUrl::RemoveFragment);

    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg("AC6b2316ab038b93972d30b2342f18eff1").arg("c674734c7e670191c949050f4269fd41").toUtf8()).toBase64());
    QNetworkReply *reply = manager->post(request, data);

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error: " << reply->errorString();
    }

}
*/

#include <QtNetwork/QNetworkAccessManager>
#include <QUrlQuery>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

void MainWindow::sendSMS(QString apiKey, QString apiSecret, QString from, QString to, QString message)
{
    QNetworkAccessManager manager;
    QUrl url("https://rest.nexmo.com/sms/json");

    QUrlQuery params;
    params.addQueryItem("3a33612e", apiKey);
    params.addQueryItem("sdix6w22WWFy5EoC", apiSecret);
    params.addQueryItem("Vonage APIs", from);
    params.addQueryItem("21697336009", to);
    params.addQueryItem("text", message);
    url.setQuery(params);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager.post(request, QByteArray());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    QJsonArray messages = obj.value("messages").toArray();
    QJsonObject messageObj = messages.first().toObject();
    QString status = messageObj.value("status").toString();
    if (status == "0")
    {
        // Le SMS a été envoyé avec succès
    }
    else
    {
        // Une erreur s'est produite lors de l'envoi du SMS
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
    {   //send_sms();
         sendSMS("3a33612e","sdix6w22WWFy5EoC","Vonage APIs","21697336009","text");
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



            *set0 << Do.vetement();
            *set1 << Do.nourriture();

            QBarSeries *series = new QBarSeries();
            series->append(set0);
            series->append(set1);


            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Statistique");
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTheme(QChart::ChartThemeBrownSand);

            QStringList categories;
            categories << "Type de don" ;

                  QBarCategoryAxis *axis = new QBarCategoryAxis();
                  axis->append(categories);
                  chart->createDefaultAxes();
                  chart->setAxisX(axis, series);



                  chart->legend()->setVisible(true);
                  chart->legend()->setAlignment(Qt::AlignBottom);

                  QChartView *chartview = new QChartView(chart);
                  chartview->setRenderHint(QPainter::Antialiasing);



                  QGridLayout *mainLayout = new QGridLayout;
                  mainLayout->addWidget(chartview, 1, 1);
                   ui->groupBox_2->setLayout(mainLayout);
                  setMinimumSize(800, 600);



}

void MainWindow::statistique_don_update()
{

    // Accéder au layout actuel du groupBox_2
    QLayout *currentLayout = ui->groupBox_2->layout();

    // Supprimer tous les widgets enfants du groupBox_2
    if (currentLayout != nullptr)
    {
        QLayoutItem *item;
        while ((item = currentLayout->takeAt(0)) != nullptr)
        {
            delete item->widget();
            delete item;
        }
    }

 statistique_don();
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






void MainWindow::on_pushButton_24_clicked()
{
    QSqlQueryModel model;
          model.setQuery("select id_don , nom_don , prenom_don, cin_don , type_don ,taille , date_v , quantite from DONS");

           QString html = "<table  border='2'> <thead> <tr> <th>#</th> <th>Id</th> <th>Nom de donateur</th> <th>Prenom de donateur</th> <th> CIN de donateur</th> <th> Type de don</th> <th> Taille </th><th> Date de validité </th> <th> Quantité </th> </tr> </thead><tbody > ";


          for (int i = 0; i < model.rowCount(); ++i) {

              QString id_don = model.record(i).value("id_don").toString();
                       QString quantite = model.record(i).value("quantite").toString();
                                QString taille = model.record(i).value("taille").toString();
                                 QString cin_don = model.record(i).value("cin_don").toString();
                                   QString  type_don = model.record(i).value(" type_don").toString();
                                     QString date_v = model.record(i).value("date_v").toString();
                                             QString nom_don = model.record(i).value("nom_don").toString();
              QString prenom_don = model.record(i).value("prenom_don").toString();
   html += "<tr > <td>"+id_don+"</td> <td>"+nom_don+"</td> <td>"+prenom_don+"</td><td>"+cin_don+"</td><td>"+type_don+"</td><td>"+taille+"</td><td>"+date_v+"</td> <td>"+quantite+"</td></tr>";
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
           "<body bgcolor=#ffffff link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
           "<center> <H1>Liste Des dons </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

       // headers
       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
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

void MainWindow::on_pushButton_16_pressed()
{
      QSslSocket socket;
    QString message = ui->lineEdit_4->text();
    if (!message.isEmpty())
    {
      message += '\n';
      socket.write(message.toLocal8Bit().constData());
      ui->lineEdit_4->clear();
    }
}

void MainWindow::on_pushButton_9_pressed()
{
      QSslSocket socket;
    ui->pushButton_9->setEnabled(false);

    if (socket.state() == QAbstractSocket::UnconnectedState)
    {
      // Initiate an SSL connection to the chat server.
      socket.connectToHostEncrypted(ui->lineEdit_5->text(), ui->spinBox_3->value());
    }
    else
    {
      socket.close();
    }
}

void MainWindow::connectedToServer()
{
  ui->pushButton_9->setText("Disconnect");
  ui->pushButton_9->setEnabled(true);
  ui->lineEdit_4->setEnabled(true);
  ui->pushButton_16->setEnabled(true);
  ui->textEdit->clear();
}

// Process SSL errors
void MainWindow::sslErrors(const QList<QSslError> &errors)
{
     QSslSocket socket;
  QString errorStrings;
  foreach (QSslError error, errors)
  {
    errorStrings += error.errorString();
    if (error != errors.last())
    {
      errorStrings += '\n';
    }
  }

  // Display error details to user and ask for permission to proceed anyway
  QMessageBox::StandardButton result = QMessageBox::question(this, "SSL Errors",
    QString("The following errors were encountered while negotiating the SSL connection:\n\n%1\n\nProceed anyway?").arg(errorStrings),
    QMessageBox::Yes|QMessageBox::No);
  if (result == QMessageBox::Yes)
  {
    socket.ignoreSslErrors();
  }
}

void MainWindow::receiveMessage()
{
     QSslSocket socket;
  if (socket.canReadLine())
  {
    ui->textEdit->append(QString("[%1] %2")
                                    .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz ap"))
                                    .arg(socket.readLine().constData()));
  }
}

void MainWindow::connectionClosed()
{
  ui->pushButton_9->setText("Connect");
  ui->pushButton_9->setEnabled(true);
  ui->lineEdit_4->setEnabled(false);
  ui->pushButton_16->setEnabled(false);
}

void MainWindow::socketError()
{
     QSslSocket socket;
  ui->textEdit->setText(QString("Socket Error: %1").arg(socket.errorString()));
  if (socket.state() != QAbstractSocket::ConnectedState)
  {
    connectionClosed();
  }
  socket.close();
}


