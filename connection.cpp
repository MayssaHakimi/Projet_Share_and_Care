#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source1");
db.setUserName("yosrbenamor");//inserer nom de l'utilisateur
db.setPassword("esprit14");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
