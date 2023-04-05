#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnect();
    MainWindow w;






    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("Base de donné "),
                    QObject::tr("Connexion réussie.\n"), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Base de donné"),
                    QObject::tr("Connexion n'est pas réussie.\n"), QMessageBox::Cancel);



    return a.exec();
}
