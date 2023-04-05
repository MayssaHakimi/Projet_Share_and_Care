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
#include <QPainter>
#include<QFileDialog>
#include <QtCore/QDebug>
#include <QVBoxLayout>
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

                 ui->groupBox_2->setLayout(new QVBoxLayout);
                                 ui->groupBox_2->layout()->addWidget(chartView);

ui->groupBox_2->resize(500,400);
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
          }

}

void MainWindow::on_pushButton_13_clicked()
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
