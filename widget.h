#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int money{0}; // member variable
    void changeMoney(int diff); // member function
    void updateButtons();

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbReset_clicked();

    void on_pbMilk_clicked();

    void on_pbTea_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
