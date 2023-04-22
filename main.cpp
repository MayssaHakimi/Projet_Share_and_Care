#include "mainwindow.h"
#include "gestionadherent.h"
#include "gestiondon.h"

#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        Connection c;
        bool test=c.createconnect();
        MainWindow w;
       Gestionadherent g;




       QNetworkConfigurationManager manager;
       if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
           // Get saved network configuration
           QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
           settings.beginGroup(QLatin1String("QtNetwork"));
           const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
           settings.endGroup();

           // If the saved network configuration is not currently discovered use the system default
           QNetworkConfiguration config = manager.configurationFromIdentifier(id);
           if ((config.state() & QNetworkConfiguration::Discovered) !=
               QNetworkConfiguration::Discovered) {
               config = manager.defaultConfiguration();
           }

           QNetworkSession *networkSession = new QNetworkSession(config, &w);
           networkSession->open();
           networkSession->waitForOpened();

           if (networkSession->isOpen()) {
               // Save the used configuration
               QNetworkConfiguration config = networkSession->configuration();
               QString id;
               if (config.type() == QNetworkConfiguration::UserChoice) {
                   id = networkSession->sessionProperty(
                           QLatin1String("UserChoiceConfiguration")).toString();
               } else {
                   id = config.identifier();
               }

               QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
               settings.beginGroup(QLatin1String("QtNetwork"));
               settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
               settings.endGroup();
           }

   }

        if(test)
        {g.show();
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
