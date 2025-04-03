#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , money(0)
{
    ui->setupUi(this);
    updateButtons();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
    updateButtons();
}

void Widget::updateButtons() {
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbMilk->setEnabled(money >= 150);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbReset_clicked()
{
    int fiveHundred = money / 500;
    int oneHundred = (money % 500) / 100;
    int fifty = (money % 100) / 50;
    int ten = (money % 50) / 10;

    QString message = QString("500원: %1개\n100원: %2개\n50원: %3개\n10원: %4개")
                          .arg(fiveHundred)
                          .arg(oneHundred)
                          .arg(fifty)
                          .arg(ten);
    QMessageBox::information(this, "잔돈", message);

    money = 0;
    ui->lcdNumber->display(money);
    updateButtons();
}
