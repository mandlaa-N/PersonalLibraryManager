#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book
{
public:
    Book(QString t, QString a, double c);
    QString getTitle();
    QString getAuthor();
    double getCost();

private:
    QString title;
    QString author;
    double cost;


};

#endif // BOOK_H
