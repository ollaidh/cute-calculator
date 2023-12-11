#include "engine.h"

Engine::Engine()
{
    m_state = State::GettingNumber1;
}

void Engine::addDigit(char digit)
{
    if (m_state == State::GettingNumber1)
    {
        m_number1.push_back(digit);
    }
    else
    {
        m_number2.push_back(digit);
    }

}

void Engine::addOperator(char op)
{
    m_op = op;
    m_state = State::GettingNumber2;
}

std::string Engine::number1() const
{
    return m_number1;
}

std::string Engine::number2() const
{
    return m_number2;
}

char Engine::op() const
{
    return m_op;
}
