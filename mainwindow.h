#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <don.h>
#include "client.h"
#include "arduinodon.h"
#include <QMainWindow>
#include <QSslSocket>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QVBoxLayout>
#include "ui_mainwindow.h"
QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void appendMessage(const QString &from, const QString &message);

private slots:
    void on_pushButton_3_clicked();


    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_7_clicked();

    void statistique_don();

    void returnPressed();
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);
    void showInformation();


void send_sms();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_24_clicked();











    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    Don Do;
    QByteArray data; // variable contenant les données reçues

    ArduinoDon Adon; // objet temporaire
    Client client;
    QString myNickName;
    QTextTableFormat tableFormat;
};
#endif // MAINWINDOW_H
