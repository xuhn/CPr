#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    calc_flag = -1;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_push_button_num1_clicked()
{
    if ( calc_flag == -1 )
    {
        first_num.append(ui->push_button_num1->text());
        ui->label_display->setText(first_num);
    }
    else
    {
        second_num.append(ui->push_button_num1->text());
        ui->label_display->setText(second_num);
    }
}

void Widget::on_push_button_num2_clicked()
{
    if ( calc_flag == -1 )
    {
        first_num.append(ui->push_button_num2->text());
        ui->label_display->setText(first_num);
    }
    else
    {
        second_num.append(ui->push_button_num2->text());
        ui->label_display->setText(second_num);
    }
}

// 抽象 分层


void Widget::on_push_button_equal_clicked()
{
    //取number1 内容
    float number1 = first_num.toFloat();

    //取number2 内容
    float number2 = second_num.toFloat();

    float result;

    //判断符号
    switch (calc_flag)
    {
    //计算
    case 0:
        result = number1 + number2;
        break;
    case 1:
        result = number1 - number2;
        break;
    case 2:
        result = number1 * number2;
        break;
    case 3:
        if (number2 == 0)
        {
            QMessageBox::about(this, "warning", "number2 == 0 error!");
            return;
        }

        result =number1 / number2;
        break;
    }

    //把result的值放入 line_edit_result
    ui->label_display->setText(QString::number(result));
    calc_flag = -1;
    first_num.clear();
    second_num.clear();
}


void Widget::on_push_button_add_clicked()
{
    calc_flag = 0;
}


void Widget::on_push_button_min_clicked()
{
    calc_flag = 1;
}

