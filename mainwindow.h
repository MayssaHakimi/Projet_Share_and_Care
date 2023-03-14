#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestionlivraison.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    Gestionlivraison l;
 //Gestionlivraison Etmp;
};
#endif // MAINWINDOW_H
