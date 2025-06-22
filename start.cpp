#include "start.h"

Start::Start(QWidget *parent)
    : QWidget(parent)

{


    setFixedSize(800,500);

    // 创建按钮
    starting = new QPushButton("开始游戏", this);
    conti = new QPushButton("继续游戏", this);
    end = new QPushButton("退出游戏", this);
    // 设置按钮位置和大小
    starting->setGeometry(50, 350, 200, 110);
    conti->setGeometry(300, 350, 200, 110);
    end->setGeometry(550, 350, 200, 110);


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

Start::~Start()
{
   delete starting;
    delete  conti;
   delete   end;
    delete label;


}


