#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include"widget1.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("Open", this);
    setFixedSize(600,600);

    Widget1 *w1 = new Widget1();
    w1->setWindowTitle("New Window");
    connect(btn, &QPushButton::clicked, this, [=](){
        if(btn->text() == "Open"){
            btn->setText("Close");
            w1->show();
        }
        else{
            btn->setText("Open");
            w1->hide();
        }
    });

}

Widget::~Widget()
{
    delete ui;
}

