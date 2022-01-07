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


void Widget::on_push_button_calculate_clicked()
{
    // 取line_edit_number1 内容
     float number1 = ui->line_edit_number1->text().toFloat();

    // 取line_edit_number2 内容
     float number2 = ui->line_edit_number2->text().toFloat();

     float result;

     // 取符号
     int index = ui->combo_box_operator->currentIndex();

     // 判断符号
     switch (index)
     {
     // 计算
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
         if ( number2 == 0 )
         {
             QMessageBox::about(this, "warning", "number2 == 0 error!");
             return;
         }

         result = number1 / number2;
         break;
     }

    // 把result的值放入 line_edit_result
    ui->line_edit_result->setText(QString::number(result));

}

