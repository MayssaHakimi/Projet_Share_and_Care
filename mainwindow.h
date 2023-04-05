#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <don.h>
#include <QMainWindow>
#include <QSslSocket>


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
    void on_pushButton_3_clicked();



    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_7_clicked();

    void statistique_don();

    void sendSMS(QString apiKey, QString apiSecret, QString from, QString to, QString message);

 void statistique_don_update();


    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_24_clicked();

    void on_pushButton_16_pressed();

    void on_pushButton_9_pressed();

    void connectedToServer();

    void sslErrors(const QList<QSslError> &errors);
    void receiveMessage();
    void connectionClosed();
    void socketError();


private:
    Ui::MainWindow *ui;
    Don Do;
};
#endif // MAINWINDOW_H
