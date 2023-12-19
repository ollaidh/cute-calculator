#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QPushButton *> buttonList = findChildren<QPushButton *>();

    for (QPushButton *button : buttonList) {
        connect(button, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refreshLabels()
{
    ui->num1Label->setText(QString::fromStdString(m_engine.number1()));
    ui->num2Label->setText(QString::fromStdString(m_engine.number2()));
    ui->opLabel->setText(QString::fromStdString(m_engine.op()));
    ui->stateLabel->setText(QString::fromStdString(m_engine.state()));

}

void MainWindow::onButtonClicked()
{
    static std::map <std::string, char> digitButtons = {
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
    static std::map <std::string, char> operatorButtons = {
        {"plusPushButton", '+'},
        {"minusPushButton", '-'},
        {"multPushButton", '*'},
        {"divPushButton", '/'},
        {"eqPushButton", '='},
        {"cleanPushButton", 'C'},
        {"backPushButton", 'B'},

    };

    QPushButton *senderButton = qobject_cast<QPushButton*>(sender());
    Q_ASSERT(senderButton != nullptr);
    std::string buttonName = (senderButton->objectName()).toStdString();
    qDebug() << "Button clicked: " << buttonName;  // optional - to show in debugger
    if (digitButtons.find(buttonName) != digitButtons.end()) {
        m_engine.addDigit(digitButtons[buttonName]);
    }
    else if (operatorButtons.find(buttonName) != operatorButtons.end()) {
        m_engine.addOperator(operatorButtons[buttonName]);

    }

    refreshLabels();
}

