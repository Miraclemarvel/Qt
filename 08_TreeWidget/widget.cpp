#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget数控件使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");

    QTreeWidgetItem *litem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *mitem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem *zhitem = new QTreeWidgetItem(QStringList() << "智力");
    //加载顶层的节点
    ui->treeWidget->addTopLevelItem((litem));
    ui->treeWidget->addTopLevelItem((mitem));
    ui->treeWidget->addTopLevelItem((zhitem));

    //追加子节点
    QStringList heroL1;
    heroL1 << "刚被猪" << "前排坦克, 能在吸收上海的同时造成可观的范围输出";
    QTreeWidgetItem *li = new QTreeWidgetItem(heroL1);
    litem->addChild(li);

}

Widget::~Widget()
{
    delete ui;
}

