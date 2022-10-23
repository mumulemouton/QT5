#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->move(200,200);
    connect(button, &QPushButton::clicked,[=](){
        /*
        QMessageBox message;
        message.setMinimumSize(300,200);
        message.setWindowTitle("Message Box");
        message.setText("Something happened");
        message.setInformativeText("Choose an action:");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);
        int ret = message.exec();
        */
        int ret = QMessageBox::critical(this, "Message Box", "Something happend. Choose an action:",
                                     (QMessageBox::Ok | QMessageBox::Cancel));
        if (ret == QMessageBox::Ok){
            qDebug() << "User clicked on OK";
        } else {
            qDebug() << "User clicked on Cancel";
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

