#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <adherent.h>
#include <QMainWindow>
#include "gestionlivraison.h"
#include <QMainWindow>
#include <QDate>
#include <algorithm>
#include <QGuiApplication>
#include <QVariant>
#include <QCalendarWidget>
#include <QDate>
#include <QList>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QTableWidget>
#include "arduino.h"
#include <beneficiaire.h>
#include <don.h>
#include "client.h"
#include"arduinodon.h"

#include <QMainWindow>
#include <QSslSocket>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
//QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
      Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void appendMessage(const QString &from, const QString &message);




private slots:


    void on_ajouter_clicked();

    void on_Supprimer_clicked();
    void on_Modifier_clicked();


    void on_Recherche_clicked();

    void on_trie_clicked();

 void on_statistique_clicked();

    void on_pdf_clicked();


    // void on_dateEdit_dateChanged(const QDate &date);
    void afficherLivraisonCalendier();
    void on_arduino_clicked();


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

    void on_pushButton_ajou_clicked();

      void on_pushButton_2_clicked();

      void on_pushButton_3_clicked();

     // void on_pushButton_t_clicked();

   //   void on_comboBox_currentIndexChanged(int index);
      void on_pushButton_tri_clicked();

      void on_pushButton_pdf_clicked();

      void on_pushButton_rech_clicked();

      void on_histbouton_clicked();

     // void on_pushButton_pdf_2_clicked();



      void on_statbutton_clicked();

      void on_aff_clicked();

      void on_pushButton_tri_2_clicked();

      void on_alarmbutton_clicked();

     // void on_pushButton_9_clicked();


      void on_pushButton_32_don_clicked();

      void on_pushButton_33_don_clicked();

      void on_pushButton_31_don_clicked();

      void on_pushButton_28_don_clicked();

      void statistique_don();

      void on_pushButton_27_don_clicked();

      void on_pushButton_29_don_clicked();

      void on_pushButton_30_don_clicked();

      void on_pushButton_19_don_clicked();


      void send_sms();

      void on_pushButton_20_don_clicked();

      void on_pushButton_26_don_clicked();

      void on_comboBox_7_don_currentIndexChanged(const QString &arg1);

      void returnPressed();
          void newParticipant(const QString &nick);
          void participantLeft(const QString &nick);
          void showInformation();



              void on_pushButton_3_amin_clicked();

              void on_pushButton_3_yosr_clicked();

              void on_pushButton_3_louay_clicked();

              void on_pushButton_3_mayssa_clicked();

              void on_pushButton_2_scanner_clicked();

              void on_pushButton_2_test_clicked();

private:

    Adherent Adh;
    QByteArray dat; // variable contenant les données reçues
    Beneficiaire B;
       Beneficiaire Btmp;
       Beneficiaire Bo;
       //ArduinoDon Aben;
       QByteArray data;
     //ArduinoDon Ar; // objet temporaire
     void rechercher(QString motCle);
     QCalendarWidget *calendarWidget;
        // int statistique(QDate date_liv);
      Gestionlivraison l;
       //ArduinoDon A;
       Don Do;
          Client client;
          QString myNickName;
          QTextTableFormat tableFormat;

ArduinoDon Adon ;
signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
};
#endif // MAINWINDOW_H
