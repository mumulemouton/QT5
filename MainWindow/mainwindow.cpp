#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QStatusBar>
#include <QMenuBar>
#include <QAction>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("Button");
    setCentralWidget(button);
    QAction* quitAction = new QAction("Quit");
    connect(quitAction, &QAction::triggered,[=](){
        QApplication::quit();
    });
    QMenu* fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("File");
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    statusBar()->showMessage("Uploading file...",3000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(800,500);
}

