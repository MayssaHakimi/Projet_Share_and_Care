#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "gestionlivraison.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>
//#include <QQuickWidget>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);


//l'affichage
ui->tab_liv->setModel(l.afficher());

Gestionlivraison Gestionlivraison;
 QSqlQueryModel * model = Gestionlivraison.trie();
 ui->tab_liv->setModel(model);
 QObject::connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);

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
    QString Date_liv_str =ui->Date_liv->text();
    //QString Date_liv_str = ui->Date_liv->text();
     QDate Date_liv = QDate::fromString(Date_liv_str, "dd/MM/yyyy");
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
    int id_livraison = ui->ID_LIVRAISON->text().toInt();
    //Gestionlivraison l;
    if(l.existe(id_livraison))
    {
        l.setID_LIVRAISON(id_livraison);
        bool test = l.supprimer(l.getID_LIVRAISON());
        QMessageBox msgbox;
        if (test)
        {
            // refresh
            ui->tab_liv->setModel(l.afficher( ));
            msgbox.setText("supprimer avec succée");
        }
        else
        {
            msgbox.setText("supprimer failed");
        }
        msgbox.exec();
    }
    else
    {
        QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("ID_LIVRAISON n'existe pas"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Modifier_clicked()
{
    int ID_LIVRAISON = ui->le_id->text().toInt();
   // Gestionlivraison l;

    if(l.existe(ID_LIVRAISON))
    {
        QString cin_liv = ui->le_cin->text();
        QString nom_liv = ui->le_nom->text();
        QString prenom_liv = ui->le_prenom->text();
        QString telephone = ui->le_telephone->text();
        QString Adresse_liv = ui->le_adresse->text();
        QString Objet = ui->le_objet->text();
        //QString Date_liv = ui->Date_liv->text();
        QString Date_liv_str = ui->Date_liv->text();
         QDate Date_liv = QDate::fromString(Date_liv_str, "dd/MM/yyyy");
        Gestionlivraison l(ID_LIVRAISON, cin_liv, nom_liv, prenom_liv, Date_liv, Adresse_liv, Objet, telephone);
        bool test2 = l.modifier(ID_LIVRAISON);
        if (test2)
        {
            // refresh
            ui->tab_liv->setModel(l.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                      QObject::tr("modififier avec succée"
                                                  "" "click canal to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                    QObject::tr("modififier echec "
                                                "click cancel to exit "), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr , QObject::tr("not ok"),
                          QObject::tr("ID_LIVRAISON n'existe pas"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Recherche_clicked()
{
    QString motCle = ui->ID_LIVRAISON->text();
     /* l.rechercher(motCle);
      ui->tab_liv->setModel(l.afficher());
*/
      ui->tab_liv->setModel(l.rechercher(motCle));
}

/*void MainWindow::on_trie_clicked()
{

    ui->tab_liv->setModel(l.trie( tab_liv,  taille_tab_liv));
    // refresh
    ui->tab_liv->setModel(l.afficher( ));
}
*/
/*void MainWindow::on_statistique_clicked()
{
    // Récupération de la date saisie par l'utilisateur
    QDate date_liv = ui->Date_liv->date();

    // Appel de la fonction de calcul de statistiques
    int nombreLivraisons = statistique(date_liv);

    // Affichage du résultat
    if(nombreLivraisons != -1)
    {
        ui->statistique->setText(QString("Nombre de livraisons pour le %1 : %2").arg(date_liv.toString("dd/MM/yyyy")).arg(nombreLivraisons));
    }
    else
    {
        ui->statistique->setText("Une erreur est survenue lors du calcul des statistiques.");
    }
}

int MainWindow::statistique(QDate date_liv)
{
    QSqlQuery query;
    QString dateString = date_liv.toString("yyyy-MM-dd");
    query.prepare("SELECT COUNT(*) FROM LOLITA.LIVRAISON WHERE Date_liv = :date_liv");
    query.bindValue(":date_liv", dateString);

    if(query.exec() && query.next())
    {
        return query.value(0).toInt();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                QObject::tr("modififier echec "
                                            "click cancel to exit "), QMessageBox::Cancel);
    }
}*/

void MainWindow::on_trie_clicked()
{
/*
    QSqlQueryModel *model = l.trie();
    ui->tab_liv->setModel(model);
    ui->tab_liv->show();
    connect(ui->trie, &QPushButton::clicked, this, &MainWindow::on_trie_clicked);
    // refresh
    ui->tab_liv->setModel(l.afficher());*/
    // refresh
     ui->tab_liv->setModel(l.afficher());
    Gestionlivraison Gestionlivraison;
    Gestionlivraison.trie();


}
void MainWindow::on_pdf_clicked()
{
    Gestionlivraison Gestionlivraison;
    Gestionlivraison.PDF();
}
