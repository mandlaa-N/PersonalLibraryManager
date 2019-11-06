#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //Add book slot.
    Book *b = new Book(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->doubleSpinBox->value());

    bookList.insert(b->getTitle(), b);

    reloadBooksCombo();
}

void Widget::on_pushButton_2_clicked()
{
    //Add client slot
    Client *c = new Client("Name of client", QDate::currentDate());

    clientList.insert("Name of client", c);
    reloadClientsCombo();
}

void Widget::on_pushButton_3_clicked()
{
    //Issue book slot
    if(ui->comboBox->currentText() != ""  && ui->comboBox_2->currentText() != "")
    {
        //Check if book alread exists for client.
        QString title = ui->comboBox_2->currentText();
        QString client = ui->comboBox->currentText();

        issueList.insertMulti(client, title);

        reloadIssuedCombo();
    }
}

void Widget::on_pushButton_4_clicked()
{
    //Return book slot

    //Do if else to check both are selected.
    QString client = ui->comboBox_4->currentText();
    QString book = ui->comboBox_3->currentText();

    QMap<QString, QString>::iterator i = issueList.find(client);

    while(i != issueList.end())
    {
        if(i.value() == book)
        {
           i = issueList.erase(i);
           break;
        }

        ++i;
    }

    reloadIssuedCombo();
}

void Widget::on_pushButton_5_clicked()
{
    //List issued

    ui->textEdit->setText("");

    QStringList allText;

    QMapIterator<QString, QString> i(issueList);
    while(i.hasNext())
    {
        i.next();
        allText << i.key() + ", " + i.value();

    }

    ui->textEdit->setText(allText.join("\n"));
}

void Widget::reloadBooksCombo()
{
    ui->comboBox_2->clear();

    QStringList l(bookList.keys());

    ui->comboBox_2->addItems(l);
}

void Widget::reloadClientsCombo()
{
    ui->comboBox->clear();
    QStringList l(clientList.keys());
    ui->comboBox->addItems(l);
}

void Widget::reloadIssuedCombo()
{
    ui->comboBox_4->clear();
    QStringList list(issueList.keys());
    ui->comboBox_4->addItems(list);
}

void Widget::on_comboBox_4_currentTextChanged(const QString &arg1)
{
    // find all books belonging to client arg1
    QList<QString> clientBooks = issueList.values(arg1);
    QStringList list(clientBooks);

    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(list);
}
