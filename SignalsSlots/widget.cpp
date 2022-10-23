#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->aPushButton, SIGNAL(clicked()), this, SLOT(changeA()));
    connect(ui->bPushButton, &QPushButton::clicked, this, &Widget::changeB);
    connect(ui->cPushButton, &QPushButton::clicked, [=]{
        ui->cLabel->setText("Functor Lambda Notation");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeA(){
   ui->aLabel->setText("String Notation");
}

void Widget::changeB(){
   ui->bLabel->setText("Functor Notation");
}

