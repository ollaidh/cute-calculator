#include "engine_tests.h"


EngineTests::EngineTests(QObject *parent)
    : QObject{parent}
{

}

void EngineTests::dummyTest()
{
    QCOMPARE(42, 42);
}
