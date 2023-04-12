#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    Connection c;

    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("base de donnees nest pas ouverte"),
                    QObject::tr("connection.\n"
                                "Clicquez Annuler pour quittter."));

}
    else
        QMessageBox::information(nullptr, QObject::tr("dbase de donnees nest pas ouverte"),
                    QObject::tr("pas de connection.\n"
                                "Clicquez Annuler pour quitttert."));



    return a.exec();
}
