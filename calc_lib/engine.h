#include <iostream>


class Engine
{
    enum State
    {
        GettingNumber1,
        GettingNumber2,
        CalcResult,
        UndefinedResult
    };

public:
    Engine();
    void addDigit(char digit);
    void addOperator(char op);
    std::string calc();

    std::string number1() const;

    std::string number2() const;

    std::string op() const;

    std::string state() const;

private:
    std::string m_number1;
    std::string m_number2;
    char m_op;

    State m_state;

    void shrinkPeriods();


};
