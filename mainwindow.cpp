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
        ui-> comboBox->addItem("Vetement et Nourriture");
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


}

MainWindow::~MainWindow()
{
    delete ui;
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

//statistique_don();

    if (test)
   {
        ui->tab_affiche_2->setModel(Do.afficher_don());
        QMessageBox::information(nullptr , QObject::tr("ok") , QObject::tr("ajout sayey"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr , QObject::tr("not ok") , QObject::tr("ajout non"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_20_clicked()
{
     int id_don=ui->spinBox_2->text().toInt();
     bool test=Do.supprimer_don( id_don);

     if (test)
    {   ui->tab_affiche_2->setModel(Do.afficher_don());
         QMessageBox::information(nullptr , QObject::tr("ok") , QObject::tr("supp sayey"),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr , QObject::tr("not ok") , QObject::tr("supp non"),QMessageBox::Cancel);

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
    int id_don=ui->spinBox_2->text().toInt();

    Don D (id_don,nom_don ,prenom_don , cin_don, type_don, taille, date_v, quantite);

    bool test=D.modifier_don(id_don);

    if (test)
   {   ui->tab_affiche_2->setModel(Do.afficher_don());
        QMessageBox::information(nullptr , QObject::tr("ok") , QObject::tr("mod sayey"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr , QObject::tr("not ok") , QObject::tr("mod non"),QMessageBox::Cancel);
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
              ui->tab_affiche_2->setModel(Do.recherche_don(ui->lineEdit_8->text()));
             //  ui->tab_affiche_2->setModel(Do.recherche_don_nom(ui->lineEdit_8->text()));

}

void MainWindow::statistique_don()
{

    //![1]
            QBarSet *set0 = new QBarSet("Vetement");
            QBarSet *set1 = new QBarSet("Nourriture");
            QBarSet *set2 = new QBarSet("Vetement et Nourriture");


            *set0 << Do.vetement();
            *set1 << Do.nourriture();
            *set2 << Do.vetement_nourriture();

        //![1]

        //![2]
            QBarSeries *series = new QBarSeries();
            series->append(set0);
            series->append(set1);
            series->append(set2);


        //![2]

        //![3]
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Statistique");
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTheme(QChart::ChartThemeBrownSand);
        //![3]

        //![4]
            QStringList categories;
            categories << "Type de don" ;
            QBarCategoryAxis *axis = new QBarCategoryAxis();
            axis->append(categories);
            chart->createDefaultAxes();
            chart->setAxisX(axis, series);
        //![4]

        //![5]
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);
        //![5]

        //![6]
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
        //![6]

        //![7]


            ui->groupBox_2->setLayout(new QVBoxLayout);
            ui->groupBox_2->layout()->addWidget(chartView);
        //![7]


}

