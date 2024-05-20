#include "smallwidget.h"
#include "ui_smallwidget.h"
#include<QSlider>
#include<QSpinBox>
#include<QDebug>

Smallwidget::Smallwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Smallwidget)
{
    ui->setupUi(this);

    //QSpinBox移动, QSlider跟着移动
    void(QSpinBox:: * spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider,  &QSlider::setValue);

    //QSlider滑动, QSpinBox跟着变化
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

    //QSlider滑动,点击按钮获取当前值
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        int val = ui->horizontalSlider->value();
        qDebug().nospace() << "当前值为:" << val;
    });

    //设置到一半
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        setNum(50);
    });


}

//设置数字
void Smallwidget::setNum(int num){
    ui->spinBox->setValue(num);
}

//获取数字
int Smallwidget::getNum(){
    return ui->spinBox->value();
}
Smallwidget::~Smallwidget()
{
    delete ui;
}
