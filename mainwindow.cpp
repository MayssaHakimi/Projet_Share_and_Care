#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "beneficiaire.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QLoggingCategory>
#include <QDateTime>
#include "mail.h"
#include "mail.cpp"



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
                                 QObject::tr("deja existe\n"
                                            "click cancel to exit."), QMessageBox::Cancel);

        QFile file ("C:/Users/Mohamed Amine/Desktop/ben/history.txt");

        if (!file.open(QFile::WriteOnly  | QFile::Append))
            {
            QMessageBox::warning(this, "title","file  not open");
            }
        QTextStream out (&file);

         QDate datenow = QDate::currentDate();
        QString datenowst=datenow.toString();
        QTime timenow= QTime::currentTime();
            QString timenowst=timenow.toString();

        //QString  text  = ui->history->toPlainText();
        out << "Ajout d'un beneficiaire  " << id_ben << "  le  " << datenowst << "  à l'heure   " << timenowst << " \n" ;
        file.flush();
        file.close ();

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
                                     QObject::tr("nexiste pas\n"
                                                "click cancel to exit."), QMessageBox::Cancel);
            QFile file ("C:/Users/Mohamed Amine/Desktop/ben/history.txt");

            if (!file.open(QFile::WriteOnly  | QFile::Append))
                {
                QMessageBox::warning(this, "title","file  not open");
                }
            QTextStream out (&file);

             QDate datenow = QDate::currentDate();
            QString datenowst=datenow.toString();
            QTime timenow= QTime::currentTime();
                QString timenowst=timenow.toString();

            //QString  text  = ui->history->toPlainText();
            out << "Supression du beneficiaire " << id_ben << "  le  " << datenowst << "  à l'heure   " << timenowst << " \n" ;
            file.flush();
            file.close ();

        }
        else

            QMessageBox::information(nullptr,QObject::tr("not OK"),
                                     QObject::tr("Suppression non effectue\n"
                                                "click cancel to exit."), QMessageBox::Cancel);

        }




//affichage
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
                                 QObject::tr("nexiste pas\n"
                                            "click cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::information(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("modification non effectue\n"
                                            "click cancel to exit."), QMessageBox::Cancel);


}







void MainWindow::on_pushButton_tri_clicked()
{
    QSqlQueryModel* sortedModel = B.tri();
    ui->tab_aff->setModel(sortedModel);
}

void exportToPdf(QTableView* view, const QString& filename)
{
    QPdfWriter writer(filename);
    QPainter painter(&writer);
    view->render(&painter);
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Export to PDF", "", "*.pdf");
       if (!filename.isEmpty()) {
           QPdfWriter writer(filename);
           writer.setPageSize(QPageSize(QPageSize::A5));
           writer.setPageMargins(QMarginsF(30, 30, 30, 30));

           QPainter painter(&writer);
           ui->tab_aff->render(&painter);
       }
}


void MainWindow::on_pushButton_rech_clicked()
{
    QString searchValue = ui->lineEdit_search->text();

    if (searchValue.isEmpty()) {
        ui->tab_aff->setModel(B.afficher());
    } else {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(QString("SELECT * FROM beneficiaire WHERE nom_ben LIKE '%%1%'").arg(searchValue));
        ui->tab_aff->setModel(model);
    }

}

void MainWindow::on_histbouton_clicked()
{
    QFile file ("C:/Users/Mohamed Amine/Desktop/ben/history.txt");

       if (!file.open(QFile::ReadOnly  | QFile::Text))
           {
           QMessageBox::warning(this, "title","file  not open");
           }
       QTextStream in (&file);
       QString  text  = in.readAll();
       ui->plainTextEdit->setPlainText(text);

       file.close();
}

void MainWindow::on_sendmail_clicked()
{QString ch;
    ch="lefi.amine@esprit.tn";
   if(ch.contains("@", Qt::CaseInsensitive)==true)
    {mail* Mail = new mail ("lefi.amine@esprit.tn","211JMT6581", "smtp.gmail.com");
      connect(Mail, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


            Mail->sendMail("lefi.amine@esprit.tn", "lefi.amine@esprit.tn" , "ui->subject_2->text()","ui->msg_2->text()");
  }
     else
         QMessageBox::information(nullptr,QObject::tr("mail non envoyé"),
                                  QObject::tr("mail non envoyé. \n"
                                              "Click Cancel to exist."),QMessageBox::Cancel);
  }



