#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->onePushButton, &QAbstractButton::clicked, this, &MainWindow::onePushButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onePushButton_clicked()
{
    ui->onePushButton->setText("ONE");
    input_symbols.append("1");
    ui->label->setText(QString::fromStdString(input_symbols));

}

