#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat(){
    qDebug() << "请老师吃饭\n";
    qDebug() << "老师, 我也饿了";
}

void Student::treat(QString foodName){
    //QString -> char* 先转成QByteArray (.toUtf8()), 再转成char*(.data())
    qDebug().nospace() << "请老师吃饭, 老师要吃:" << foodName.toUtf8().data();
}
