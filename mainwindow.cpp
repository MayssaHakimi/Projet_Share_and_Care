#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherent.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(Adh.afficher_adh());
    on_pushButton_14_clicked();
    on_pushButton_15_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_button_clicked()
{

   QString nom_adh=ui->lineEdit_8->text();
   QString prenom_adh=ui->lineEdit_6->text();
   QString cin_adh=ui->lineEdit_7->text();
   QString identifiant=ui->lineEdit_10->text();
   QString mdp_adh=ui->lineEdit_9->text();
   QString img=ui->lineEdit_12->text();
   QString fct_adh=ui->lineEdit_11->text();
   QString date_emb=ui->lineEdit_4->text();
   Adherent A(nom_adh , prenom_adh, cin_adh,identifiant , mdp_adh,img , date_emb ,fct_adh);

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
    QString identifiant=ui->lineEdit_10->text();
    QString mdp_adh=ui->lineEdit_9->text();
    QString img=ui->lineEdit_12->text();
    QString fct_adh=ui->lineEdit_11->text();
    QString date_emb=ui->lineEdit_4->text();
    int id_adh =ui->lineEdit_5->text().toInt();

    Adherent A(nom_adh , prenom_adh, cin_adh,identifiant , mdp_adh,img , date_emb ,fct_adh);

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
    QString fct_adh=ui->lineEdit_23->text();
    ui->tableView_2->setModel(Adh.recherche_adh(fct_adh));

}
