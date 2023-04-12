#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <beneficiaire.h>

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_t_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_tri_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_rech_clicked();

    void on_histbouton_clicked();

    void on_pushButton_pdf_2_clicked();

    void on_sendmail_clicked();

    void on_mailbutt_clicked();



    void on_statbutton_clicked();

    void on_aff_clicked();

    void on_pushButton_tri_2_clicked();

private:
    Ui::MainWindow *ui;
    Beneficiaire B;
    Beneficiaire Btmp;
    Beneficiaire Bo;
};
#endif // MAINWINDOW_H
