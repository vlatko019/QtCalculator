#ifndef CALCULATORLOGIC_H
#define CALCULATORLOGIC_H

#include <QObject>

class CalculatorLogic : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorLogic(QObject *parent = nullptr);

    void doCommand(QString);
    double getNumber();
    QString getResult();

private:
    double _result;
    double _number;
    double _parameter;
    double _parameter2;
    int _digit = 0;
    bool _point = false;
    QString _operation;

signals:
    bool resultChanged(QString);
    bool resultHistoryChanged(QString);

public slots:
    void setNumber(double);
};

#endif // CALCULATORLOGIC_H
