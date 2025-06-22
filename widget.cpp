#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(800,500);

    // 创建按钮
    start = new QPushButton("开始游戏", this);
    conti = new QPushButton("继续游戏", this);
    end = new QPushButton("退出游戏", this);
    // 设置按钮位置和大小
    start->setGeometry(50, 350, 200, 110);
    conti->setGeometry(300, 350, 200, 110);
    end->setGeometry(550, 350, 200, 110);
    // 连接按钮的点击事件到槽函数
    connect(start, &QPushButton::clicked, this, &Widget::fstart);
    connect(conti, &QPushButton::clicked, this, &Widget::fconti);
    connect(end, &QPushButton::clicked, this, &Widget::fend);



    // 创建和布局文本框、标签和按钮
    label = new QLabel("异形工厂", this);
    label->setStyleSheet("font-size: 150px;");//设置字体大小
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label); // 将标签添加到布局中
    // 设置布局到窗口中央上侧
    QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer);
    layout->setAlignment(label, Qt::AlignHCenter); // 将标签居中对齐
    // 将布局设置到主窗口
    setLayout(layout);




}

Widget::~Widget()
{
    delete ui;
}

void Widget::fstart()
{
    gameInterface = new GameInterface;
    gameInterface->show();
    this->hide(); // 可选：隐藏当前窗口，如果您希望完全切换
}

void Widget::fconti()
{
    qDebug() << "Button clicked!";
}


void Widget::fend()
{
    close();
}

