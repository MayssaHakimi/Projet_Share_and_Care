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
using namespace qrcodegen ;
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //controle de saisir pour id
    ui->lineEdit_4->setValidator(new QIntValidator(1,99999999,this));
    //controle de saisir pour nom

    QRegExpValidator *validator = new QRegExpValidator(QRegExp("[A-Za-z ]+"),ui->lineEdit_8);
    ui->lineEdit_8->setValidator(validator);
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
    //pour recupérer id
    QSqlQuery query;
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
    //code qr
   /* QZXing decoder;
    QString result = decoder.decodeImage(QImage("code.png"));*/

    //pdf


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
    delete ui;
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
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString ident = ui->lineEdit_3->text();

 auth.m_username=Adh.authen_nom(username);
 auth.m_password=Adh.authen_mdp(username);
        // Vérification de l'authentification

if (username == auth.m_username && password == auth.m_password ) {
    QMessageBox::information(this, "Authentification réussie", "Vous êtes connecté.");
    if (ident == "200ADH1403")
     {ui->stackedWidget->setCurrentIndex(2);}
   else  if (ident == "214BEN1101")
     {ui->stackedWidget->setCurrentIndex(3);}
    else if (ident == "301DON1407")
     {ui->stackedWidget->setCurrentIndex(4);}
    else if (ident == "312LIV1807")
     {ui->stackedWidget->setCurrentIndex(5);}
    else if (ident == "232EVE0101")
     {ui->stackedWidget->setCurrentIndex(6);}


} else {
    // Authentification échouée
    QMessageBox::warning(this, "Authentification échouée", "Nom d'utilisateur ou mot de passe invalide.");
}


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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_16_clicked()
{
ui->stackedWidget->setCurrentIndex(7);}
