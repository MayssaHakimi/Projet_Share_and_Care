#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        Connection c;
        bool test=c.createconnect();
        MainWindow w;

        if(test)
        {w.show();
            QMessageBox::information(nullptr, QObject::tr("Base de donné est ouvert"),
                        QObject::tr("Connexion réussie.\n"
                                    "Cliquez sur Cancel pour quitter"), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Cliquez sur Cancel pour quitter"), QMessageBox::Cancel);



        return a.exec();
}
