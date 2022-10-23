#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Widget::setWindowTitle("Guess my number");
    ui->scoreLabel->setText("Score: " + QString::number(number));
    numberGenerator(&number);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::refreshScore(){
  ui->scoreLabel->setText("Score: " + QString::number(score));
}
void Widget::numberGenerator(int* n){
    srand(time(NULL));
    *n = rand() % 10 + 1;
    qDebug() << "Secret Number generated: " << *n << "/n";
}

void Widget::on_checkButton_clicked()
{
 if(ui->spinBox->value() == number ){
     ui->trueFalseLlabel->setText("You won!");
     score ++;
     refreshScore();
     numberGenerator(&number);
 } else {
     ui->trueFalseLlabel->setText("Try again!");
 }
}

