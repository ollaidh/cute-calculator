#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->onePushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->twoPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->threePushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->fourPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->fivePushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->sixPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->sevenPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->eightPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->ninePushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->zeroPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->periodPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);

    connect(ui->plusPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->minusPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->multPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->divPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->eqPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);

    connect(ui->cleanPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->backPushButton, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refreshLabels()
{
    ui->num1_label->setText(QString::fromStdString(m_engine.number1()));
    ui->num2_label->setText(QString::fromStdString(m_engine.number2()));
    ui->op_label->setText(QString::fromStdString(m_engine.op()));
    ui->state_label->setText(QString::fromStdString(m_engine.state()));

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
        {"zeroPushButton", '0'},
        {"periodPushButton", '.'}
    };
    std::map <std::string, char> operator_buttons = {
        {"plusPushButton", '+'},
        {"minusPushButton", '-'},
        {"multPushButton", '*'},
        {"divPushButton", '/'},
        {"eqPushButton", '='},
        {"cleanPushButton", 'C'},
        {"backPushButton", 'B'},

    };

    std::vector <std::string> clean_buttons = {"cleanPushButton", "backPushButton"};

    QPushButton *senderButton = qobject_cast<QPushButton*>(sender());
    Q_ASSERT(senderButton != nullptr);
    QString buttonName = senderButton->objectName();
    qDebug() << "Button clicked: " << buttonName;  // optional - to show in debugger
    if (digit_buttons.find(buttonName.toStdString()) != digit_buttons.end()) {
        m_engine.addDigit(digit_buttons[buttonName.toStdString()]);
    }
    else if (operator_buttons.find(buttonName.toStdString()) != operator_buttons.end()) {
        m_engine.addOperator(operator_buttons[buttonName.toStdString()]);

    }

    refreshLabels();
}

