#include "mywidget.h"
#include "QPushButton" //按钮控件的头文件
#include "mypushbutton.h"
//命名规范
//类名 首字母大写, 单词和单词之间首字母大写
//函数名 变量名称 首字母小写, 单词和单词之间首字母大写

//快捷键
//注释 ctrl + /
//允许 ctrl + r
//编译 ctrl + b
//字体缩放 ctrl + 鼠标滚轮
//查找 ctrl + f
//整行移动 ctrl + shift + ↑或者↓
//帮助文档 F1
//自动对齐 ctrl + i
//同名之间的.h和.cpp切换 F4

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //btn->show(); //以顶层方式弹出窗口控件
    //让btn对象 依赖在myWidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮 按控件的大小创建窗口
    QPushButton * btn2 = new QPushButton("第二个按钮", this);

    //移动btn2按钮
    btn2->move(100, 100);

    //重置按钮大小
    btn2->resize(100, 50);

    //创建一个自己的按钮对象
    MyPushButton * mybtn = new MyPushButton;
    mybtn->setText("我自己的按钮");

    mybtn->move(200, 0);
    mybtn->setParent(this); //设置到对象树中

    //重置窗口大小
    resize(600, 400);

    //设置固定窗口大小
    setFixedSize(600, 400);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //需求 点击按钮一 关闭窗口
    //connect(信号的发送者, 发送的具体信号, 信号的接受者, 信号的处理(槽))
    //参数1 信号的发送者, 参数2 发送的信号(函数的地址), 参数3 信号的处理者, 参数4 槽函数
    //发送的信号: clicked: 点击; pressed: 点(松之前); released: 松; toggled: 切换
    //connect(btn, &QPushButton::clicked, this, &QPushButton::close);
    connect(btn, &QPushButton::clicked, this, &QWidget::close);

}

myWidget::~myWidget()
{
}

