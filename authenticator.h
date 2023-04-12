#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H


#include <QString>

class Authenticator
{
public:
    Authenticator();

    // Méthode pour vérifier l'authentification
   // bool authenticate(const QString& username,const QString& password);
    QString m_username;
    QString m_password;


//private:

};

#endif // AUTHENTICATOR_H
