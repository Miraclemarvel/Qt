#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

//Teacher类 老师类
//Student类 学生类
//下课后, 老师会触发一个信号, 饿了, 学生响应信号, 请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->t = new Teacher(this);
    this->s = new Student(this);

    //老师饿了, 学生请客的连接
    //connect(t, &Teacher::hungry, s, &Student::treat);
    //连接带参数的信号和槽
    //指针 -> 地址
    //函数指针 -> 函数地址
    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;
    connect(t, teacherSignal, s, studentSlot);
    //classIsOver();

//    //点击一下下课的按钮,再触发下课
      QPushButton *btn = new QPushButton("下课", this);
      setFixedSize(600, 600);
      //点击按钮, 触发下课
      connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

//    //无参信号和槽连接
//    void(Teacher::*teacherSignal2)(void) = &Teacher::hungry;
//    void(Student::*studentSlot2)(void) = &Student::treat;
//    connect(t, teacherSignal2, s, studentSlot2);

//    //信号连接信号
//    connect(btn, &QPushButton::clicked, t, teacherSignal2);

//    //断开连接
//    disconnect(t, teacherSignal2, s, studentSlot2);

      //利用lambda函数, 实现点击按钮, 关闭窗口
      QPushButton *btn2 = new QPushButton("关闭", this);
      btn2->move(300, 300);
      connect(btn2, &QPushButton::clicked, this, [=]()mutable{
          btn2->setText("哈?");
          //this->close();
      });



}

void Widget::classIsOver(){
    //下课函数, 调用后, 触发老师饿了的信号
    //emit t->hungry();
    emit t->hungry("宫保鸡丁");
};

Widget::~Widget()
{
    delete ui;
}

