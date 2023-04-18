#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <adherent.h>
#include <QMainWindow>
#include"arduino.h"
//QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_button_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();
    void getNomPrenomFromComboBox();


    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

private:
    Ui::MainWindow *ui;
    Adherent Adh;
    QByteArray dat; // variable contenant les données reçues

     Arduino Ar; // objet temporaire
};
#endif // MAINWINDOW_H
