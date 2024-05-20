#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QTime>
#include<QMouseEvent>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    id1 = startTimer(1000);   //参数1 间隔 单位毫秒

    id2 = startTimer(2000);

    //定时器的第二种方式
    QTimer *timer = new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        static int num2 = 1;
        ui->label_4->setText(QString::number(num2++));
    });

    ui->pushButton_2->hide();
    //点击暂停停止计时
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        timer->stop();
        ui->pushButton->hide();
        ui->pushButton_2->show();
    });

    //点击继续计时
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        timer->start(500);
        ui->pushButton->show();
        ui->pushButton_2->hide();
    });

    //给label1安装事件过滤器
    //1.安装过滤器
    ui->label->installEventFilter(this);

}
//2.重写事件过滤器
bool Widget::eventFilter(QObject* obj, QEvent *e){
    if(obj == ui->label){
        if(e->type() == QEvent::MouseButtonPress){
            QMouseEvent *ev = static_cast<QMouseEvent *>(e);
            QString str = QString("事件过滤器中 鼠标按下了 x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str.toUtf8().data();

            return true; //true代表用户自己处理这个事件, 不用向下分发
        }
    }
    //其他默认处理
    return QWidget::eventFilter(obj, e);
}

void Widget::timerEvent(QTimerEvent *e){
    static int num = 1;


    //label2每隔一秒+1
    if(e->timerId() == id1){
        ui->label_2->setText(QString::number(num++));
        ui->label_5->setText(QDateTime::currentDateTime().toString());
    }

    //label2每隔两秒+1
    static int num1 = 1;
    if(e->timerId() == id2){
            ui->label_3->setText(QString::number(num1++));
    }

}


Widget::~Widget()
{
    delete ui;
}

