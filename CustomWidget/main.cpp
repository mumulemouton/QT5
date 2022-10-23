#include "customwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomWidget w;
    w.show();
    //w.setWindowTitle("set from main.cpp");
    return a.exec();
}
