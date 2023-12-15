#include "engine_tests.h"
#include "engine.h"


EngineTests::EngineTests(QObject *parent)
    : QObject{parent}
{

}

void EngineTests::basicTest()
{
    Engine engine;
    engine.addDigit('4');
    engine.addDigit('2');
    engine.addOperator('+');
    engine.addDigit('5');


    QCOMPARE(engine.number1(), "42");
    QCOMPARE(engine.number2(), "5");
    QCOMPARE(engine.op(), '+');

    engine.addOperator('=');
    QCOMPARE(engine.number1(), "47");
    QCOMPARE(engine.number2(), "5");
    QCOMPARE(engine.op(), '+');

    engine.addOperator('-');
    engine.addDigit('1');
    engine.addDigit('7');
    engine.addOperator('=');
    QCOMPARE(engine.number2(), "17");
    QCOMPARE(engine.number1(), "30");
    QCOMPARE(engine.op(), '-');

    engine.addOperator('=');
    QCOMPARE(engine.number2(), "17");
    QCOMPARE(engine.number1(), "13");
    QCOMPARE(engine.op(), '-');

    engine.addOperator('C');
    QCOMPARE(engine.number2(), "");
    QCOMPARE(engine.number1(), "");
    QCOMPARE(engine.op(), '\0');

    engine.addDigit('1');
    engine.addDigit('0');
    engine.addOperator('*');
    QCOMPARE(engine.op(), '*');
    QCOMPARE(engine.number1(), "10");
    engine.addDigit('5');
    engine.addOperator('B');

    QCOMPARE(engine.op(), '*');
    QCOMPARE(engine.number1(), "10");
    QCOMPARE(engine.number2(), "");
    engine.addDigit('2');
    engine.addDigit('0');
    engine.addOperator('=');
    QCOMPARE(engine.number2(), "20");
    QCOMPARE(engine.number1(), "200");
    QCOMPARE(engine.op(), '*');

    engine.addOperator('B');
    QCOMPARE(engine.number2(), "");
    QCOMPARE(engine.number1(), "200");
    QCOMPARE(engine.op(), '*');


}

void EngineTests::onlyFirstNumberTest()
{
    Engine engine;

    engine.addDigit('2');
    engine.addDigit('0');
    engine.addOperator('=');

    QCOMPARE(engine.number2(), "0");
    QCOMPARE(engine.number1(), "20");

    engine.addOperator('=');

    QCOMPARE(engine.number2(), "0");
    QCOMPARE(engine.number1(), "20");
}

void EngineTests::numberWithPeriodTest()
{
    Engine engine;

    engine.addDigit('2');
    engine.addDigit('0');
    engine.addDigit('.');
    engine.addOperator('=');

    QCOMPARE(engine.number2(), "0");
    QCOMPARE(engine.number1(), "20");

    engine.addOperator('+');
    engine.addDigit('1');
    engine.addDigit('5');
    engine.addDigit('.');
    engine.addDigit('.');
    engine.addOperator('=');

    QCOMPARE(engine.number1(), "35");
    QCOMPARE(engine.number2(), "15");
}
