#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* firstNameLabel = new QLabel("First Name",this);
    firstNameLabel->setMinimumSize(70,50);
    firstNameLabel->move(10,10);
    QLineEdit* firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->move(100,10);
    QLabel* lastNameLabel = new QLabel("Last Name", this);
    lastNameLabel->setMinimumSize(70,50);
    lastNameLabel->move(10,70);
    QLineEdit* lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200,50);
    lastNameLineEdit->move(100,70);
    QPushButton* button = new QPushButton(this);
    button->setText("Send");
    QFont buttonFont("Times", 20, QFont::Bold);
    button->setFont(buttonFont);
    button->move(100,130);
    connect(button, &QPushButton::clicked,[=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        if(!firstName.isEmpty() && !lastName.isEmpty()){
        qDebug() << "First Name: " << firstName;
        qDebug() << "Last Name: " << lastName;
        } else {
            qDebug() << "One field is empty";
        }
    });
    connect(firstNameLineEdit, &QLineEdit::cursorPositionChanged,[=](){
        qDebug()<<"The current cursor position is: " << firstNameLineEdit->cursorPosition();
    });
}

Widget::~Widget()
{
}

