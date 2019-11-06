#include "client.h"

Client::Client(QString n, QDate j)
{
    name = n;
    joinDate = j;
}

QString Client::getName()
{
    return name;
}

QDate Client::getJoinDate()
{
    return joinDate;
}
