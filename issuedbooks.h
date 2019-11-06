#ifndef ISSUEDBOOKS_H
#define ISSUEDBOOKS_H

#include <QMap>
#include <QString>

class IssuedBooks : public QMap<QString, QString>
{
public:
    IssuedBooks();
};

#endif // ISSUEDBOOKS_H
