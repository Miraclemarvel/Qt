#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QImage>
#include<QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //Pixmap绘图设备  专门为平台做了显示的优化
//    QPixmap pix(300, 300);

//    //填充颜色
//    pix.fill(Qt::transparent);

//    //声明画家
//    QPainter painter(&pix);

//    painter.setPen(QPen(Qt::cyan));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    //保存
//    pix.save("E:\\pix.png");

//    //QImage绘图设备  可以对像素点进行访问
//    QImage img(300, 300, QImage::Format_RGB32);
//    img.fill(Qt::white);

//    //声明画家
//    QPainter painter(&img);

//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    //保存
//    img.save("E:\\img.png");

    //picture绘图设备  可以记录和重新绘制绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);  //开始往pic上画

    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(150, 150), 100, 100);

    painter.end();

    //保存到磁盘
    pic.save("E:\\pic.sk");




}

void Widget::paintEvent(QPaintEvent *){
//    QPainter painter(this);

//    //利用QImage对像素进行修改
//    QImage img;
//    img.load(":/Elysia.jpg");
//    //修改像素点
//    for(int i = 50; i < 100; i++){
//        for(int j = 50; j < 100; j++){
//            QRgb value = qRgb(255, 0, 0);
//            img.setPixel(i, j, value);
//        }
//    }

//    painter.drawImage(0, 0, img);

    //重现QPicture的绘图指令
    QPainter painter(this);

    QPicture pic;
    pic.load("E:\\pic.sk");
    painter.drawPicture(0, 0, pic);


}

Widget::~Widget()
{
    delete ui;
}

