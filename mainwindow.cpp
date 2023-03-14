#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "beneficiaire.h"
#include<QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
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
                                 QObject::tr("Ajout  effectue\n"
                                            "click cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout non effectue\n"
                                            "click cancel to exit."), QMessageBox::Cancel);

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
                                     QObject::tr("Suppression effectue\n"
                                                "click cancel to exit."), QMessageBox::Cancel);
        }
        else

            QMessageBox::information(nullptr,QObject::tr("not OK"),
                                     QObject::tr("Suppression non effectue\n"
                                                "click cancel to exit."), QMessageBox::Cancel);

        }





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
                                            "click cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::information(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("modification non effectue\n"
                                            "click cancel to exit."), QMessageBox::Cancel);


}
