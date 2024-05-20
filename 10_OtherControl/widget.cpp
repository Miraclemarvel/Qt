#include "widget.h"
#include "ui_widget.h"
#include<QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //栈控件使用
    //设置默认定位为scrollArea
    ui->stackedWidget->setCurrentIndex(1);

    //scrollArea按钮
    connect(ui->btn_scrollArea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //toolBox按钮
    connect(ui->btn_ToolBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //TabWidget按钮
    connect(ui->btn_TabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");
    //选中拖拉机
    connect(ui->btn_select, &QPushButton::clicked, [=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("拖拉机");
    });

    //利用label显示图片
    ui->lbl_Image->setPixmap(QPixmap("C:/Users/Miracle/Desktop/9V(XB63TU[4D0)[7I01DA@A.jpg"));

    //利用QLabel显示gif动态图片
    QMovie *movie = new QMovie("C:/Users/Miracle/Desktop/v2-477658d4dc01c675b7d5781363061ff1_720w.gif");
    ui->lbl_Image->setMovie(movie);
    //播放动图
    movie->start();


}

Widget::~Widget()
{
    delete ui;
}

