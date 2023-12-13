#include <iostream>


class Engine
{
public:
    Engine();
    void addDigit(char digit);
    void addOperator(char op);
    double calc();

    std::string number1() const;

    std::string number2() const;

    char op() const;

private:
    std::string m_number1;
    std::string m_number2;
    char m_op;
    enum class State
    {
        GettingNumber1,
        GettingNumber2,
        CalcResult
    };
    State m_state;

};
