#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_push_button_num1_clicked();

    void on_push_button_equal_clicked();

    void on_push_button_add_clicked();

    void on_push_button_num2_clicked();

    void on_push_button_min_clicked();

private:
    Ui::Widget *ui;
    QString first_num;
    QString second_num;
    int calc_flag;
};
#endif // WIDGET_H
