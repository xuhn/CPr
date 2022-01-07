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


void Widget::on_pushButton_clicked()
{

    QLineEdit* numEdit[5] = {ui->lineEditNum1, ui->lineEditNum2, ui->lineEditNum3, ui->lineEditNum4, ui->lineEditNum5};

    int len = 5;

    int minIndex;
    QLineEdit* tempQLE;
        for (int i = 0; i < len - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < len; j++) {
                if (numEdit[j]->text().toInt() < numEdit[minIndex]->text().toInt()) {     // 寻找最小的数
                    minIndex = j;                 // 将最小数的索引保存
                }
            }

            tempQLE = numEdit[i];
            numEdit[i] = numEdit[minIndex];
            numEdit[minIndex] = tempQLE;
            aniStop = 0;
              // swap

            QPoint a = numEdit[i]->pos();
            QPoint b = numEdit[minIndex]->pos();

            QPropertyAnimation* animation = new QPropertyAnimation(numEdit[i], "geometry");
            animation->setDuration(4000);
            animation->setStartValue(QRect(a, QSize(numEdit[i]->width(), numEdit[i]->height())));
            animation->setEndValue(QRect(b, QSize(numEdit[i]->width(), numEdit[i]->height())));
            animation->start(QAbstractAnimation::DeleteWhenStopped);

            QPropertyAnimation* animation2 = new QPropertyAnimation(numEdit[minIndex], "geometry");
            animation2->setDuration(4000);
            animation2->setStartValue(QRect(b, QSize(numEdit[minIndex]->width(), numEdit[minIndex]->height())));
            animation2->setEndValue(QRect(a, QSize(numEdit[minIndex]->width(), numEdit[minIndex]->height())));
            animation2->start(QAbstractAnimation::DeleteWhenStopped);

            connect(animation, &QPropertyAnimation::finished,this,[=](){
                aniStop = 1;
            });

            while(!aniStop){
                Sleep(40);
            }

        }


}

void Widget::Sleep(int msec)
{

    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

