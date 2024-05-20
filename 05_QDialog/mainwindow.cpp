#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮, 谈出一个对话框
    connect(ui->actionnew, &QAction::triggered, [=](){
        //对话框 分类
        //模态对话框(不可以对其他窗口进行操作)  非模态对话框(可以对其他窗口进行操作)
        //模态创建 阻塞
//        QDialog dig(this);
//        dig.resize(200, 100);
//        dig.exec();

//        qDebug() << "模态对话框弹出了";
        //非模态创建
//        QDialog *dig2 = new QDialog(this);
//        dig2->resize(200,300);
//        dig2->show();
//        dig2->setAttribute(Qt::WA_DeleteOnClose); //55号

//        qDebug() << "非模态的对话框弹出了";

        //消息对话框(模态)
        //错误对话框
        //QMessageBox::critical(this, "critical", "错误");
        //信息对话框
        //QMessageBox::information(this, "info", "信息");
        //提问对话框
        //参数1: 父亲; 参数2: 标题; 参数3:提示内容; 参数4: 按键类型; 参数5: 默认关联回车按键
//        if(QMessageBox::Save == QMessageBox::question(this, "ques", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel)){
//            qDebug() << "用户点击了保存";
//        }
//        else{
//            qDebug() << "用户点击了取消";
//        }
        //警告对话框
        //QMessageBox::warning(this, "warning", "警告");


        //其他标准对话框
        //颜色对话框
//        auto ret = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << "r = " << ret.red() << "g = " << ret.green() << "b = " << ret.blue();

        //文件对话框  参数1: 父亲; 参数2: 标题; 参数3: 默认打开路径; 参数4:过滤文件格式
        //返回的是选取的路径
//        auto ret = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\Miracle\\Desktop", "(*.txt)");
//        qDebug() << ret;

        //字体对话框
        bool flag;
        auto ret = QFontDialog::getFont(&flag, QFont("华文彩云", 36));
        qDebug()<< "字体:" << ret.family().toUtf8().data() << "字号:" << ret.pointSize() << "是否加粗:" << (ret.bold() == true ? "是" : "否") << "是否倾斜:" << (ret.italic() == true? "是" : "否");


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

