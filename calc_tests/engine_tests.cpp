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
    QCOMPARE(engine.number1(), "5");
    QCOMPARE(engine.number2(), "47");
    QCOMPARE(engine.op(), '=');



}
