#include "engine.h"

Engine::Engine()
{
    m_state = State::GettingNumber1;
}

void Engine::addDigit(char digit)
{
    if (m_state == State::GettingNumber1) {
        m_number1.push_back(digit);
    }
    else if (m_state == State::GettingNumber2) {
        m_number2.push_back(digit);
    }
    else if (m_state == State::CalcResult) {
        m_number1 = m_number2;
        m_state = State::GettingNumber2;
        m_number2 = "";
        m_number2.push_back(digit);
    }
}

void Engine::addOperator(char op)
{
    if (op == 'C') {
        m_number1 = "";
        m_number2 = "";
        m_op = '\0';
        m_state = State::GettingNumber1;
        return;
    }
    if (op == 'B') {
        if (m_state == State::CalcResult) {
            m_number2 = "";
            m_state = State::GettingNumber2;
        }
        else if (m_state == State::GettingNumber1) {
           m_number1 = "";
        }
        else if (m_state == State::GettingNumber2) {
           m_number2 = "";
        }
        return;

    }

    if (m_state == State::GettingNumber2 && op != '=') {
        if (m_number1 != "" and m_number2 != ""){
            m_number1 = std::to_string(calc());
            m_number1.erase ( m_number1.find_last_not_of('0') + 1, std::string::npos );
            m_number1.erase ( m_number1.find_last_not_of('.') + 1, std::string::npos );
        }
    }
    if (op == '=') {
        if (m_number1 != "" and m_number2 == "") {
            m_number2 = "0";
            m_op = '+';
        }
        if (m_number1 != "" and m_number2 != "") {
            m_number1 = std::to_string(calc());
            m_number1.erase ( m_number1.find_last_not_of('0') + 1, std::string::npos );
            m_number1.erase ( m_number1.find_last_not_of('.') + 1, std::string::npos );
            m_state = State::CalcResult;
        }

    }
    else {
        m_op = op;
        m_number2 = "";
        m_state = State::GettingNumber2;
    }
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

