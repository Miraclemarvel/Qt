#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    setMouseTracking(true);
}

//鼠标进入事件
void myLabel::enterEvent(QEvent *){
    //qDebug() << "鼠标进入了!";
};

//鼠标离开事件
void myLabel::leaveEvent(QEvent *){
    //qDebug() << "鼠标离开了!";
};

//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev){
    //buttons联合按键
    //if(ev->buttons() & Qt::LeftButton){
        QString str = QString("鼠标移动了 x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str.toUtf8().data();
    //}
};
//鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev){
    //if(ev->button() == Qt::LeftButton){
        QString str = QString("鼠标按下了 x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str.toUtf8().data();
    //};
};
//鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev){
    //if(ev->button() == Qt::LeftButton){
        QString str = QString("鼠标释放了 x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str.toUtf8().data();

    //}
};

bool myLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        QString str = QString("Event函数中 鼠标按下了 x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str.toUtf8().data();
        return true; //true代表用户自己处理这个事件, 不用向下分发
    }

    //其他事假交给父类处理(默认处理)
    return QLabel::event(e);
};
