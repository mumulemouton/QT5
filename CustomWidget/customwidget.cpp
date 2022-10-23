#include "customwidget.h"
#include <QLabel>
CustomWidget::CustomWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Custom Widget Window");
    QLabel * label = new QLabel("Custom Widget Label",this);
}
