#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QDebug>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QDockWidget>
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)   
{
    //重置窗口大小
    resize(600, 400);
    //菜单栏 只能最多有一个
    //只能建一个的不需要new
    //菜单栏创建
    //QMenuBar *b = new QMenuBar(this);
    QMenuBar *bar = menuBar();  //menuBar()函数本身就会new一个指针, 返回值直接接受就好
    //将菜单栏放入到窗口中
    setMenuBar(bar);

    //创建菜单
    auto *ret = bar->addMenu("文件");
    auto *ret1 = bar->addMenu("编辑");

    //创建菜单项目
    ret->addAction("新建");
    //添加分隔符
    ret->addSeparator();
    ret->addAction("打开");




    //工具栏   可以有多个
    QToolBar *toolbar = new QToolBar(this);

    //枚举值
//    Constant Value
//    Qt::LeftToolBarArea   0x1
//    Qt::RightToolBarArea  0x2
//    Qt::TopToolBarArea    0x4
//    Qt::BottomToolBarArea 0x8
//    Qt::AllToolBarAreas   ToolBarArea_Mask
//    Qt::NoToolBarArea     0

    addToolBar(Qt::LeftToolBarArea, toolbar);

    //后期设置只允许左右停靠
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    //设置浮动
    toolbar->setFloatable(false);

    //设置移动(总开关)
    toolbar->setMovable(false);

    //工具栏可以设置内容
    toolbar->addAction("新建");
    //添加分割线
    toolbar->addSeparator();
    toolbar->addAction("打开");

    //工具栏可以添加控件
    QPushButton *btn = new QPushButton("aa", this);
    toolbar->addWidget(btn);




    //状态栏 最多有一个
    auto *stBar = statusBar();
    //设置到窗口中
    setStatusBar(stBar);
    //放标签控件
    QLabel *label = new QLabel("提示的信息", this);
    stBar->addWidget(label);

    QLabel *label2 = new QLabel("右侧提示的信息", this);
    stBar->addPermanentWidget(label2);




    //铆接部件(浮动窗口)可以有多个
    QDockWidget *dockWidget = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    //设置后期停靠区域,只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);



    //只有一个的用set, 可以有多个的用add
    //设置中心部件, 只能有一个
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);




}

MainWindow::~MainWindow()
{
}

