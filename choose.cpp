#include "choose.h"
#include "stastic.h"
Choose::Choose(QWidget *parent)
    : QWidget{parent}
{

    //设置三个选择按钮
    setFixedSize(800,500);
    QPixmap belt_(BELT_BUTTON_PATH);
    QPixmap cutter_(CUTTER_BUTTON_PATH);
     QPixmap miner_(MINER_BUTTON_PATH);
    belt_button = new QPushButton(this);
    belt_button->setGeometry(124, 202, 100, 100);
    belt_button->setIcon(QIcon(belt_));
    belt_button->setIconSize(belt_.size()/2);
    belt_button->show();

    cutter_button = new QPushButton(this);
   cutter_button->setGeometry(342, 202, 100, 100);
    cutter_button->setIcon(QIcon(cutter_));
    cutter_button->setIconSize(cutter_.size()/2);
    cutter_button->show();

    miner_button = new QPushButton(this);
    miner_button->setGeometry(557, 202, 100,100);
    miner_button->setIcon(QIcon(miner_));
    miner_button->setIconSize(miner_.size()/2);
    miner_button->show();

//设置文字
    QSize labelSize(800, 50);
    Label = new QLabel(this);
    Label->setText(QString("恭喜过关！请选择你想加速的设备"));
    Label->move(10, 100); // 设置位置，可以根据实际情况调
    Label->setFixedSize(labelSize);
    QFont font;
    font.setPointSize(40); // 设置字体大小为20像素
    Label->setFont(font);

}


