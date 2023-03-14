
#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "gestionlivraison.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tab_liv->setModel(l.afficher());

// lena zedt validator

ui->cin_liv->setValidator(new QIntValidator(0, 99999999, this));
ui->telephone->setValidator(new QIntValidator(0, 99999999, this));
ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));

//lina youfa

}

MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    int ID_LIVRAISON =ui->le_id->text().toInt();
    QString nom_liv=ui->nom_liv->text();
    QString prenom_liv=ui->prenom_liv->text();
    QString Date_liv =ui->Date_liv->text();
     QString cin_liv =ui->cin_liv->text();
    QString Adresse_liv =ui->Adresse_liv->text();
    QString Objet =ui->Objet->text();
    QString telephone =ui->telephone->text();



Gestionlivraison l ( ID_LIVRAISON ,cin_liv, nom_liv , prenom_liv , Date_liv, Adresse_liv, Objet ,  telephone   );

bool testaj=l.ajouter();

if (testaj)
{
   // refresh
    ui->tab_liv->setModel(l.afficher());

  QMessageBox::information(nullptr , QObject::tr("ok"),
          QObject::tr("ajout avec succée"
                    "" "click canal to exit."),QMessageBox::Cancel);

}else
    QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("ajout echec "
                                      "click cancel to exit "), QMessageBox::Cancel);

}

void MainWindow::on_Supprimer_clicked()
{
Gestionlivraison l1;l1.setID_LIVRAISON(ui->ID_LIVRAISON->text().toInt());

bool test =l1.supprimer(l1.getID_LIVRAISON());
QMessageBox msgbox;
if (test)
{
    // refresh
     ui->tab_liv->setModel(l.afficher());
      msgbox.setText("supprimer acev succée");
}
else   
    msgbox.setText("supprimer failed");
    msgbox.exec();
}


void MainWindow::on_Modifier_clicked()
{



  int ID_LIVRAISON =ui->le_id->text().toInt();
     QString cin_liv=ui->le_cin->text();
    QString nom_liv=ui->le_nom->text();
     QString prenom_liv=ui->le_prenom->text();
     QString telephone =ui->le_telephone->text();
      QString Adresse_liv =ui->le_adresse->text();
     QString Objet =ui->le_objet->text();
     QString Date_liv =ui->Date_liv->text();


Gestionlivraison l2 ( ID_LIVRAISON ,cin_liv, nom_liv , prenom_liv , Date_liv, Adresse_liv, Objet ,  telephone   );

bool test2 =l2.modifier(l2.getID_LIVRAISON());

if (test2)
{
   // refresh
    ui->tab_liv->setModel(l.afficher());

  QMessageBox::information(nullptr , QObject::tr("ok"),
          QObject::tr("modififier avec succée"
                    "" "click canal to exit."),QMessageBox::Cancel);

}else
    QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("modififier echec "
                                      "click cancel to exit "), QMessageBox::Cancel);
}
