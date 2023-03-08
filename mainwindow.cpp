#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(ev.afficher());
       on_ajouter_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    QString nom_eve=ui->nom_eve->text();
    QString nom_eq=ui->nom_eq->text();
    QString nom_org = ui->nom_org->text();
    int np=ui->np->text().toInt();
    QString tache= ui->tache->text();
    QDate date_eve=ui->date->date();

    QString cin= QString::number(id);
    Event e(id, nom_eve,nom_eq,nom_org,np,date_eve,tache);


    if(e.existance(cin))

        {
            bool test=e.ajouter();
            if(test)
            {
                ui->tableView->setModel(ev.afficher());

                QMessageBox::information(nullptr, QObject::tr("ajout effuctué"),  QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout n'est pas effuctué"),QObject::tr("connection failed.\n"  "Click Cancel to exit."), QMessageBox::Cancel);

}}
