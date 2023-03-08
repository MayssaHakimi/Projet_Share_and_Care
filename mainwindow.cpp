#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "don.h"
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_affiche_2->setModel(Do.afficher_don());
     on_pushButton_22_clicked();
     on_pushButton_23_clicked();



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
     int id_don=ui->lineEdit_4->text().toInt();
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
   {   ui->tab_affiche_2->setModel(Do.afficher_don());
        QMessageBox::information(nullptr , QObject::tr("ok") , QObject::tr("ajout sayey"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr , QObject::tr("not ok") , QObject::tr("ajout non"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_20_clicked()
{
     int id_don=ui->lineEdit_4->text().toInt();
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
    int id_don=ui->lineEdit_4->text().toInt();

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
    QString type_don=ui->lineEdit_8->text();
              ui->tab_affiche_2->setModel(Do.recherche_don(type_don));
              ui->lineEdit_8->clear();

}
