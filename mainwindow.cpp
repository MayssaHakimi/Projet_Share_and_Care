#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherent.h"
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCore/QDebug>
#include <QVBoxLayout>
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //controle de saisir pour id
    ui->lineEdit_5->setValidator(new QIntValidator(1,99999999,this));
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
    int id_adh =ui->lineEdit_5->text().toInt();
   QString nom_adh=ui->lineEdit_8->text();
   QString prenom_adh=ui->lineEdit_6->text();
   QString  cin_adh =ui->lineEdit_7->text();
   QString identifiant=ui->comboBox_2->currentText();
   QString mdp_adh=ui->lineEdit_9->text();
   QString fct_adh=ui->comboBox->currentText();
   QString date_emb=ui->lineEdit_4->text();
   Adherent A(id_adh ,nom_adh , prenom_adh, cin_adh,identifiant , mdp_adh, date_emb ,fct_adh);
   bool test =A.ajouter_adh();

   if(test)
   {
       ui->tableView_2->setModel(Adh.afficher_adh());

       QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué \n" "Click Cancel to exit ."),QMessageBox::Cancel  );
   }
else

       QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Ajout non effectué \n" "Click Cancel to exit ."),QMessageBox::Cancel  );

}


void MainWindow::on_pushButton_12_clicked()
{
    int id_adh =ui->lineEdit_5->text().toInt();
    bool test =Adh.supprimer_adh(id_adh);

    if(test)
    {
        ui->tableView_2->setModel(Adh.afficher_adh());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectué \n" "Click Cancel to exit ."),QMessageBox::Cancel  );
    }
 else

        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression non effectué \n" "Click Cancel to exit ."),QMessageBox::Cancel  );

}



void MainWindow::on_pushButton_11_clicked()
{
    QString nom_adh=ui->lineEdit_8->text();
    QString prenom_adh=ui->lineEdit_6->text();
   QString cin_adh=ui->lineEdit_7->text();
    QString identifiant=ui->comboBox_2->currentText();
    QString mdp_adh=ui->lineEdit_9->text();

    QString fct_adh=ui->comboBox->currentText();
    QString date_emb=ui->lineEdit_4->text();
    int id_adh =ui->lineEdit_5->text().toInt();

    Adherent A(id_adh,nom_adh , prenom_adh, cin_adh,identifiant , mdp_adh, date_emb ,fct_adh);

    bool test =A.modifier_adh(id_adh);

    if(test)
    {
        ui->tableView_2->setModel(Adh.afficher_adh());

        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modificaion effectué \n" "Click Cancel to exit ."),QMessageBox::Cancel  );
    }
 else

        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification non effectué \n" "Click Cancel to exit ."),QMessageBox::Cancel  );

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
