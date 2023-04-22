#include "gestionadherent.h"
#include "ui_Gestionadherent.h"
#include "adherent.h"
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include <QtCore/QDebug>
#include <QVBoxLayout>
#include "authenticator.h"
#include "mainwindow.h"
#include "gestiondon.h"
#include "ui_gestiondon.h"
#include "gestionbeneficiaire.h"
#include "ui_gestionbeneficiaire.h"
#include "qrcode.h"
using namespace qrcodegen ;
QT_CHARTS_USE_NAMESPACE

Gestionadherent::Gestionadherent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gestionadherent)
{
ui->setupUi(this);
connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(on_pushButton_10_clicked()));

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
      ui->lineEdit_2->setEchoMode(QLineEdit::Password);
            ui->lineEdit_2->show();
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

             chartView->setRenderHint(QPainter::Antialiasing);

             ui->frame->setLayout(new QVBoxLayout);
                             ui->frame->layout()->addWidget(chartView);

ui->frame->resize(500,400);
//![3]



}

Gestionadherent::~Gestionadherent()
{
delete ui;
}


void Gestionadherent::on_ajouter_button_clicked()
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


void Gestionadherent::on_pushButton_12_clicked()
{
int id_adh =ui->comboBox_3->currentText().toInt();
bool test =Adh.supprimer_adh(id_adh);

if(test)
{
    ui->comboBox_3->clear();
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


void Gestionadherent::on_pushButton_11_clicked()
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

void Gestionadherent::on_pushButton_14_clicked()
{
ui->tableView_2->setModel(Adh.tri_adh_asc());

}

void Gestionadherent::on_pushButton_15_clicked()
{
ui->tableView_2->setModel(Adh.tri_adh_desc());

}

void Gestionadherent::on_pushButton_8_clicked()
{

ui->tableView_2->setModel(Adh.recherche_adh(ui->lineEdit_23->text()));

}

void Gestionadherent::on_comboBox_3_currentIndexChanged(const QString &id_adh)
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

void Gestionadherent::on_comboBox_4_currentIndexChanged(const QString &id_adh)
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
      }

}

void Gestionadherent::on_pushButton_13_clicked()
{
QString filename = QFileDialog::getSaveFileName(this, "Export to PDF", "", "*.pdf");
       if (!filename.isEmpty()) {
           QPdfWriter writer(filename);
           writer.setPageSize(QPageSize(QPageSize::A5));
           writer.setPageMargins(QMarginsF(30, 30, 30, 30));

           QPainter painter(&writer);
         ui-> groupBox_4->render(&painter);

       }

}
void Gestionadherent::on_pushButton_clicked()
{
    Authenticator auth;

    QString password = ui->lineEdit_2->text();
    QString ident = ui->lineEdit_3->text();

 auth.m_username=Adh.authen_nom(password);
 auth.m_password=Adh.authen_mdp(password);
        // Vérification de l'authentification

if (ident == auth.m_username && password == auth.m_password ) {
    QMessageBox::information(this, "Authentification réussie", "Vous êtes connecté.");
    if (ident == "ADH140")
     {ui->stackedWidget->setCurrentIndex(2);}
   else  if (ident == "BEN110")
     {ui->stackedWidget->setCurrentIndex(3);}
    else if (ident == "DON147")
     {ui->stackedWidget->setCurrentIndex(4);}
    else if (ident == "LIV180")
     {ui->stackedWidget->setCurrentIndex(5);}
    else if (ident == "EVE010")
     {ui->stackedWidget->setCurrentIndex(6);}


} else {
    // Authentification échouée
    QMessageBox::warning(this, "Authentification échouée", "Nom d'utilisateur ou mot de passe invalide.");
}


}
void Gestionadherent::on_pushButton_9_clicked()
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

void Gestionadherent::on_pushButton_20_clicked()
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
void Gestionadherent::getNomPrenomFromComboBox()
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
void Gestionadherent::on_pushButton_10_clicked()
{
ui->stackedWidget->setCurrentIndex(7);
}

void Gestionadherent::on_pushButton_16_clicked()
{
    Gestionbeneficiaire *gest_ben = new Gestionbeneficiaire(this);
    ui->stackedWidget->addWidget(gest_ben);
    ui->stackedWidget->setCurrentWidget(gest_ben);
}
void Gestionadherent::on_pushButton_22_clicked()
{
    //deconnecter amin
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
     ui->stackedWidget->setCurrentIndex(0);
}

void Gestionadherent::on_pushButton_17_clicked()
{
    Gestiondon *gest_don = new Gestiondon(this);
    ui->stackedWidget->addWidget(gest_don);
    ui->stackedWidget->setCurrentWidget(gest_don);
}
void Gestionadherent::on_pushButton_23_clicked()
{
    //deconnecter yosr
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
     ui->stackedWidget->setCurrentIndex(0);
}

/*void Gestionadherent::on_pushButton_18_clicked()
{
    //louay
}*/
void Gestionadherent::on_pushButton_24_clicked()
{
    //deconnecter louay
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
     ui->stackedWidget->setCurrentIndex(0);
}


/*void Gestionadherent::on_pushButton_19_clicked()
{
    //montaha
}*/
void Gestionadherent::on_pushButton_7_clicked()
{
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
     ui->stackedWidget->setCurrentIndex(0);

}
void Gestionadherent::on_pushButton_25_clicked()
{
    //deconnecter montaha
    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
     ui->stackedWidget->setCurrentIndex(0);
}

void Gestionadherent::on_pushButton_21_clicked()
{

    ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

