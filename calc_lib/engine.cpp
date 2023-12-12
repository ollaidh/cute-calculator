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
    if (m_state == State::GettingNumber1)
    {
        m_state = State::GettingNumber2;
    }
    else
    {
        m_state = State::GettingNumber1;
    }
    if (op == '=') {
        std::string temp = m_number2;
        m_number2 = std::to_string(calc());
        m_number2.erase ( m_number2.find_last_not_of('0') + 1, std::string::npos );
        m_number2.erase ( m_number2.find_last_not_of('.') + 1, std::string::npos );
        m_number1 = temp;
    }
    m_op = op;


}

double Engine::calc()
{
    if (m_op == '+') {
        return std::stod(m_number1) + std::stod(m_number2);
    }
    else if (m_op == '-') {
        return std::stod(m_number1) - std::stod(m_number2);
    }
    else if (m_op == '*') {
        return std::stod(m_number1) * std::stod(m_number2);
    }
    else if (m_op == '/') {
        return std::stod(m_number1) / std::stod(m_number2);
    }
    else {
        return 0;
    }
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
