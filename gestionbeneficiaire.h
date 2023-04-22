#ifndef GESTIONBENEFICIAIRE_H
#define GESTIONBENEFICIAIRE_H

#include <beneficiaire.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Gestionbeneficiaire; }
QT_END_NAMESPACE

class Gestionbeneficiaire : public QMainWindow
{
    Q_OBJECT

public:
    Gestionbeneficiaire(QWidget *parent = nullptr);
    ~Gestionbeneficiaire();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



   // void on_comboBox_currentIndexChanged(int index);

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
    Ui::Gestionbeneficiaire *ui;
    Beneficiaire B;
    Beneficiaire Btmp;
    Beneficiaire Bo;
};


#endif // GESTIONBENEFICIAIRE_H
