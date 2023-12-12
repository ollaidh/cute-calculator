#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->onePushButton, &QAbstractButton::clicked, this, &MainWindow::onePushButton_clicked);
//    connect(ui->twoPushButton, &QAbstractButton::clicked, this, &MainWindow::twoPushButton_clicked);
    connect(ui->onePushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->twoPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->threePushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->fourPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->fivePushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->sixPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->sevenPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->eightPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->ninePushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->zeroPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->plusPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->minusPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->multPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->divPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->cleanPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refreshLabels()
{
    ui->num1_label->setText(QString::fromStdString(m_engine.number1()));
    ui->num2_label->setText(QString::fromStdString(m_engine.number2()));
}

void MainWindow::onButtonClicked()
{
    std::map <std::string, char> digit_buttons = {
        {"onePushButton", '1'},
        {"twoPushButton", '2'},
        {"threePushButton", '3'},
        {"fourPushButton", '4'},
        {"fivePushButton", '5'},
        {"sixPushButton", '6'},
        {"sevenPushButton", '7'},
        {"eightPushButton", '8'},
        {"ninePushButton", '9'},
        {"zeroPushButton", '0'}
    };
    std::map <std::string, char> operator_buttons = {
        {"plusPushButton", '+'},
        {"minusPushButton", '-'},
        {"multPushButton", '*'},
        {"divPushButton", '/'},
    };

    std::vector <std::string> clean_buttons = {"cleanPushButton", "backPushButton"};

    QPushButton *senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton) {
        QString buttonName = senderButton->objectName();
        qDebug() << "Button clicked: " << buttonName;  // optional - to show in debugger
        if (digit_buttons.find(buttonName.toStdString()) != digit_buttons.end()) {
            m_engine.addDigit(digit_buttons[buttonName.toStdString()]);
        }
        else if (operator_buttons.find(buttonName.toStdString()) != operator_buttons.end()) {
            m_engine.addOperator(digit_buttons[buttonName.toStdString()]);
        }
//        else {
//            m_engine.
//        }
    }
    refreshLabels();
}

