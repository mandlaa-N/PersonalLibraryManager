#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>

class Client
{
public:
    Client(QString n, QDate j);
    QString getName();
    QDate getJoinDate();

private:
    QString name;
    QDate joinDate;
};

#endif // CLIENT_H
