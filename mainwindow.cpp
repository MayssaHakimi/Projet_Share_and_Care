#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherent.h"
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPdfWriter>
#include <QPrinter>
#include <QPainter>
#include<QFileDialog>
#include <QtCore/QDebug>
#include <QVBoxLayout>
#include <QtGui>
#include<QInputDialog>
#include "qrcode.h"
#include "authenticator.h"
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
//#include "smtp.cpp"
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
#include "beneficiaire.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QLoggingCategory>
#include <QDateTime>
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
#include "gestionlivraison.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>
#include <QIntValidator>
#include <QQuickItem>
#include <QtPositioning/QGeoPositionInfoSource>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QtCharts>
#include <QSqlError>
#include"arduino.h"
#include"arduinodon.h"
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
#include<QMediaPlayer>
#include<QVideoWidget>
using namespace qrcodegen ;
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);


    QIcon iconx("C:/imageedit_1_4293195545.png"); // Replace ":/images/logo.png" with the path to your logo image
        setWindowIcon(iconx);


    //partie arduino
       /*int ret=Ar.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< Ar.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<Ar.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }*/

/////////////////////AMIN //////////////////////////////////////


       //le slot update_label suite à la reception du signal readyRead (reception des données).

            ui->lineEdit_id->setValidator(new QIntValidator(0, 99999999, this));
            ui->lineEdit_cin->setValidator(new QIntValidator(0, 99999999, this));
            ui->lineEdit_tel->setValidator(new QIntValidator(10000000, 99999999, this));
            ui->tab_aff->setModel(Bo.afficher());
//////////////////////////////////////////////////////////////////////////
///
///
/////////////////////////////////LOUAY////////////////////////////////////
  l = Gestionlivraison();
                  //map
                  ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
                  ui->quickWidget->show();
                //map end

                //calendar
                // Créer un QCalendarWidget et l'ajouter à l'interface utilisateur
                calendarWidget = new QCalendarWidget(this);


                // Connecter le signal selectionChanged() de QCalendarWidget au slot ajouterEvenement()
                connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(ajouterEvenement()));
                connect(ui->statistique, &QPushButton::clicked, this, &MainWindow::on_statistique_clicked);
            //arduino
                Adon.connect_arduino(); // se connecter à la carte arduino
                Adon.write_to_arduino("6");


            //l'affichage
                ui->tab_liv1->setModel(l.afficher());

            Gestionlivraison Gestionlivraison;
             QSqlQueryModel * model = Gestionlivraison.trie();
            ui->tab_liv1->setModel(model);
             QObject::connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);

            // lena zedt validator

            ui->cin_liv->setValidator(new QIntValidator(0, 99999999, this));
            ui->telephone->setValidator(new QIntValidator(0, 99999999, this));
            ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));

            //lina youfa
/////////////////////////////////////////////////////////
            ////////////////////:::yosr//////////////////////////////
            ///
            ///
            ///
            ///
            ///
            //////////////////////////////////////////////
            ///
            ///
            //arduino
                int r=Adon.connect_arduino(); // lancer la connexion à arduino
                switch(r){
                case(0):qDebug()<< "arduino is available and connected to : "<< Adon.getarduino_port_name();
                    break;
                case(1):qDebug() << "arduino is available but not connected to :" <<Adon.getarduino_port_name();
                   break;
                case(-1):qDebug() << "arduino is not available";
                }
                 QObject::connect(Adon.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
            ///
                 ui->lineEdit_13_don->setPlaceholderText("Nom du donateur / Type de don");
                ui->lineEdit_12_don->setValidator(new QIntValidator(0,999999999,this));
                ui->tab_affiche_2_don->setModel(Do.afficher_don());

            //controle de vetement
                 ui->comboBox_5_don->addItem("Vetement");
                    ui-> comboBox_5_don->addItem("Nourriture");
                 QObject::connect(ui->comboBox_5_don, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), [=](const QString &text) {
                         if (text == "Vetement") {
                             ui->dateEdit_2_don->setDisabled(true);
                         } else {
                            ui->dateEdit_2_don->setEnabled(true);
                         }
                     });
             //controle de taille
                 QObject::connect(ui->comboBox_5_don, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), [=](const QString &text) {
                         if (text == "Nourriture") {
                             ui->comboBox_6_don->setDisabled(true);
                         } else {
                            ui->comboBox_6_don->setEnabled(true);
                         }
                     });

                      //controle de nom
                     QRegExpValidator *validator = new QRegExpValidator(QRegExp("[A-Za-z ]+"),ui->lineEdit_don); // Création du validateur
                     ui->lineEdit_don->setValidator(validator);
                      //controle de prenom
                      QRegExpValidator(QRegExp("[A-Za-z ]+"),ui->lineEdit_11_don); // Création du validateur
                     ui->lineEdit_11_don->setValidator(validator);







            QSqlQuery query;
            query.exec("SELECT id_don FROM DONS");

            while (query.next()) {
                QString id_don = query.value(0).toString();
                ui->comboBox_7_don->addItem(id_don);

            }


            connect(ui->comboBox_7_don, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));
            ui->lineEdit_11_don->clear();;
            ui->lineEdit_don->clear();;
            ui->lineEdit_12_don->clear();;
            ui->dateEdit_2_don->clear();;
            ui->spinBox_don->clear();;
            ui->spinBox_2_don->clear();

            statistique_don();
            // chat

            ui->lineEdit_14_don->setFocusPolicy(Qt::StrongFocus);
            ui->textEdit_2_don->setFocusPolicy(Qt::NoFocus);
            ui->textEdit_2_don->setReadOnly(true);
            ui->listWidget->setFocusPolicy(Qt::NoFocus);

            connect(ui->lineEdit_14_don, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
            connect(ui->lineEdit_14_don, SIGNAL(returnPressed()), this, SLOT(returnPressed()));

            ui->lineEdit->setFocusPolicy(Qt::StrongFocus);
            ui->textEdit_2_adh->setFocusPolicy(Qt::NoFocus);
            ui->textEdit_2_adh->setReadOnly(true);
            ui->listWidget_2->setFocusPolicy(Qt::NoFocus);

            connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
            connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
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

/////////////////////////////////////////////////////////////////////////::::::::::::

    //controle de saisir pour id
    ui->lineEdit_4->setValidator(new QIntValidator(1,99999999,this));
    //controle de saisir pour nom

    QRegExpValidator *validator0 = new QRegExpValidator(QRegExp("[A-Za-z ]+"),ui->lineEdit_8);
    ui->lineEdit_8->setValidator(validator0);
    //controle de saisir pour prenom

    QRegExpValidator *validator1 = new QRegExpValidator(QRegExp("[A-Za-z ]+"),ui->lineEdit_6);
    ui->lineEdit_6->setValidator(validator1);

//controle de saisir pour cin
     ui->lineEdit_7->setValidator(new QIntValidator(1,99999999,this));


     ui->tableView_2->setModel(Adh.afficher_adh());
    on_pushButton_14_clicked();
    on_pushButton_15_clicked();

    ui->lineEdit_9->setEchoMode(QLineEdit::Password);
          ui->lineEdit_9->show();
          ui->lineEdit_2->setEchoMode(QLineEdit::Password);
                ui->lineEdit_2->show();
    //pour recupérer id

    query.exec("select id_adh from adherent");

    while (query.next()) {
        QString id_adh = query.value(0).toString();
        ui->comboBox_3->addItem(id_adh);
                 ui->comboBox_4->addItem(id_adh);}
    connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));
    connect(ui->comboBox_4, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_4_currentIndexChanged(const QString&)));

    ui->lineEdit_8->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_10->clear();

     //statistique


    //![1]
        QPieSeries *series = new QPieSeries();

        series->setHoleSize(0.40);
        series->append("RH ", Adh.RH());
        //QPieSlice *slice =
        series->append("RRB", Adh.RRB());
         series->append("DCF", Adh.DCF());
          series->append("RL", Adh.RL());
           series->append("RE", Adh.RE());
        //slice->setExploded();
        //slice->setLabelVisible();

    //![1]

    //![2]
        QChartView *chartView = new QChartView();
      chartView->setRenderHint(QPainter::Antialiasing);
        chartView->chart()->setTitle("Statistique des adhérents par fonction");
        chartView->chart()->addSeries(series);
        chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
        chartView->chart()->setTheme(QChart::ChartThemeBrownSand);
        chartView->chart()->legend()->setFont(QFont("Times New Roman", 12));
    //![2]

 //![3]

                 //chartView->setRenderHint(QPainter::Antialiasing);

                // ui->frame->setLayout(new QVBoxLayout);
                                // ui->frame->layout()->addWidget(chartView);

//ui->frame->resize(500,400);
QGridLayout *mainLayout = new QGridLayout(ui->frame);

                  mainLayout->addWidget(chartView, 1, 1);

                 //  ui->frame->setLayout(mainLayout);
                 chartView->setMinimumSize(681, 331);
                 chartView->resize(681, 331);
                 chartView->setParent(ui->frame);

chartView->show();
 //![3]

}


MainWindow::~MainWindow()
{
    QSslSocket socket;
       if (socket.isOpen())
       {
         socket.close();
       }
    delete ui;
       // delete player1; // Détruire l'objet QMediaPlayer
         // delete vid; // Détruire l'objet QVideoWidget
}


void MainWindow::on_ajouter_button_clicked()
{

    int id_adh =ui->lineEdit_4->text().toInt();
   QString nom_adh=ui->lineEdit_8->text();
   QString prenom_adh=ui->lineEdit_6->text();
   QString  cin_adh =ui->lineEdit_7->text();
   QString identifiant=ui->comboBox_2->currentText();
   QString mdp_adh=ui->lineEdit_9->text();
   QString fct_adh=ui->comboBox->currentText();
   QString date_emb=ui->dateEdit->text();
   Adherent A(id_adh ,nom_adh , prenom_adh, cin_adh,identifiant , mdp_adh, date_emb ,fct_adh);
   bool test =A.ajouter_adh();

   if(test)
   {
       ui->comboBox_3->clear();
       ui->comboBox_4->clear();
       QSqlQuery query;
       query.exec("select id_adh from adherent");

       while (query.next()) {
           QString id_adh = query.value(0).toString();
           ui->comboBox_3->addItem(id_adh);}
       connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));
       ui->tableView_2->setModel(Adh.afficher_adh());

       ui->lineEdit_8->clear();
       ui->lineEdit_6->clear();
       ui->lineEdit_7->clear();
       ui->lineEdit_9->clear();
       ui->lineEdit_4->clear();
        QMessageBox::information(nullptr, QObject::tr("Bien"), QObject::tr("Ajout effectué \n" "Cliquez sur Cancel pour quitter"),QMessageBox::Cancel  );
   }
else

       QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Ajout non effectué \n" "Cliquez sur Cancel pour quitter"),QMessageBox::Cancel  );

}


void MainWindow::on_pushButton_12_clicked()
{
    int id_adh =ui->comboBox_3->currentText().toInt();
 bool test =Adh.supprimer_adh(id_adh);

    if(test)
    {
        ui->comboBox_3->clear();
        ui->comboBox_4->clear();

        QSqlQuery query;
        query.exec("select id_adh from adherent");

        while (query.next()) {
            QString id_adh = query.value(0).toString();
            ui->comboBox_3->addItem(id_adh);}
        connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));
        ui->tableView_2->setModel(Adh.afficher_adh());

        ui->lineEdit_8->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_4->clear();
        QMessageBox::information(nullptr, QObject::tr("Bien"), QObject::tr("Suppression effectué \n" "Cliquez sur Cancel pour quitter"),QMessageBox::Cancel  );
    }
 else

        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Suppression non effectué \n" "Cliquez sur Cancel pour quitter"),QMessageBox::Cancel  );

}


void MainWindow::on_pushButton_11_clicked()
{
    QString nom_adh=ui->lineEdit_8->text();
    QString prenom_adh=ui->lineEdit_6->text();
   QString cin_adh=ui->lineEdit_7->text();
    QString identifiant=ui->comboBox_2->currentText();
    QString mdp_adh=ui->lineEdit_9->text();

    QString fct_adh=ui->comboBox->currentText();
    QString date_emb=ui->dateEdit->text();
    int id_adh =ui->comboBox_3->currentText().toInt();
    Adherent A(id_adh,nom_adh , prenom_adh, cin_adh,identifiant , mdp_adh, date_emb ,fct_adh);

    bool test =A.modifier_adh(id_adh);

    if(test)
    {
        ui->comboBox_3->clear();
        ui->comboBox_4->clear();

        QSqlQuery query;
        query.exec("select id_adh from adherent");

        while (query.next()) {
            QString id_adh = query.value(0).toString();
            ui->comboBox_3->addItem(id_adh);}
        connect(ui->comboBox_3, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));
        ui->tableView_2->setModel(Adh.afficher_adh());

        ui->lineEdit_8->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_4->clear();
        QMessageBox::information(nullptr, QObject::tr("Bien"), QObject::tr("Modificaion effectué \n" "Cliquez sur Cancel pour quitter"),QMessageBox::Cancel  );
    }
 else

        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Modification non effectué \n" "Cliquez sur Cancel pour quitter"),QMessageBox::Cancel  );

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->tableView_2->setModel(Adh.tri_adh_asc());

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->tableView_2->setModel(Adh.tri_adh_desc());

}

void MainWindow::on_pushButton_8_clicked()
{

    ui->tableView_2->setModel(Adh.recherche_adh(ui->lineEdit_23->text()));


}

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &id_adh)
{
     QSqlQuery query;

    query.prepare("select nom_adh,prenom_adh,cin_adh,identifiant,date_emb,fct_adh,mdp_adh from adherent where id_adh=:id_adh");
        query.bindValue(":id_adh", id_adh);

        if (query.exec() && query.next())
        {
            QString nom_adh = query.value(0).toString();
            QString prenom_adh = query.value(1).toString();
            QString cin_adh = query.value(2).toString();
            QString identifiant = query.value(3).toString();
            QString date_emb = query.value(4).toString();
            QString fct_adh = query.value(5).toString();
         QString mdp_adh = query.value(6).toString();
         QString id_adh = query.value(7).toString();


            ui->lineEdit_8->setText(nom_adh);
            ui->lineEdit_6->setText(prenom_adh);
            ui->lineEdit_7->setText(cin_adh);
            ui->comboBox->setCurrentText(fct_adh);
            ui->comboBox_2->setCurrentText(identifiant);
            ui->dateEdit->setDate(QDate::fromString(date_emb, "yyyy-MM-dd"));
            ui->lineEdit_9->setText(mdp_adh);
            ui->lineEdit_4->text().toInt();

        }
}

void MainWindow::on_comboBox_4_currentIndexChanged(const QString &id_adh)
{
    QSqlQuery query;

   query.prepare("select nom_adh,prenom_adh from adherent where id_adh=:id_adh");
       query.bindValue(":id_adh", id_adh);

       if (query.exec() && query.next())
       {
           QString nom_adh = query.value(0).toString();
           QString prenom_adh = query.value(1).toString();


           ui->lineEdit_5->setText(nom_adh);
           ui->lineEdit_10->setText(prenom_adh);
          QString nom = ui->lineEdit_5->text();
          QString prenom = ui->lineEdit_10->text();
          }

}


void MainWindow::on_pushButton_13_clicked()
{
MainWindow::getNomPrenomFromComboBox();
QString nom = ui->lineEdit_5->text();
   QString prenom = ui->lineEdit_10->text();
    QString html = " </thead><tbody > ";



html+="</tbody> ";
QString strStream;
QTextStream out(&strStream);


out <<  "<html>\n"
    "<head>\n"

    "<meta Content=\"Text/html; charset=Windows-1251\">\n"




    <<  QString("<title>%1</title>\n").arg("strTitle")
    <<  "</head>\n"
   "<body bgcolor=#dfabc9 link=#5000A0>\n"

 //logo   //     "<align='right'> " << datefich << "</align>"
    "<center>  <img src='C:/imageedit_1_4293195545.png'></img><h1>Remerciement</h1>"
                                                                     "<h2>Ms/Mme :" + nom + " " + prenom + "</h2>"
                                                                     "<h2>Nous voulons vous remercier pour votre implication au sein de notre association. Vous jouez un rôle primordial dans notre succès et nous en sommes très reconnaissants. Encore une fois, merci de votre contribution !</h2>";



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


void MainWindow::on_pushButton_clicked()
{
    Authenticator auth;

    QString password = ui->lineEdit_2->text();
    QString ident = ui->lineEdit_3->text();

 auth.m_username=Adh.authen_nom(password);
 auth.m_password=Adh.authen_mdp(password);
        // Vérification de l'authentification

if (ident == auth.m_username && password == auth.m_password ) {
    //QMessageBox::information(this, "Authentification réussie", "Vous êtes connecté.");
    if (ident == "ADH140")
     {ui->stackedWidget->setCurrentIndex(13);}
   else  if (ident == "BEN110")
     {ui->stackedWidget->setCurrentIndex(0);}
    else if (ident == "DON147")
     {ui->stackedWidget->setCurrentIndex(1);}
    else if (ident == "LIV180")
     {ui->stackedWidget->setCurrentIndex(2);}
    /*else if (ident == "EVE010")
     {ui->stackedWidget->setCurrentIndex(8);}*/


} /*else {
    // Authentification échouée
    QMessageBox::warning(this, "Authentification échouée", "Nom d'utilisateur ou mot de passe invalide.");
}*/


}

void MainWindow::on_pushButton_9_clicked()
{
    int tabeq= ui->tableView_2->currentIndex().row();
       QVariant idd= ui->tableView_2->model()->data( ui->tableView_2->model()->index(tabeq,0));
       QString numero= idd.toString();
       QSqlQuery qry;
       qry.prepare("select id_adh ,nom_adh ,identifiant ,mdp_adh from adherent where id_adh=:id_adh");
       qry.bindValue(":id_adh",numero);
       qry.exec();
       QString  Nom_Adherent,Identifiant_Adherent,Mdp_Adherent;

       while(qry.next())
       {
           numero=qry.value(0).toString();
           Nom_Adherent=qry.value(1).toString();
           Identifiant_Adherent=qry.value(2).toString();
           Mdp_Adherent=qry.value(3).toString();
            // Quantiter=qry.value(4).toString();
       }
       numero=QString(numero);
        numero = "id_adh:" + numero + ";nom_adh:" + Nom_Adherent + ";identifiant:" + Identifiant_Adherent + ";mdp_adh:" + Mdp_Adherent;

       QrCode qr = QrCode::encodeText(numero.toUtf8().constData(), QrCode::Ecc::HIGH);

       // Read the black & white pixels
       QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
       for (int y = 0; y < qr.getSize(); y++)
       {
       for (int x = 0; x < qr.getSize(); x++)
       {
       int color = qr.getModule(x, y);  // 0 for white, 1 for black

       // You need to modify this part
       if(color==0)
          im.setPixel(x, y,qRgb(254, 254, 254));
       else
          im.setPixel(x, y,qRgb(0, 0, 0));
       }
       }
       im=im.scaled(200,200);
       ui->Qrcode->setPixmap(QPixmap::fromImage(im));

}

void MainWindow::on_pushButton_10_clicked()
{
    //statistique


   //![1]
       QPieSeries *series = new QPieSeries();

       series->setHoleSize(0.40);
       series->append("RH ", Adh.RH());
       //QPieSlice *slice =
       series->append("RRB", Adh.RRB());
        series->append("DCF", Adh.DCF());
         series->append("RL", Adh.RL());
          series->append("RE", Adh.RE());
       //slice->setExploded();
       //slice->setLabelVisible();

   //![1]

   //![2]
       QChartView *chartView = new QChartView();
     chartView->setRenderHint(QPainter::Antialiasing);
       chartView->chart()->setTitle("Statistique des adhérents par fonction");
       chartView->chart()->addSeries(series);
       chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
       chartView->chart()->setTheme(QChart::ChartThemeBrownSand);
       chartView->chart()->legend()->setFont(QFont("Times New Roman", 12));
   //![2]

//![3]

                //chartView->setRenderHint(QPainter::Antialiasing);

               // ui->frame->setLayout(new QVBoxLayout);
                               // ui->frame->layout()->addWidget(chartView);

//ui->frame->resize(500,400);
QGridLayout *mainLayout = new QGridLayout(ui->frame);

                 mainLayout->addWidget(chartView, 1, 1);

                //  ui->frame->setLayout(mainLayout);
                chartView->setMinimumSize(501, 401);
                chartView->resize(501, 401);
                chartView->setParent(ui->frame);

chartView->show();
//![3]

}
void MainWindow::getNomPrenomFromComboBox()
{
    // Get the current index value of the combo box
    int index = ui->comboBox_4->currentIndex();

    // Get the ID value associated with the current index
    QString id_adh = ui->comboBox_4->itemData(index).toString();

    QSqlQuery query;
    query.prepare("select nom_adh, prenom_adh from adherent where id_adh = :id_adh");
    query.bindValue(":id_adh", id_adh);

    if (query.exec() && query.next())
    {
        QString nom_adh = query.value(0).toString();
        QString prenom_adh = query.value(1).toString();

        // Set the nom and prenom values to the corresponding line edits
        ui->lineEdit_5->setText(nom_adh);
        ui->lineEdit_10->setText(prenom_adh);

        // Get the text values of the line edits
        QString nom = ui->lineEdit_5->text();
        QString prenom = ui->lineEdit_10->text();
    }
}


void MainWindow::on_pushButton_7_clicked()
{

   ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_22_clicked()
{
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_23_clicked()
{
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_25_clicked()
{
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_24_clicked()
{
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}
void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}
void MainWindow::on_pushButton_21_clicked()
{

        QSqlQuery query;
        QString rfid = "";
  //      rfid = QString(Ar.getserial()->readLine()).trimmed();
        query.prepare("SELECT * from adherent where rfid=:rfid ");
        query.bindValue(":rfid",rfid);
        qDebug()<<rfid;

        qDebug() << query.boundValues();
        if(query.exec())
            {
                if(query.next())
                {
                        QMessageBox::information(nullptr, QObject::tr("Access reussis OK"),
                                              QObject::tr("Access Réussis OK\n"
                                                          "Click Cancel to exit."),QMessageBox::Cancel);
                        if(rfid=="1476319173")
                        {
                        ui->stackedWidget->setCurrentIndex(4);}
                        if(rfid=="234457899")
                        {
                        ui->stackedWidget->setCurrentIndex(5);}
                        if(rfid=="20813217237")
                        {
                        ui->stackedWidget->setCurrentIndex(6);}
                        if(rfid=="13116814729")
                        {
                        ui->stackedWidget->setCurrentIndex(7);}


                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                          QObject::tr("Accéss Interdit\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                      QObject::tr("Accéss non Réussis\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);

            }



}

/////////////////////////////AMIN/////////////////////////////////////////
void MainWindow::on_pushButton_ajou_clicked()
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

        QFile file ("C:/Users/hakimi mayssa/Desktop/other - Copy/hist.txt");

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
            QFile file ("C:/Users/hakimi mayssa/Desktop/other - Copy/hist.txt");

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

        QFile file ("C:/Users/hakimi mayssa/Desktop/other - Copy/hist.txt");

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
    QFile file ("C:/Users/hakimi mayssa/Desktop/other - Copy/hist.txt");

       if (!file.open(QFile::ReadOnly  | QFile::Text))
           {
           QMessageBox::warning(this, "title","file  not open");
           }
       QTextStream in (&file);
       QString  text  = in.readAll();
       ui->plainTextEdit_ben->setPlainText(text);

       file.close();
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
           Adon.write_to_arduino("7");//1
       }
       else
       {
           // Password does not exist in the database
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("mot de passe invalide"));
           Adon.write_to_arduino("8");//0
       }
}



///////////////////////////LOUAY/////////////////////
void MainWindow::on_ajouter_clicked()
{
    int ID_LIVRAISON =ui->le_id->text().toInt();
    QString nom_liv=ui->nom_liv->text();
    QString prenom_liv=ui->prenom_liv->text();
    QString Date_liv_str =ui->Date_liv->text();
    //QString Date_liv_str = ui->Date_liv->text();
     QDate Date_liv = QDate::fromString(Date_liv_str, "dd/MM/yyyy");
     QString cin_liv =ui->cin_liv->text();
    QString Adresse_liv =ui->Adresse_liv->text();
     int Objet =ui->Objet->text().toInt();
    //QString Objet =ui->Objet->text();
    QString telephone =ui->telephone->text();
    float Latitude = ui->Latitude->text().toFloat();
    float Longitude = ui->Longitude->text().toFloat();
    QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addMarker",
                              Q_ARG(QVariant, Latitude),
                              Q_ARG(QVariant, Longitude));


 l = Gestionlivraison(ID_LIVRAISON ,cin_liv, nom_liv , prenom_liv , Date_liv, Adresse_liv, Objet ,  telephone ,Latitude, Longitude);
bool testaj=l.ajouter();

if (testaj)
{
   // refresh
    ui->tab_liv1->setModel(l.afficher());

  QMessageBox::information(nullptr , QObject::tr("ok"),
          QObject::tr("ajout avec succée"
                    "" "click canal to exit."),QMessageBox::Cancel);
  afficherLivraisonCalendier();

}else
    QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("ajout echec "
                                      "click cancel to exit "), QMessageBox::Cancel);

}

void MainWindow::on_Supprimer_clicked()

{
    int id_livraison = ui->ID_LIVRAISON->text().toInt();

    //Gestionlivraison l;
    if(l.existe(id_livraison))
    {
        l.setID_LIVRAISON(id_livraison);
        bool test = l.supprimer(l.getID_LIVRAISON());
        QMessageBox msgbox;
        if (test)
        {
            // refresh
            ui->tab_liv1->setModel(l.afficher( ));
            msgbox.setText("supprimer avec succée");
        }
        else
        {
            msgbox.setText("supprimer failed");
        }
        msgbox.exec();
    }
    else
    {
        QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("ID_LIVRAISON n'existe pas"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Modifier_clicked()
{
    int ID_LIVRAISON = ui->le_id->text().toInt();
    float Latitude = ui->Latitude->text().toFloat();
    float Longitude = ui->Longitude->text().toFloat();

   // Gestionlivraison l;

    if(l.existe(ID_LIVRAISON))
    {
        QString cin_liv = ui->le_cin->text();
        QString nom_liv = ui->le_nom->text();
        QString prenom_liv = ui->le_prenom->text();
        QString telephone = ui->le_telephone->text();
        QString Adresse_liv = ui->le_adresse->text();
        int Objet =ui->Objet->text().toInt();
       //  QString Objet = ui->le_objet->text();
        //QString Date_liv = ui->Date_liv->text();
        QString Date_liv_str = ui->Date_liv->text();
         QDate Date_liv = QDate::fromString(Date_liv_str, "dd/MM/yyyy");
        Gestionlivraison l(ID_LIVRAISON ,cin_liv, nom_liv , prenom_liv , Date_liv, Adresse_liv, Objet ,  telephone ,Latitude, Longitude);
        bool test2 = l.modifier(ID_LIVRAISON);
        if (test2)
        {
            // refresh
            ui->tab_liv1->setModel(l.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                      QObject::tr("modififier avec succée"
                                                  "" "click canal to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                    QObject::tr("modififier echec "
                                                "click cancel to exit "), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("ID_LIVRAISON n'existe pas"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Recherche_clicked()
{
    QString motCle = ui->ID_LIVRAISON->text();
     /* l.rechercher(motCle);
      ui->tab_liv->setModel(l.afficher());
*/
    ui->tab_liv1->setModel(l.rechercher(motCle));
}

/*void MainWindow::on_trie_clicked()
{

    ui->tab_liv->setModel(l.trie( tab_liv,  taille_tab_liv));
    // refresh
    ui->tab_liv->setModel(l.afficher( ));
}
*/
/*void MainWindow::on_statistique_clicked()
{
    // Récupération de la date saisie par l'utilisateur
    QDate date_liv = ui->Date_liv->date();

    // Appel de la fonction de calcul de statistiques
    int nombreLivraisons = statistique(date_liv);

    // Affichage du résultat
    if(nombreLivraisons != -1)
    {
        ui->statistique->setText(QString("Nombre de livraisons pour le %1 : %2").arg(date_liv.toString("dd/MM/yyyy")).arg(nombreLivraisons));
    }
    else
    {
        ui->statistique->setText("Une erreur est survenue lors du calcul des statistiques.");
    }
}

int MainWindow::statistique(QDate date_liv)
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
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                QObject::tr("modififier echec "
                                            "click cancel to exit "), QMessageBox::Cancel);
    }
}*/

void MainWindow::on_trie_clicked()
{
/*
    QSqlQueryModel *model = l.trie();
    ui->tab_liv->setModel(model);
    ui->tab_liv->show();
    connect(ui->trie, &QPushButton::clicked, this, &MainWindow::on_trie_clicked);
    // refresh
    ui->tab_liv->setModel(l.afficher());*/
    // refresh
    ui->tab_liv1->setModel(l.afficher());
    QSqlQueryModel *sorteModel = l.trie();
    ui->tab_liv1->setModel(sorteModel);

    //Gestionlivraison Gestionlivraison;
    //Gestionlivraison.trie();


}
void MainWindow::on_pdf_clicked()
{
    Gestionlivraison Gestionlivraison;
    Gestionlivraison.PDF();
}

void MainWindow::afficherLivraisonCalendier()
{
    QList<QDate> livraisons = l.getLivraisonsCalendrier();
    qDebug() << "Taille de la liste de livraisons : " << livraisons.size();
    for(int i=0; i<livraisons.size(); i++)
    {
        QDate date_liv = livraisons.at(i);
        qDebug() << "Date de livraison : " << date_liv.toString("dd/MM/yyyy");

        // Récupération de l'adresse de la base de données
        QSqlQuery configQuery;
        configQuery.prepare("SELECT Adresse_liv FROM MAYSSA.LIVRAISON WHERE ID_LIVRAISON = 1");
        if(configQuery.exec() && configQuery.next())
        {
            QString Adresse_liv = configQuery.value(0).toString();
            QString message = "Vous avez une livraison aujourd'hui à l'adresse " + Adresse_liv;
                                  QTextCharFormat format;
            format.setBackground(Qt::green);
            format.setToolTip(message);
            ui->calendarWidget->setDateTextFormat(date_liv, format);
        }
        else
        {
            qDebug() << "Error executing query: " << configQuery.lastError().text();
        }
    }
}

void MainWindow::on_statistique_clicked()
{
    // Création de la série de données
    QBarSeries *series = new QBarSeries();

    // Récupération des dates de livraison de la base de données
    QSqlQuery query("SELECT date_liv FROM livraison");

    // Initialisation des compteurs
    int nb_liv = 0;
    QDate semaine_precedente = QDate::currentDate().addDays(-1);
    QDate semaine_actuelle;

    // Parcours des enregistrements de la base de données
    while (query.next()) {
        // Récupération de la date de livraison
        QDateTime date_liv = query.value(0).toDateTime();

        // Si la date de livraison est dans la semaine actuelle
        semaine_actuelle = date_liv.date();
        if (semaine_actuelle > semaine_precedente && semaine_actuelle <= QDate::currentDate()) {
            // Incrémentation du compteur
            nb_liv++;
        } else {
            // Ajout du compteur à la série de données pour la semaine précédente
            QBarSet *set = new QBarSet(QString("Semaine %1").arg(semaine_precedente.toString("ww")));
            *set << nb_liv;
            series->append(set);

            // Réinitialisation du compteur et de la semaine précédente
            nb_liv = 1;
            semaine_precedente = semaine_actuelle;
        }
    }

    // Ajout du compteur à la série de données pour la dernière semaine
    QBarSet *set = new QBarSet(QString("Semaine %1").arg(semaine_precedente.toString("ww")));
    *set << nb_liv;
    series->append(set);

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre de livraisons par semaine");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Configuration de l'axe X
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configuration de l'axe Y
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Configuration de la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Affichage du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000, 500);
    chartView->show();
}



/*void MainWindow::on_arduino_clicked()
{
    QSqlQuery query;
    int ID_LIVRAISON=ui->ID_LIVRAISON->text().toInt();
    query.prepare("SELECT * FROM LOLITA.LIVRAISON WHERE ID_LIVRAISON = :ID_LIVRAISON");
    query.bindValue(":ID_LIVRAISON", ID_LIVRAISON);
    if (!query.exec())
    {
        qWarning() << "Failed to execute query.";

    }

    // Check if the query returned any rows
    if (query.next())
    {
        // Password exists in the database
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("existe"));
        A.write_to_arduino("1");
    }
    else
    {
        // Password does not exist in the database
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("n'existe pas"));
        A.write_to_arduino("0");
    }
}

*/



void MainWindow::on_arduino_clicked()
{
    QSqlQuery query;
    int ID_LIVRAISON = ui->ID_LIVRAISON->text().toInt();
    query.prepare("SELECT Objet FROM MAYSSA.LIVRAISON WHERE ID_LIVRAISON = :ID_LIVRAISON");
    query.bindValue(":ID_LIVRAISON", ID_LIVRAISON);

    if (!query.exec()) {
        qWarning() << "Failed to execute query.";
    }

    if (query.next()) {
        int Objet = query.value(0).toInt();
        if ( Objet < 20) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Quantité inférieure à 20"));
            Adon.write_to_arduino("5");//0

        }
        else {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Quantité supérieure ou égale à 20"));
            Adon.write_to_arduino("6");//1
        }
    }
    else {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("ID_LIVRAISON non trouvé dans la base de données"));
    }
}

/////////////////////////:::YOSR/////////////////////////////////

void MainWindow::appendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;

    QTextCursor cursor(ui->textEdit_2_don->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, tableFormat);
    table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
    table->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar = ui->textEdit_2_don->verticalScrollBar();
    bar->setValue(bar->maximum());

    QTextCursor cursor1(ui->textEdit_2_adh->textCursor());
    cursor1.movePosition(QTextCursor::End);
    QTextTable *table1 = cursor1.insertTable(1, 2, tableFormat);
    table1->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
    table1->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar1 = ui->textEdit_2_adh->verticalScrollBar();
    bar1->setValue(bar1->maximum());
}



void MainWindow::returnPressed()
{
    QString text = ui->lineEdit_14_don->text();
     QString text1 = ui->lineEdit->text();
    if (text.isEmpty())
        return;

    if ((text.startsWith(QChar('/')))||(text1.startsWith(QChar('/')))) {
        QColor color = ui->textEdit_2_don->textColor();
        ui->textEdit_2_don->setTextColor(Qt::red);
        ui->textEdit_2_don->append(tr("! Unknown command: %1")
                         .arg(text.left(text.indexOf(' '))));
        ui->textEdit_2_don->setTextColor(color);

        QColor color1 = ui->textEdit_2_adh->textColor();
        ui->textEdit_2_adh->setTextColor(Qt::red);
        ui->textEdit_2_adh->append(tr("! Unknown command: %1")
                         .arg(text1.left(text1.indexOf(' '))));
        ui->textEdit_2_adh->setTextColor(color1);
    } else {
        client.sendMessage(text);
        appendMessage(myNickName, text);
        client.sendMessage(text1);
        appendMessage(myNickName, text1);
    }

   ui->lineEdit_14_don->clear();
   ui->lineEdit->clear();

  /*   QString text1 = ui->lineEdit->text();
    if (text1.isEmpty())
        return;

    if (text1.startsWith(QChar('/'))) {
        QColor color1 = ui->textEdit_2_adh->textColor();
        ui->textEdit_2_adh->setTextColor(Qt::red);
        ui->textEdit_2_adh->append(tr("! Unknown command: %1")
                         .arg(text1.left(text1.indexOf(' '))));
        ui->textEdit_2_adh->setTextColor(color1);
    } else {
        client.sendMessage(text1);
        appendMessage(myNickName, text1);
    }

    ui->lineEdit->clear();*/
}



void MainWindow::newParticipant(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QColor color = ui->textEdit_2_don->textColor();
    ui->textEdit_2_don->setTextColor(Qt::gray);
    ui->textEdit_2_don->append(tr("* %1 a rejoint").arg(nick));
    ui->textEdit_2_don->setTextColor(color);
    ui->listWidget->addItem(nick);

    QColor color1 = ui->textEdit_2_adh->textColor();
    ui->textEdit_2_adh->setTextColor(Qt::gray);
    ui->textEdit_2_adh->append(tr("* %1 a rejoint").arg(nick));
    ui->textEdit_2_adh->setTextColor(color1);
    ui->listWidget_2->addItem(nick);
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
    QColor color = ui->textEdit_2_don->textColor();
    ui->textEdit_2_don->setTextColor(Qt::gray);
    ui->textEdit_2_don->append(tr("* %1 est parti").arg(nick));
    ui->textEdit_2_don->setTextColor(color);


    QList<QListWidgetItem *> items1 = ui->listWidget_2->findItems(nick,
                                                           Qt::MatchExactly);


    delete items.at(0);
    QColor color1 = ui->textEdit_2_adh->textColor();
    ui->textEdit_2_adh->setTextColor(Qt::gray);
    ui->textEdit_2_adh->append(tr("* %1 est parti").arg(nick));
    ui->textEdit_2_adh->setTextColor(color1);
}



void MainWindow::showInformation()
{
    if (ui->listWidget->count() == 1) {
        QMessageBox::information(this, tr("Chat"),
                                 tr("Lancez plusieurs instances de ce "
                                    " programme sur votre réseau local et "
                                    "Commencez à discuter !"));
    }

    if (ui->listWidget_2->count() == 1) {
        QMessageBox::information(this, tr("Chat"),
                                 tr("Lancez plusieurs instances de ce "
                                    " programme sur votre réseau local et "
                                    "Commencez à discuter !"));
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

        QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC3f9de0017be9564b86cb4664a10df6b1/Messages.json");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QUrlQuery params;
        params.addQueryItem("From", "+16073502295"); // votre numéro Twilio
       params.addQueryItem("MessagingServiceSid", "MG28d639f8911906c17008900052e0f474");
    int id_don=ui->comboBox_7_don->currentText().toInt();
    QString type_don=ui->comboBox_5_don->currentText();
    QString message = QString("Un don d'id %1 de type %2 a été supprimé").arg(id_don).arg(type_don);
        params.addQueryItem("To", "+21697336009"); // le numéro de téléphone du destinataire
        params.addQueryItem("Body", message);

        url.setQuery(params);
        QByteArray data = url.toEncoded(QUrl::RemoveFragment);

        request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg("AC3f9de0017be9564b86cb4664a10df6b1").arg("39cd530983202e8289aaaf16444c4951").toUtf8()).toBase64());
        QNetworkReply *reply = manager->post(request, data);

        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error: " << reply->errorString();
        }
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
                  QGridLayout *mainLayout = new QGridLayout(ui->frame_2_don);

                  mainLayout->addWidget(chartview, 1, 1);

                 //  ui->frame->setLayout(mainLayout);
                 chartview->setMinimumSize(681, 331);
                 chartview->resize(681, 331);
                 chartview->setParent(ui->frame_2_don);

chartview->show();





}





// arduino

void MainWindow::on_pushButton_32_don_clicked()
{
    int vet = Do.vetement();

        if (vet==0)
         {Adon.write_to_arduino("0");


        }
        else {Adon.write_to_arduino("1");

        }
}

void MainWindow::on_pushButton_33_don_clicked()
{
    int nourr = Do.nourriture();

        if (nourr==0)
         {Adon.write_to_arduino("2");}
        else Adon.write_to_arduino("3");
}

void MainWindow::on_pushButton_31_don_clicked()
{
    statistique_don();
}

void MainWindow::on_pushButton_28_don_clicked()
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

       const int rowCount = ui->tab_affiche_2_don->model()->rowCount();
       const int columnCount = ui->tab_affiche_2_don->model()->columnCount();

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
           if (!ui->tab_affiche_2_don->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tab_affiche_2_don->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++)
       {
           out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
           for (int column = 0; column < columnCount; column++)
           {
              if (!ui->tab_affiche_2_don->isColumnHidden(column))
               {
                   QString data = ui->tab_affiche_2_don->model()->data(ui->tab_affiche_2_don->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_27_don_clicked()
{
      ui->tab_affiche_2_don->setModel(Do.recherche_don(ui->lineEdit_13_don->text(),ui->lineEdit_13_don->text()));
}

void MainWindow::on_pushButton_29_don_clicked()
{
     ui->tab_affiche_2_don->setModel(Do.trieAsc());
}

void MainWindow::on_pushButton_30_don_clicked()
{
     ui->tab_affiche_2_don->setModel(Do.trieDesc());
}

void MainWindow::on_pushButton_19_don_clicked()
{

    int id_don=ui->spinBox_2_don->text().toInt();
   QString nom_don=ui->lineEdit_don->text();
   QString prenom_don=ui->lineEdit_11_don->text();
   QString cin_don=ui->lineEdit_12_don->text();
   QString type_don=ui->comboBox_5_don->currentText();
   QString taille=ui->comboBox_6_don->currentText();
   QString date_v=ui->dateEdit_2_don->text();
   int quantite=ui->spinBox_don->text().toInt();

   Don D (id_don,nom_don ,prenom_don , cin_don, type_don, taille, date_v, quantite);

   bool test=D.ajouter_don();


   if (test)
  {


       ui->comboBox_7_don->clear();

       QSqlQuery query;
       query.exec("SELECT id_don FROM DONS");

       while (query.next()) {
           QString id_don = query.value(0).toString();
           ui->comboBox_7_don->addItem(id_don);
       }

       connect(ui->comboBox_7_don, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

       ui->tab_affiche_2_don->setModel(Do.afficher_don());

       ui->lineEdit_11_don->clear();;
       ui->lineEdit_don->clear();;
       ui->lineEdit_12_don->clear();;
       ui->dateEdit_2_don->clear();;
       ui->spinBox_don->clear();;
       ui->spinBox_2_don->clear();

       QMessageBox::information(nullptr , QObject::tr("Bien") , QObject::tr("Ajout effectué"),QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr , QObject::tr("Erreur") , QObject::tr("Ajout n'est pas effectué "),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_20_don_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id_don FROM DONS");

    while (query.next()) {
        QString id_don = query.value(0).toString();
        ui->comboBox_7_don->addItem(id_don);
    }

    connect(ui->comboBox_7_don, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

     int id_don=ui->comboBox_7_don->currentText().toInt();
    bool test=Do.supprimer_don( id_don);



     if (test)
    {   send_sms();

         ui->tab_affiche_2_don->setModel(Do.afficher_don());

         ui->comboBox_7_don->clear();
         QSqlQuery query;
         query.exec("SELECT id_don FROM DONS");

         while (query.next()) {
             QString id_don = query.value(0).toString();
             ui->comboBox_7_don->addItem(id_don);
         }

         connect(ui->comboBox_7_don, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

         ui->lineEdit_11_don->clear();;
         ui->lineEdit_don->clear();;
         ui->lineEdit_12_don->clear();;
         ui->dateEdit_2_don->clear();;
         ui->spinBox_don->clear();;
         ui->spinBox_2_don->clear();




             QMessageBox::information(nullptr , QObject::tr("Bien") , QObject::tr("Suppression effectuée"),QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr , QObject::tr("Erreur") , QObject::tr("Suppression n'est pas effectuée "),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_26_don_clicked()
{


   QString nom_don=ui->lineEdit_don->text();
   QString prenom_don=ui->lineEdit_11_don->text();
   QString cin_don=ui->lineEdit_12_don->text();
   QString type_don=ui->comboBox_5_don->currentText();
   QString taille=ui->comboBox_6_don->currentText();
   QString date_v=ui->dateEdit_2_don->text();
   int quantite=ui->spinBox_don->text().toInt();
    int id_don=ui->comboBox_7_don->currentText().toInt();

    Don D (id_don,nom_don ,prenom_don , cin_don, type_don, taille, date_v, quantite);

    bool test=D.modifier_don(id_don);


    if (test)
   {   ui->tab_affiche_2_don->setModel(Do.afficher_don());
        ui->comboBox_3->clear();
        QSqlQuery query;
        query.exec("SELECT id_don FROM DONS");

        while (query.next()) {
            QString id_don = query.value(0).toString();
            ui->comboBox_7_don->addItem(id_don);
        }

        connect(ui->comboBox_7_don, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_3_currentIndexChanged(const QString&)));

        ui->lineEdit_11_don->clear();;
        ui->lineEdit_don->clear();;
        ui->lineEdit_12_don->clear();;
        ui->dateEdit_2_don->clear();;
        ui->spinBox_don->clear();;
        ui->spinBox_2_don->clear();

        QMessageBox::information(nullptr , QObject::tr("Bien") , QObject::tr("Modification effectuée"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr , QObject::tr("Erreur") , QObject::tr("Modification n'est pas effectuée "),QMessageBox::Cancel);
}

void MainWindow::on_comboBox_7_don_currentIndexChanged(const QString& id_don)
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

            ui->lineEdit_don->setText(nom_don);
            ui->lineEdit_11_don->setText(prenom_don);
            ui->lineEdit_12_don->setText(cin_don);
            ui->comboBox_5_don->setCurrentText(type_don);
            ui->comboBox_6_don->setCurrentText(taille);
            ui->dateEdit_2_don->setDate(QDate::fromString(date_v, "yyyy-MM-dd"));
            ui->spinBox_don->setValue(quantite);
            ui->spinBox_2_don->setValue(id_don);
        }
}

void MainWindow::on_pushButton_3_amin_clicked()
{
    ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_3_yosr_clicked()
{
    ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_3_louay_clicked()
{
    ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_3_mayssa_clicked()
{
    ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_2_scanner_clicked()
{

    QSqlQuery query;
    QString rfid = "";
    rfid = QString(Adon.getserial()->readLine()).trimmed();
    query.prepare("SELECT * from adherent where rfid=:rfid ");
    query.bindValue(":rfid",rfid);
    qDebug()<<rfid;

    qDebug() << query.boundValues();
    if(query.exec())
        {
            if(query.next())
            {
                    QMessageBox::information(nullptr, QObject::tr("Access reussis OK"),
                                          QObject::tr("Access Réussis OK\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);
                    if(rfid=="1476319173")
                    {
                    ui->stackedWidget->setCurrentIndex(13);}
                    if(rfid=="234457899")
                    {
                    ui->stackedWidget->setCurrentIndex(0);}
                    if(rfid=="20813217237")
                    {
                    ui->stackedWidget->setCurrentIndex(1);}
                    if(rfid=="13116814729")
                    {
                    ui->stackedWidget->setCurrentIndex(2);}


            }
            else
                QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                      QObject::tr("Accéss Interdit\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                  QObject::tr("Accéss non Réussis\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);

        }
}

void MainWindow::on_pushButton_2_test_clicked()
{
    Smtp* smtp = new Smtp("lefi.amine@esprit.tn", "popamqoxierydzbe", "smtp.gmail.com", 465 , 1500000);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            smtp->sendMail("lefi.amine@esprit.tn", ui->mail->text() , ui->subject->text(),ui->msg->toPlainText());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Mail envoyé"));
}
