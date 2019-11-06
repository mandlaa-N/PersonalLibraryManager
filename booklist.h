#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <QMap>
#include "book.h"

class BookList : public QMap<QString, Book*>
{
public:
    BookList();
};

#endif // BOOKLIST_H
