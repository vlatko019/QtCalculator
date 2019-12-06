#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    logic(new CalculatorLogic(this))
{
    ui->setupUi(this);
    ui->lineEdit_display->setValidator(new QRegExpValidator(QRegExp("[+-]?[1-9]\\d+\\.\\d{2}")));
    this->setWindowTitle("CALCULATOR 3000");
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_equals, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_squareRoot, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_changeSign, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_changeSign, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_return, SIGNAL(clicked()), this, SLOT(onBtnClicked()));

    connect(logic, SIGNAL(resultChanged(QString)), this, SLOT(onResultChanged()));
    connect(logic, SIGNAL(resultHistoryChanged(QString)), this, SLOT(onResultHistoryChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete logic;
}

void MainWindow::onBtnClicked(){
    QObject *sndr = sender();
    logic->doCommand(sndr->objectName());
    if(sndr->objectName().mid(11, sndr->objectName().length()-11) != "equals") onResultChanged();
    else onResultHistoryChanged();
}

void MainWindow::onResultChanged()
{
    ui->lineEdit_display->setText(QString::number(logic->getNumber()));
}

void MainWindow::onResultHistoryChanged(){
    ui->plainTextEdit_history->appendPlainText(logic->getResult());
    ui->lineEdit_display->setText(QString::number(logic->getNumber()));
}

