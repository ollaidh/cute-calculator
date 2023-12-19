#include <iostream>


class Engine
{

public:

    enum State
    {
        GettingNumber1,
        GettingNumber2,
        ResultCalculated,
        UndefinedResult
    };

    Engine();
    void addDigit(char digit);
    void addOperator(char op);
    std::string calculate();

    std::string number1() const;

    std::string number2() const;

    std::string op() const;

    State state() const;

private:
    std::string m_number1;
    std::string m_number2;
    char m_op;

    State m_state;

    void shrinkPeriods();


};
