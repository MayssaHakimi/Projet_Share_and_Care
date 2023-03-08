#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QDebug>
#include <QSqlDatabase>
class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnection();
    void closecnnection();
};

#endif // CONNECTION_H

