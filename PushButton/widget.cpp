#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont buttonFont("Times", 20, QFont::Bold);
    QPushButton* button = new QPushButton(this);
    button->setText("Button");
    button->setMinimumSize(200,100);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked,[=](){
        qDebug() << "Button pressed";
            });


}

Widget::~Widget()
{
    delete ui;
}

