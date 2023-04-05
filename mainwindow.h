#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "event.h"
#include <QMainWindow>
#include <QIntValidator>
#include<QPrinter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QFileDialog>
#include <windows.h>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QObject>
#include <QIntValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
#include <QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include<QDebug>
#include <QPrinter>
#include<QPrintDialog>
#include <QMessageBox>
#include <QFileDialog>
#include<QDebug>
#include <QDateTime>
#include <QDate>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();



    void on_tableView_2_clicked(const QModelIndex &index);

    void on_comboBox_activated(const QString &arg1);

    void on_rechercher_clicked();

    void on_savetopdf_clicked();

private:
    Ui::MainWindow *ui;
    Event ev;
};
#endif // MAINWINDOW_H
