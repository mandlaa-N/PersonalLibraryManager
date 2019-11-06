#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include <QMap>
#include "client.h"

class ClientList : public QMap<QString, Client*>
{
public:
    ClientList();
};

#endif // CLIENTLIST_H
