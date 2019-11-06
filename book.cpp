#include "book.h"


Book::Book(QString t, QString a, double c)
{
    title = t;
    author = a;
    cost = c;
}

QString Book::getTitle()
{
    return title;
}

QString Book::getAuthor()
{
    return author;
}

double Book::getCost()
{
    return cost;
}
