#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ButtonCalc_clicked()
{
    double num1 = ui->lineEditNum1->text().toDouble();//获取num1的值
    double num2 = ui->lineEditNum2->text().toDouble();//获取num2的值
    double result = num1 + num2;

    ui->lineEditSum->setText(QString::number(result));
}

