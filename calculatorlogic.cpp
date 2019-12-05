#include "calculatorlogic.h"
#include "math.h"

CalculatorLogic::CalculatorLogic(QObject *parent) : QObject(parent)
{
    setNumber(0);
}

void CalculatorLogic::setNumber(double number){
    _number = number;
}

double CalculatorLogic::getNumber(){
    return _number;
}

QString CalculatorLogic::getResult(){
    QString operacija;
    if (_operation == "plus") operacija = "+";
    if (_operation == "minus") operacija = "-";
    if (_operation == "divide") operacija = "/";
    if (_operation == "multiply") operacija = "*";
    if (_operation == "squareRoot") operacija = "√";
    return _operation == "squareRoot" ? operacija + QString::number(_parameter2) + "=" + QString::number(_result):QString::number(_parameter) + operacija + QString::number(_parameter2) + "=" + QString::number(_result);
}

void CalculatorLogic::doCommand(QString command){
    QString cmd = command.mid(11, command.length()-11);

    if (cmd == "point"){
        _point = true;
    }

    //printf("%c\n", cmd[0].toLatin1());
    if ((cmd[0] >= '0') && (cmd[0] <= '9')){
        if(!_point){
            _number *= 10;
            _number += (cmd[0].toLatin1()-48);
        } else {
            _number += (cmd[0].toLatin1()-48)/pow(10,++_digit);
        }
    }

    if(cmd == "clear"){
        _number = 0;
        _point = false;
        _digit = 0;
    }

    if (cmd == "changeSign")
        _number = -_number;

    if (cmd == "return"){
        QString broj = QString::number(_number);
        broj = broj.mid(0, broj.length()-1);
        _number = broj.toDouble();
    }

    if (cmd == "plus" || cmd == "minus" || cmd == "divide" || cmd == "multiply" || cmd == "squareRoot"){
        _parameter = _number;
        if(cmd != "squareRoot") _number = 0;
        _point = false;
        _digit = 0;
        _operation = cmd;
    }

    if (cmd == "equals"){
        _parameter2 = _number;
        if (_operation == "plus"){
            _result = _parameter + _parameter2;
        }

        if (_operation == "minus"){
            _result = _parameter - _parameter2;
        }

        if (_operation == "divide"){
            _result = _parameter / _parameter2;
        }

        if (_operation == "multiply"){
            _result = _parameter * _parameter2;
        }

        if (_operation == "squareRoot"){
            _result = sqrt(_parameter);
        }
        _number = _result;
    }


    //printf("%f\n", _number);

    //printf("%s\n", cmd.toLatin1().data());

}
