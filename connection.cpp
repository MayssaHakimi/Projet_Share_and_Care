/*#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");

bool test=false;
db.setDatabaseName("source");
db.setUserName("lolita");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closecnnection()
{
    db.close();
}
*/
#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");

    bool test=false;
    db.setDatabaseName("source");
    db.setUserName("lolita");//inserer nom de l'utilisateur
    db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

    if (db.open())
    {
        qDebug() << "Connexion reussie !";
        test = true;
    }
    else
    {
        qDebug() << "Erreur de connexion : " << db.lastError().text();
    }

    return test;
}

void Connection::closecnnection()
{
    db.close();
}

