/*#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/
#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "gestionlivraison.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
ui->setupUi(this);
// lena zedt validator

ui->cin_liv->setValidator(new QIntValidator(0, 9999999, this));
ui->phone->setValidator(new QIntValidator(0, 99999999, this));
//lina youfa
}

MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::on_ajouter_clicked()
{

    QString nom_liv=ui->nom_liv->text();
    QString prenom_liv=ui->prenom_liv->text();
     int CIN =ui->cin_liv->text().toInt();
    int   telephone =ui->phone->text().toInt();
    QString Date_liv =ui->Date_liv->text();
    QString Adresse_liv =ui->Adresse_liv->text();
    QString Objet =ui->Objet->text();




Gestionlivraison l ( nom_liv , prenom_liv , Date_liv, Adresse_liv, Objet , CIN, telephone   );

bool test=l.ajouter();

if (test)
{
  QMessageBox::information(nullptr , QObject::tr("ok"),
          QObject::tr("ajout avec succée"
                    "click canal to exit."),QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("ajout echec "
                                      "click cancel to exit "), QMessageBox::Cancel);

}

void MainWindow::on_Supprimer_clicked()
{

}
