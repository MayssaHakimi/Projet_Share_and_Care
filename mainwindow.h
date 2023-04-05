#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestionlivraison.h"
#include <QMainWindow>
#include <QDate>
#include <algorithm>
#include <QGuiApplication>
//#include <QtLocation>
//#include <QWidget>

//QT_BEGIN_NAMESPACE
namespace Ui {
//QT_END_NAMESPACE
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit  MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();

    void on_Supprimer_clicked();
    void on_Modifier_clicked();


    void on_Recherche_clicked();

    void on_trie_clicked();

//    void on_statistique_clicked();

    void on_pdf_clicked();

private:
    void rechercher(QString motCle);

//QQuickView *louay;
     int statistique(QDate date_liv);
    Ui::MainWindow *ui;
    Gestionlivraison l;
 //Gestionlivraison Etmp;
};
#endif // MAINWINDOW_H
