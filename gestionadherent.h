#ifndef GESTIONADHERENT_H
#define GESTIONADHERENT_H
#include <QFile>
#include <QDialog>
#include <QPropertyAnimation>
#include "adherent.h"
#include "don.h"
#include "gestiondon.h"
#include <QFileDialog>


namespace Ui {
class Gestionadherent;
}
class QMediaPlayer;
class Gestionadherent : public QDialog
{
    Q_OBJECT

public:
    explicit Gestionadherent(QWidget *parent = nullptr);
    ~Gestionadherent();
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


    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

private:
    Ui::Gestionadherent *ui;
Adherent Adh;

};

#endif // GESTIONADHERENT_H
