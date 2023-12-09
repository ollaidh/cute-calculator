#include <QCoreApplication>
#include <iostream>
#include <QtTest>

#include "engine_tests.h"


class TestRunner
{
    Q_DISABLE_COPY_MOVE(TestRunner)
public:
    TestRunner() :
        m_failedTestCount(0){ }

    template <typename T>
    void runTests()
    {
        T member;
        int result = QTest::qExec(&member);
        QThread::msleep(100);
        m_failedTestCount += result;
    }

    int failedTestCount() const
    {
        return m_failedTestCount;
    }

private:
    int m_failedTestCount;
};

int main(int argc, char *argv[])
{
    EngineTests runner;
    return QTest::qExec(&runner);

}
