#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "book.h"
#include "client.h"
#include "clientlist.h"
#include "booklist.h"
#include "issuedbooks.h"
#include <QMapIterator>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_4_currentTextChanged(const QString &arg1);

private:
    void reloadBooksCombo();
    void reloadClientsCombo();
    void reloadIssuedCombo();


    Ui::Widget *ui;
    BookList bookList;
    ClientList clientList;
    IssuedBooks issueList;
};

#endif // WIDGET_H
