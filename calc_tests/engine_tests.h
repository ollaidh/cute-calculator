#include <QtTest>

class EngineTests : public QObject
{
    Q_OBJECT
public:
    explicit EngineTests(QObject *parent = nullptr);

private slots:
    void basicTest();
    void onlyFirstNumberTest();
    void numberWithPeriodTest();
    void twoOperatorsInaRowTest();
    void divisionByZeroTest();
};
