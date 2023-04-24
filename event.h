#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include <QDate>
#include <QAbstractItemModel>
#include <QPainter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QString>
#include <QMessageBox>
#include <QApplication>
#include <QtCore>
#include <QPdfWriter>
#include <QPainter>
#include <Windows.h>
#include <QDateTime>
#include <QTimer>
#include <QtCharts>
#include <QSqlError>
class Event
{
private:
   int  id;
   QString nom_eve;
   QString nom_eq;
   QString nom_org;
   int np;
   QDate date_eve;
   QString tache;
public:
    Event(int ,QString ,QString,QString,int,QDate,QString);
    Event();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    bool existance(QString);
   QSqlQueryModel * rechercher(QString);
    QSqlQueryModel* trie(int a);
    QChart * statistique_chart();
    QString notif();
  /*  void SetReminder(const wchar_t, int );*/
};

#endif // EVENT_H
