#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Cute Calculator by Ollaidh");

    // All buttons have the same type QPushButton, so use findChildren to get list of all pushButtons:
    QList<QPushButton *> buttonList = findChildren<QPushButton *>();

    // Connect all pushButtons:
    for (QPushButton *button : buttonList) {
        connect(button, &QAbstractButton::clicked, this, &MainWindow::onButtonClicked);
    }

    // Set right + center verticcal alignments for labels:
    ui->num1Label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    ui->num2Label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    // Make bold font and set it for result label:
    QFont resultFont;
    resultFont.setBold(true);
    resultFont.setPixelSize(25);
    ui->num1Label->setFont(resultFont);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refreshLabels()
{
    static std::map<Engine::State, std::string> stateRepresentation = {
        {Engine::GettingNumber1, "GettingNumber1"},
        {Engine::GettingNumber2, "GettingNumber2"},
        {Engine::ResultCalculated, "ResultCalculated"},
        {Engine::UndefinedResult, "UndefinedResult"}
    };

    if (m_engine.state() == Engine::UndefinedResult) {
        ui->num1Label->setText(QString::fromStdString("Division by zero: Undefined"));
    }
    else {
        ui->num1Label->setText(QString::fromStdString(m_engine.number1()));
    }
    ui->num2Label->setText(QString::fromStdString(m_engine.number2()));
    ui->opLabel->setText(QString::fromStdString(m_engine.op()));
    ui->stateLabel->setText(QString::fromStdString(stateRepresentation[m_engine.state()]));

}


void MainWindow::enableArithmeticButtons(bool enable)
{
    ui->plusPushButton->setEnabled(enable);
    ui->minusPushButton->setEnabled(enable);
    ui->multPushButton->setEnabled(enable);
    ui->divPushButton->setEnabled(enable);

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

    if (m_engine.state() == Engine::UndefinedResult) {
        enableArithmeticButtons(false);
    }
    else {
        enableArithmeticButtons(true);
    }
}

