#include "shop.h"
#include "stastic.h"
Shop::Shop(QWidget *parent)
    : QWidget{parent}
{//初始化屏幕大小及购买标记
setFixedSize(800,500);
    isbuy1=0;
    isbuy2=0;
    isbuy3=0;
//加载图片
    QPixmap  stone_(CYCLE_MINE);
    QPixmap hub_( HUB_BIG_PATH );
    QPixmap money_(":/picture/increase_mine.png");
    QPixmap return_(":/picture/return.png");
     have=QPixmap(":/picture/have.png");
//设置四个按钮
    stone_button = new QPushButton(this);
     stone_button->setGeometry(76, 149, 100, 100);
     stone_button->setIcon(QIcon( stone_));
     stone_button->setIconSize( stone_.size()/2);
     stone_button->show();

    hub_button = new QPushButton(this);
    hub_button->setGeometry(310, 149, 100, 100);
    hub_button->setIcon(QIcon(hub_));
    hub_button->setIconSize(hub_.size()/10);
    hub_button->show();

    money_button = new QPushButton(this);
    money_button->setGeometry(550, 149, 100,100);
    money_button->setIcon(QIcon(money_));
    money_button->setIconSize(money_.size()/2);
    money_button->show();

     return_button = new QPushButton(this);
     return_button->setGeometry(658, 340, 90,100);
    return_button->setIcon(QIcon( return_));
     return_button->setIconSize( return_.size()/2);
     return_button->show();

//设置文字
    QSize labelSize(800, 50);
   shop_w = new QLabel(this);
    shop_w->setText(QString("商店"));
    shop_w->move(350, 30); // 设置位置，可以根据实际情况调
    shop_w->setFixedSize(labelSize);
    QFont font1;
    font1.setPointSize(40); // 设置字体大小为20像素
    shop_w->setFont(font1);

   money_w = new QLabel(this);
    money_w->setText(QString("矿物涨价"));
   money_w->move(550, 260); // 设置位置，可以根据实际情况调
    money_w->setFixedSize(labelSize);
    QFont font;
    font.setPointSize(20); // 设置字体大小为20像素
    money_w->setFont(font);

    money_m = new QLabel(this);
    money_m->setText(QString("需要金币：200"));
    money_m->move(550, 290); // 设置位置，可以根据实际情况调
    money_m->setFixedSize(labelSize);
    money_m->setFont(font);

    hub_w = new QLabel(this);
    hub_w->setText(QString("扩建交付中心"));
   hub_w->move(283, 260); // 设置位置，可以根据实际情况调
    hub_w->setFixedSize(labelSize);
    hub_w->setFont(font);


    hub_m = new QLabel(this);
   hub_m->setText(QString("需要金币：300"));
    hub_m->move(283, 290); // 设置位置，可以根据实际情况调
    hub_m->setFixedSize(labelSize);
    hub_m->setFont(font);

   mine_w = new QLabel(this);
    mine_w->setText(QString("增加矿地"));
    mine_w->move(76, 260); // 设置位置，可以根据实际情况调
    mine_w->setFixedSize(labelSize);
    mine_w->setFont(font);

    mine_m = new QLabel(this);
    mine_m->setText(QString("需要金币：400"));
   mine_m->move(76, 290); // 设置位置，可以根据实际情况调
    mine_m->setFixedSize(labelSize);
    mine_m->setFont(font);


    return_w = new QLabel(this);
    return_w->setText(QString("返回游戏"));
    return_w->move(662, 428); // 设置位置，可以根据实际情况调
    return_w->setFixedSize(labelSize);
    QFont font2;
    font2.setPointSize(20); // 设置字体大小为20像素
    return_w->setFont(font2);

}

void Shop::paintEvent(QPaintEvent *event)//绘图
{
    Q_UNUSED(event);
    QPainter painter(this);
    //如果买过了在相应位置打对号
    if(isbuy1)//money
    {
     painter.drawPixmap(600,200,100,100,have);
    }
    if(isbuy2)//hub
    {
        painter.drawPixmap(360,200,100,100,have);
    }
    if(isbuy3)//stone
    {
        painter.drawPixmap(126,200,100,100,have);
    }


}
