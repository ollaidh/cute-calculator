#include "engine.h"

Engine::Engine()
{
    m_state = State::GettingNumber1;
}

void Engine::shrinkPeriods() {
    if (m_number1.back() == '.') {
        m_number1.pop_back();
    }
    if (m_number2.back() == '.') {
        m_number2.pop_back();
    }
}

void Engine::addDigit(char digit)
{
    if  (m_state == State::UndefinedResult) {
        m_number1 = "";
        m_number2 = "";
        m_state = State::GettingNumber1;
    }

    if (m_state == State::GettingNumber1) {
        if (digit == '.' and m_number1.find('.') != std::string::npos) {
            return;
        }
        if (m_number1 == "0" and digit != '.') {
            m_number1 = "";
        }
        m_number1.push_back(digit);

    }
    else if (m_state == State::GettingNumber2) {
        if (digit == '.' and m_number2.find('.') != std::string::npos) {
            return;
        }
        if (m_number2 == "0" and digit != '.') {
            m_number2 = "";
        }
        m_number2.push_back(digit);
    }
    else if (m_state == State::CalcResult) {
//        m_number1 = m_number2;
        m_state = State::GettingNumber2;
        m_number2 = "";
        m_number2.push_back(digit);
    }
}

void Engine::addOperator(char op)
{
    shrinkPeriods();

    if  (m_state == State::UndefinedResult) {
        op = 'C';
    }

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

    if (m_state == State::GettingNumber2) {
        if (m_number1 != "" and m_number2 != ""){
           m_state = State::CalcResult;
           m_number1 = calc();
       }
        if (op != '=') {
           m_op = op;
        }
    }
    else if (m_state == State::GettingNumber1) {
        if (op == '=') {
            if (m_number1 != "" and m_number2 == "") {
                m_number2 = "0";
                m_op = '+';
                m_state = State::CalcResult;

            }
        }
        else {
            m_op = op;
            m_number2 = "";
            m_state = State::GettingNumber2;
        }
    }
    else if (m_state == State::CalcResult) {
        if (op == '=') {
            m_number1 = calc();
        }
        else {
            m_op = op;
            m_number2 = "";
            m_state = State::GettingNumber2;
        }
    }
}

std::string Engine::calc()
{
    std::string result;
    if (m_op == '+') {
        result = std::to_string(std::stod(m_number1) + std::stod(m_number2));
    }
    else if (m_op == '-') {
        result = std::to_string(std::stod(m_number1) - std::stod(m_number2));
    }
    else if (m_op == '*') {
        result = std::to_string(std::stod(m_number1) * std::stod(m_number2));
    }
    else if (m_op == '/') {
        if (m_number2 != "0") {
            result = std::to_string(std::stod(m_number1) / std::stod(m_number2));
        }
        else {
            result = "Division by Zero: Undefined Result";
            m_state = State::UndefinedResult;
        }
    }
    else {
        result = "";
    }
    result.erase ( result.find_last_not_of('0') + 1, std::string::npos );
    result.erase ( result.find_last_not_of('.') + 1, std::string::npos );
    return result;

}

std::string Engine::number1() const
{
    return m_number1;
}

std::string Engine::number2() const
{
    return m_number2;
}

std::string Engine::op() const
{
    if (m_op == '\0') {
        return "";
    }
    std::string result;
    result.push_back(m_op);
    return result;
}

std::string Engine::state() const
{
    if (m_state == GettingNumber1) {
        return "GettingNumber1";
    }
    if (m_state == GettingNumber2) {
        return "GettingNumber2";
    }
    if (m_state == CalcResult) {
        return "CalcResult";
    }
    if (m_state == UndefinedResult) {
        return "UndefinedResult";
    }
    return "";
}

