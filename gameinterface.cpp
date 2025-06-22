#include "gameinterface.h"

GameInterface::GameInterface(int round0,int need_cycle0,int need_cycle_l0,int need_rect0,QWidget *parent)//构造函数
    : QWidget(parent)
{
    //初始化各个量
     if_stone=0;
     if_hub=0;
     if_money=2;
    placing_belt=false;
    placing_cutter=false;
    placing_trash=false;
    placing_miner=false;
    placing_eraser=false;
    currentdi="W";
    money=0;
    n_cycle=0;
    n_rect=0;
     n_cycle_l=0;
     n_cycle_r=0;
      need_cycle=need_cycle0;
      need_cycle_l=need_cycle_l0;
      need_cycle_r=0;
      need_rect=need_rect0;
      round=round0;
       v_miner=3000;
        v_cutter=500;
        v_belt=1000;
        for(int i=0;i<WIDTH;i++)
        {
            for(int j=0;j<HEIGHT;j++)
            {
                stone_map[i][j]=1;
            }
        }


    // 初始化定时器
    mineTimer = new QTimer(this);
    moveTimer=new QTimer(this);
    cutTimer=new QTimer(this);
    receiveTimer=new QTimer(this);
    connect(mineTimer, &QTimer::timeout, this, &GameInterface::generateMine);
    connect(moveTimer, &QTimer::timeout, this, &GameInterface::moveMines);
    connect(cutTimer, &QTimer::timeout, this, &GameInterface::cutMines);
    connect(receiveTimer, &QTimer::timeout, this, &GameInterface::receive);
    mineTimer->start(v_miner);
    moveTimer->start(v_belt);
    cutTimer->start(v_cutter);
    receiveTimer->start(100);
    //画网格
    setFixedSize(800,500);
    rows = HEIGHT; // 行数，留出最下方两行
    cols = WIDTH; // 列数
    setFixedSize(cols * 30, rows * 30 + 100); // 设置固定大小，确保网格填满除最下方两行外的区域
    //加载图片
    belt_button= QPixmap(":/picture/belt_button.png");
    cutter_button=QPixmap(":/picture/cutter_button.png");
    miner_button=QPixmap(":/picture/miner_button.png");
    trash_button=QPixmap(":/picture/trash_button.png");
   eraser_button=QPixmap(":/picture/eraser.png");
    hub_small = QPixmap(":/picture/hub_small.png");
    hub_big=QPixmap(HUB_BIG_PATH);
    cycle_mine = QPixmap(":/picture/cycle_mine.png");
    rect_mine = QPixmap(":/picture/rect_mine.png");
    barrier = QPixmap(":/picture/barrier.png");
    miner_p[0]=QPixmap(MINER_W_PATH);
    miner_p[1]=QPixmap(MINER_A_PATH);
    miner_p[2]=QPixmap(MINER_S_PATH);
    miner_p[3]=QPixmap(MINER_D_PATH);
    cutter_p[0]=QPixmap(CUTTER_W_PATH);
    cutter_p[1]=QPixmap(CUTTER_A_PATH);
    cutter_p[2]=QPixmap(CUTTER_S_PATH);
    cutter_p[3]=QPixmap(CUTTER_D_PATH);
    trash_p[0]=QPixmap(TRASH_W_PATH);
    trash_p[1]=QPixmap(TRASH_A_PATH);
    trash_p[2]=QPixmap(TRASH_S_PATH);
    trash_p[3]=QPixmap(TRASH_D_PATH);
    belt_p[0]=QPixmap(BELT_W_PATH);
    belt_p[1]=QPixmap(BELT_A_PATH);
    belt_p[2]=QPixmap(BELT_S_PATH);
    belt_p[3]=QPixmap(BELT_D_PATH);
    belt_p[4]=QPixmap(BELT_A_S_PATH);
    belt_p[5]=QPixmap(BELT_A_W_PATH);
    belt_p[6]=QPixmap(BELT_D_W_PATH);
    belt_p[7]=QPixmap(BELT_D_S_PATH);
    belt_p[8]=QPixmap(BELT_S_A_PATH);
    belt_p[9]=QPixmap(BELT_S_D_PATH);
    belt_p[10]=QPixmap(BELT_W_A_PATH);
    belt_p[11]=QPixmap(BELT_W_D_PATH);
    stone_p[0]=QPixmap(CYCLE_PATH);
    stone_p[1]=QPixmap(RECT_PATH);
    stone_p[2]=QPixmap(LEFT_CYCLE_PATH);
    stone_p[3]=QPixmap(RIGHT_CYCLE_PATH);
    QPixmap shop(":/picture/shop.png");
    shop_button = new QPushButton(this);
    shop_button->setGeometry(587, 450, 50, 50);
    shop_button->setIcon(QIcon(shop));
    shop_button->setIconSize(shop.size()/2);
    shop_button->show();


    // 创建QLabel用于显示各个量的值
     QSize labelSize(300, 25);
    moneyLabel = new QLabel(this);
    moneyLabel->setText(QString("金币: %1").arg(money));
    moneyLabel->move(586, 437);
    moneyLabel->setFixedSize(labelSize);

    need_c_Label = new QLabel(this);
    need_c_Label->setText(QString("需要圆形: %1").arg(need_cycle));
    need_c_Label->move(2, 426);
    need_c_Label->setFixedSize(labelSize);


   n_c_Label = new QLabel(this);
    n_c_Label->setText(QString("已采圆形: %1").arg(n_cycle));
    n_c_Label->move(667, 426);
    n_c_Label->setFixedSize(labelSize);

   need_r_Label = new QLabel(this);
    need_r_Label->setText(QString("需要方形: %1").arg(need_rect));
    need_r_Label->move(2, 450);
    need_r_Label->setFixedSize(labelSize);

    n_r_Label = new QLabel(this);
    n_r_Label->setText(QString("已采方形: %1").arg(n_rect));
    n_r_Label->move(667, 450);
   n_r_Label->setFixedSize(labelSize);

    need_c_l_Label = new QLabel(this);
    need_c_l_Label->setText(QString("需要左半边圆形: %1").arg(need_cycle_l));
    need_c_l_Label->move(2, 472);
    need_c_l_Label->setFixedSize(labelSize);

   n_c_l_Label = new QLabel(this);
    n_c_l_Label->setText(QString("已采左半边圆形: %1").arg(n_cycle_l));
    n_c_l_Label->move(667, 472);
    n_c_l_Label->setFixedSize(labelSize);

    need_c_r_Label = new QLabel(this);
    need_c_r_Label->setText(QString("需要右半边圆形: %1").arg(need_cycle_r));
    need_c_r_Label->move(2, 495);
   need_c_r_Label->setFixedSize(labelSize);

   n_c_r_Label = new QLabel(this);
    n_c_r_Label->setText(QString("已采右半边圆形: %1").arg(n_cycle_r));
    n_c_r_Label->move(667, 495);
    n_c_r_Label->setFixedSize(labelSize);

    round_Label = new QLabel(this);
    round_Label->setText(QString("关卡: %1").arg(round));
    round_Label->move(10, 10);
    QFont font;
    font.setPointSize(20); // 设置字体大小为20像素
    round_Label->setFont(font);


}

GameInterface::~GameInterface()// 清理资源
{
    delete mineTimer ;
   delete moveTimer;
   delete cutTimer;
   delete receiveTimer;
   delete shop_button;
   delete  moneyLabel;
   delete need_c_Label;
   delete n_c_Label;
   delete need_r_Label;
   delete n_r_Label;
   delete need_c_l_Label;
   delete n_c_l_Label;
   delete need_c_r_Label;
   delete n_c_r_Label;
   delete round_Label;

}
void GameInterface::paintEvent(QPaintEvent *event)//绘图
{
    Q_UNUSED(event);
    QPainter painter(this);
    drawGrid(&painter);
//画几个设备的按钮
    painter.drawPixmap(100,450,50,50,cutter_button);
    painter.drawPixmap(200,450, 50, 50,belt_button);
    painter.drawPixmap(300,450,50, 50, miner_button);
    painter.drawPixmap(400,450,50, 50,trash_button);
    painter.drawPixmap(500,450,50, 50,eraser_button);



    //画垃圾桶
    for(const Trash& trash : trashs)
    {
        QPixmap *trashpicture1=nullptr;
        if(trash.getdi()=="W")
        {
            trashpicture1=&trash_p[0];
        }
        else if(trash.getdi()=="A")
        {
            trashpicture1=&trash_p[1];
        }
        else if(trash.getdi()=="S")
        {
            trashpicture1=&trash_p[2];
        }
        else if(trash.getdi()=="D")
        {
            trashpicture1=&trash_p[3];
        }
        if(trashpicture1)
        {
            painter.drawPixmap(trash.getx()*30,trash.gety()*30,30,30,*trashpicture1);

        }
    }
    //画cutter
    for(const Cutter& cutter : cutters)
    {
        QPixmap *cutterpicture1=nullptr;
        if(cutter.getdi()=="W")
        {
            cutterpicture1=&cutter_p[0];
            painter.drawPixmap(cutter.getx()*30,cutter.gety()*30,60,30,*cutterpicture1);
        }
        else if(cutter.getdi()=="A")
        {
            cutterpicture1=&cutter_p[1];
            painter.drawPixmap(cutter.getx()*30,cutter.gety()*30,30,60,*cutterpicture1);
        }
        else if(cutter.getdi()=="S")
        {
            cutterpicture1=&cutter_p[2];
            painter.drawPixmap(cutter.getx()*30,cutter.gety()*30,60,30,*cutterpicture1);
        }
        else if(cutter.getdi()=="D")
        {
            cutterpicture1=&cutter_p[3];
            painter.drawPixmap(cutter.getx()*30,cutter.gety()*30,30,60,*cutterpicture1);
        }

    }
    //画传送带
    for(const Belt& belt : belts)
    {
        QPixmap *beltpicture1=nullptr;
        if(belt.getdi()=="W")
        {
            beltpicture1=&belt_p[0];
        }
        else if(belt.getdi()=="A")
        {
            beltpicture1=&belt_p[1];
        }
        else if(belt.getdi()=="S")
        {
            beltpicture1=&belt_p[2];
        }
        else if(belt.getdi()=="D")
        {
            beltpicture1=&belt_p[3];
        }
        else if(belt.getdi()=="AS")
        {
            beltpicture1=&belt_p[4];
        }
        else if(belt.getdi()=="AW")
        {
            beltpicture1=&belt_p[5];
        }
        else if(belt.getdi()=="DW")
        {
            beltpicture1=&belt_p[6];
        }
        else if(belt.getdi()=="DS")
        {
            beltpicture1=&belt_p[7];
        }
        else if(belt.getdi()=="SA")
        {
            beltpicture1=&belt_p[8];
        }
        else if(belt.getdi()=="SD")
        {
            beltpicture1=&belt_p[9];
        }
        else if(belt.getdi()=="WA")
        {
            beltpicture1=&belt_p[10];
        }
        else if(belt.getdi()=="WD")
        {
            beltpicture1=&belt_p[11];
        }
        if(beltpicture1)
        {
            painter.drawPixmap(belt.getx()*30,belt.gety()*30,30,30,*beltpicture1);


        }}
//画矿石
    for(const Stone& stone : stones)
    {
        QPixmap *stonepicture1=nullptr;
        if(stone.get_type()==CYCLE)
        {
            stonepicture1=&stone_p[0];
        }
        else if(stone.get_type()==RECT)
        {
            stonepicture1=&stone_p[1];
        }
        else if(stone.get_type()==LEFT_CYCLE)
        {
            stonepicture1=&stone_p[2];
        }
        else if(stone.get_type()==RIGHT_CYCLE)
        {
            stonepicture1=&stone_p[3];
        }
        if(stonepicture1)
        {
            painter.drawPixmap(stone.getx()*30+5,stone.gety()*30+5,20,20,*stonepicture1);

        }
    }

//画交付中心
    if(if_hub)
    {
        painter.drawPixmap(384,175, 130,128, hub_big);
        map0.improve();
    }
    else
    {
        painter.drawPixmap(382,173, 80,78, hub_small);
    }
//画矿地
    painter.drawPixmap(90, 120, 30, 30, cycle_mine);
    painter.drawPixmap(120, 120, 30, 30, cycle_mine);
    painter.drawPixmap(90, 150, 30, 30, cycle_mine);
    painter.drawPixmap(90, 90, 30, 30, cycle_mine);
    painter.drawPixmap(60, 150, 30, 30, cycle_mine);
    painter.drawPixmap(120, 150,30, 30, cycle_mine);
    painter.drawPixmap(150, 120, 30,30, cycle_mine);

    painter.drawPixmap(600, 330, 30,30, rect_mine);
    painter.drawPixmap(600, 360, 30, 30, rect_mine);
    painter.drawPixmap(630, 360,30,30, rect_mine);
    painter.drawPixmap(660,330, 30, 30,rect_mine);
    painter.drawPixmap(630, 300, 30,30,rect_mine);
    painter.drawPixmap(660, 360, 30, 30, rect_mine);
    painter.drawPixmap(660, 300, 30,30, rect_mine);

    if(if_stone)
    {
        map.improve();
        painter.drawPixmap(570, 60, 30, 30, cycle_mine);
        painter.drawPixmap(570, 90, 30, 30, cycle_mine);
        painter.drawPixmap(600, 60, 30, 30, cycle_mine);
        painter.drawPixmap(600, 90, 30, 30, cycle_mine);
        painter.drawPixmap(630, 60, 30, 30, cycle_mine);
        painter.drawPixmap(540, 90,30, 30, cycle_mine);
        painter.drawPixmap(540, 120, 30,30, cycle_mine);

        painter.drawPixmap(60, 330, 30,30, rect_mine);
        painter.drawPixmap(60, 300, 30, 30, rect_mine);
        painter.drawPixmap(60, 360,30,30, rect_mine);
        painter.drawPixmap(90,300, 30, 30,rect_mine);
        painter.drawPixmap(90, 330, 30,30,rect_mine);
        painter.drawPixmap(120, 330, 30, 30, rect_mine);
        painter.drawPixmap(120, 360, 30,30, rect_mine);


    }

    painter.drawPixmap(267,177, 38, 38, barrier);
    painter.drawPixmap(297, 267,38, 38, barrier);
    painter.drawPixmap(357, 147, 38,38, barrier);
    painter.drawPixmap(357, 297, 38,38, barrier);
    painter.drawPixmap(537, 237, 38, 38, barrier);
    painter.drawPixmap(567, 297, 38, 38, barrier);


    //画采矿机
    for(const Miner& miner : miners)
    {
        QPixmap *minerpicture1=nullptr;
        if(miner.getdi()=="W")
        {
            minerpicture1=&miner_p[0];
        }
        else if(miner.getdi()=="A")
        {
            minerpicture1=&miner_p[1];
        }
        else if(miner.getdi()=="S")
        {
            minerpicture1=&miner_p[2];
        }
        else if(miner.getdi()=="D")
        {
            minerpicture1=&miner_p[3];
        }
        if(minerpicture1)
        {
            painter.drawPixmap(miner.getx()*30,miner.gety()*30,30,30,*minerpicture1);

        }

    }

    //画各个设备拖拽时的动画
    if(placing_miner)
    {
        QPixmap *minerpicture=nullptr;
        if(currentdi=="W")
        {
            minerpicture=&miner_p[0];
        }
        else if(currentdi=="A")
        {
            minerpicture=&miner_p[1];
        }
        else if(currentdi=="S")
        {
            minerpicture=&miner_p[2];
        }
        else if(currentdi=="D")
        {
            minerpicture=&miner_p[3];
        }
        if(minerpicture)
        {
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,30,30,*minerpicture);
        }
    }
    if(placing_trash)
    {
        QPixmap *trashpicture=nullptr;
        if(currentdi=="W")
        {
            trashpicture=&trash_p[0];
        }
        else if(currentdi=="A")
        {
            trashpicture=&trash_p[1];
        }
        else if(currentdi=="S")
        {
            trashpicture=&trash_p[2];
        }
        else if(currentdi=="D")
        {
            trashpicture=&trash_p[3];
        }
        if(trashpicture)
        {
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,30,30,*trashpicture);
        }
    }
    if(placing_cutter)
    {
        QPixmap *cutterpicture=nullptr;
        if(currentdi=="W")
        {
            cutterpicture=&cutter_p[0];
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,60,30,*cutterpicture);
        }
        else if(currentdi=="A")
        {
           cutterpicture=&cutter_p[1];
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,30,60,*cutterpicture);
        }
        else if(currentdi=="S")
        {
            cutterpicture=&cutter_p[2];
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,60,30,*cutterpicture);
        }
        else if(currentdi=="D")
        {
            cutterpicture=&cutter_p[3];
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,30,60,*cutterpicture);
        }

    }
    if(placing_belt)
    {
        QPixmap *beltpicture=nullptr;
        if(currentdi=="W")
        {
            beltpicture=&belt_p[0];
        }
        else if(currentdi=="A")
        {
            beltpicture=&belt_p[1];
        }
        else if(currentdi=="S")
        {
            beltpicture=&belt_p[2];
        }
        else if(currentdi=="D")
        {
            beltpicture=&belt_p[3];
        }
        else if(currentdi=="AS")
        {
            beltpicture=&belt_p[4];
        }
        else if(currentdi=="AW")
        {
            beltpicture=&belt_p[5];
        }
        else if(currentdi=="DW")
        {
            beltpicture=&belt_p[6];
        }
        else if(currentdi=="DS")
        {
            beltpicture=&belt_p[7];
        }
        else if(currentdi=="SA")
        {
            beltpicture=&belt_p[8];
        }
        else if(currentdi=="SD")
        {
            beltpicture=&belt_p[9];
        }
        else if(currentdi=="WA")
        {
            beltpicture=&belt_p[10];
        }
        else if(currentdi=="WD")
        {
            beltpicture=&belt_p[11];
        }
        if(beltpicture)
        {
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,30,30,*beltpicture);
        }
    }


    if(placing_eraser)
    {
        QPixmap *eraserpicture=nullptr;

            eraserpicture=&eraser_button;
            painter.drawPixmap(currentPos.x()-15,currentPos.y()-15,60,30,*eraserpicture);


    }

}

void GameInterface::drawGrid(QPainter *painter)
{
    painter->setPen(Qt::gray);

    // 绘制网格
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            painter->drawRect(j * 30, i * 30, 30, 30);
        }
    }
}

void GameInterface::mousePressEvent(QMouseEvent *event)
{

    if(event->button() == Qt::LeftButton)
    {
    qDebug()<<(event->pos().x());
    qDebug()<<(event->pos().y());
    //点击了清除器按钮
    if((event->pos().x()>500)&&(event->pos().x()<541)&&(event->pos().y()>450)&&(event->pos().y()<491))
    {
        placing_eraser=true;
        startPos=event->pos();
        currentPos=event->pos();
        update();//重新绘制
    }
    //点击了垃圾桶按钮
    if((event->pos().x()>400)&&(event->pos().x()<441)&&(event->pos().y()>450)&&(event->pos().y()<491))
    {
         placing_trash=true;
        startPos=event->pos();
        currentPos=event->pos();
        update();//重新绘制
    }
   // 点击了采矿机按钮
    if((event->pos().x()>300)&&(event->pos().x()<342)&&(event->pos().y()>450)&&(event->pos().y()<491))
    {
         placing_miner=true;
         startPos=event->pos();
         currentPos=event->pos();
         update();//重新绘制
    }
    //点击了传送带按钮
    if((event->pos().x()>200)&&(event->pos().x()<242)&&(event->pos().y()>450)&&(event->pos().y()<491))
    { placing_belt=true;
        startPos=event->pos();
        currentPos=event->pos();
        update();//重新绘制
    }
    //点击了切割机按钮
    if((event->pos().x()>100)&&(event->pos().x()<144)&&(event->pos().y()>450)&&(event->pos().y()<491))
    {
         placing_cutter=true;
        startPos=event->pos();
        currentPos=event->pos();
        update();//重新绘制
    }
    }

}

void GameInterface::mouseMoveEvent(QMouseEvent *event)
{
    //图像坐标随鼠标位置变化
    if (placing_belt||placing_cutter||placing_miner||placing_trash||placing_eraser ) {
        currentPos=event->pos();
        update();//重新绘制
    }
}


void GameInterface::mouseReleaseEvent(QMouseEvent *event)//判断是否可以放置设备并放置设备
{
    if(placing_eraser)
    {
        int x=(event->pos().x())/30;
        int y=(event->pos().y())/30;
        if((!(x==13&&y==6))&&(!(x==13&&y==7))&&(!(x==14&&y==6))&&(!(x==14&&y==7)))
        {
            if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_A_L)
            {
                map0.add(event->pos().x()/30,(event->pos().y()/30)-1,-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30)&&(cutter.gety()==event->pos().y()/30-1))
                    {
                        it=cutters.erase(it);
                        qDebug()<<"dkdk";
                        break;
                    }
                }
            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_A_R)
            {
                map0.add(event->pos().x()/30,(event->pos().y()/30)+1,-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30&&cutter.gety()==event->pos().y()/30))
                    {
                        it=cutters.erase(it);qDebug()<<"dkdk";
                        break;
                    }
                }
            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_D_L)
            {
                map0.add(event->pos().x()/30,(event->pos().y()/30)+1,-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30&&cutter.gety()==event->pos().y()/30))
                    {
                        it=cutters.erase(it);break;
                    }
                }
            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_D_R)
            {
                map0.add(event->pos().x()/30,(event->pos().y()/30)-1,-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30&&cutter.gety()==event->pos().y()/30-1))
                    {
                        it=cutters.erase(it);break;
                    }
                }
            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_W_L)
            {
                map0.add(event->pos().x()/30+1,event->pos().y()/30,-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30&&cutter.gety()==event->pos().y()/30))
                    {
                        it=cutters.erase(it);break;
                    }
                }

            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_W_R)
            {
                map0.add(event->pos().x()/30-1,(event->pos().y()/30)-1,-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30-1&&cutter.gety()==event->pos().y()/30))
                    {
                        it=cutters.erase(it);break;
                    }
                }
            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_S_L)
            {
                map0.add(event->pos().x()/30-1,(event->pos().y()/30),-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30-1&&cutter.gety()==event->pos().y()/30))
                    {
                        it=cutters.erase(it);break;
                    }
                }
            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==CUTTER_S_R)
            {
                map0.add(event->pos().x()/30+1,(event->pos().y()/30),-1,"");
                for(auto it=cutters.begin();it!=cutters.end();++it)
                {
                    Cutter&cutter=*it;
                    if ((cutter.getx()==event->pos().x()/30&&cutter.gety()==event->pos().y()/30))
                    {
                        it=cutters.erase(it);break;
                    }
                }
            }

            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==MINER)
            {            for(auto it=miners.begin();it!=miners.end();++it)
                {
                    Miner&miner=*it;
                    if ((miner.getx()==event->pos().x()/30&&miner.gety()==event->pos().y()/30))
                    {
                        it=miners.erase(it);break;
                    }
                }
            }
            else if(map0.see(event->pos().x()/30,event->pos().y()/30)==BELT)
            {            for(auto it=belts.begin();it!=belts.end();++it)
                {
                    Belt&belt=*it;
                    if ((belt.getx()==event->pos().x()/30&&belt.gety()==event->pos().y()/30))
                    {
                        it=belts.erase(it);break;
                    }
                }
            }
            else  if(map0.see(event->pos().x()/30,event->pos().y()/30)==TRASH)
            {            for(auto it=trashs.begin();it!=trashs.end();++it)
                {
                    Trash&trash=*it;
                    if ((trash.getx()==x)&&(trash.gety()==y))
                    {
                        it=trashs.erase(it);
                        break;
                    }
                }
            }
            map0.add(event->pos().x()/30,event->pos().y()/30,-1,"");
            update();
        }
        placing_eraser=false;
    }
    if (placing_miner)
    {
        placing_miner=false;
        int x=(event->pos().x())/30;
        int y=(event->pos().y())/30;
        if(isMiner(x,y))
        {

            miners.emplace_back(x,y,currentdi);

                map0.add(x,y,MINER,currentdi);


        }
        update();
    }
    if (placing_trash)
    {
        placing_trash=false;
        int x=(event->pos().x())/30;
        int y=(event->pos().y())/30;
        if(cantrash(x,y))
        {

            trashs.emplace_back(x,y,currentdi);

                map0.add(x,y,TRASH,currentdi);


        }
        update();
    }
    if (placing_cutter)
    {
        placing_cutter=false;
        int x=(event->pos().x())/30;
        int y=(event->pos().y())/30;
        if(cancutter(x,y))
        {

            cutters.emplace_back(x,y,currentdi);
            if(currentdi=="W")
            {
                map0.add(x,y,CUTTER_W_L,currentdi);
                 map0.add(x+1,y,CUTTER_W_R,"");
            }
            if(currentdi=="A")
            {
                map0.add(x,y,CUTTER_A_R,"");
                 map0.add(x,y+1,CUTTER_A_L,currentdi);
            }
            if(currentdi=="S")
            {
                map0.add(x,y,CUTTER_S_R,"");
                 map0.add(x+1,y,CUTTER_S_L,currentdi);
            }
            if(currentdi=="D")
            {
                 map0.add(x,y,CUTTER_D_L,currentdi);
                 map0.add(x,y+1,CUTTER_D_R,"");
            }

        }
        update();
    }
    if (placing_belt)
    {
        placing_belt=false;
        int x=(event->pos().x())/30;
        int y=(event->pos().y())/30;
        if(cantrash(x,y))
        {

            belts.emplace_back(x,y,currentdi);

                map0.add(x,y,BELT,currentdi);
            currentdi="W";


        }
        update();
    }

}

void GameInterface::keyPressEvent(QKeyEvent *event)//改变设备方向
{
    if(placing_belt||placing_cutter||placing_miner||placing_trash )
    {
        if(event->key()==Qt::Key_W)
        {
            currentdi="W";
        }
        else if(event->key()==Qt::Key_S)
        {
            currentdi="S";
        }
        else if(event->key()==Qt::Key_A)
        {
            currentdi="A";
        }
        else if(event->key()==Qt::Key_D)
        {
            currentdi="D";
        }
        update();
    }
    if(placing_belt)
    {
        if(event->key()==Qt::Key_Q)
        {
            currentdi="WA";
        }
        else if(event->key()==Qt::Key_Z)
        {
            currentdi="SA";
        }
        else if(event->key()==Qt::Key_E)
        {
            currentdi="AW";
        }
        else if(event->key()==Qt::Key_R)
        {
            currentdi="DW";
        }
        if(event->key()==Qt::Key_T)
        {
            currentdi="WD";
        }
        else if(event->key()==Qt::Key_X)
        {
            currentdi="SD";
        }
        else if(event->key()==Qt::Key_C)
        {
            currentdi="AS";
        }
        else if(event->key()==Qt::Key_V)
        {
            currentdi="DS";
        }
        update();
    }
}

bool GameInterface::isMiner(int i,int j)//判断是否可以放采矿机
{
    return((map0.see(i,j)==-1)&&((map.see(i,j)==CYCLE)||(map.see(i,j)==RECT)));
}

bool GameInterface::cantrash(int i,int j)//判断是否可以放垃圾桶或传送带
{
    return((map.see(i,j)==NONE)&&(map0.see(i,j)==-1)&&(j<14));
}
bool GameInterface::cancutter(int i,int j)//判断是否可以放切割机
{
    if(currentdi=="W")
    {

        return((map.see(i,j)==NONE)&&(map0.see(i,j)==-1)&&(j<14)&&(map.see(i+1,j)==NONE)&&(map0.see(i+1,j)==-1));
    }
    if(currentdi=="A")
    {

        return((map.see(i,j+1)==NONE)&&(j<14)&&(map0.see(i,j+1)==-1)&&(map.see(i,j)==NONE)&&(map0.see(i,j)==-1));
    }
    if(currentdi=="S")
    {

        return((map.see(i+1,j)==NONE)&&(j<14)&&(map0.see(i+1,j)==-1)&&(map.see(i,j)==NONE)&&(map0.see(i,j)==-1));
    }
    if(currentdi=="D")
    {

        return((map.see(i,j+1)==NONE)&&(j<14)&&(map0.see(i,j+1)==-1)&&(map.see(i,j)==NONE)&&(map0.see(i,j)==-1));
    }
}

void GameInterface::generateMine()// 生成矿石的槽函数
{
    // 从每个矿工的位置生成一个矿石
    for (const auto& miner : miners)
    {

        int x=miner.getx();
        int y=miner.gety();
        if( stone_map[x][y])
        {
        stones.emplace_back(miner.getx(), miner.gety(), map.see(miner.getx(), miner.gety()),miner.getdi());
        stone_map[x][y]=0;
        }
    }
    update(); // 重新绘制
}

void GameInterface::moveMines()// 移动矿石的槽函数
{
    // 遍历所有在传送带上的的矿石，沿着传送带方向移动
    for (auto it=stones.begin();it!=stones.end();++it)
    { Stone&stone=*it;
        int x=stone.getx();
        int y=stone.gety();
        if(map0.see(stone.getx(),stone.gety())==MINER||map0.see(stone.getx(),stone.gety())==BELT)
        {
            if(stone.getdi()=="W")
            {if(map0.see(stone.getx(),stone.gety()-1)==TRASH)
                {
                    stone_map[x][y]=1;

                    it=stones.erase(it);
                    it--;
                    continue;

                }
               else if(map0.flag(stone.getx(),stone.gety()-1)=="W"&&stone_map[x][y-1])
                {

                    stone.move(stone.getx(),stone.gety()-1);
                    stone_map[x][y-1]=0;
                    stone_map[x][y]=1;
                    continue;


                }
                else if(map0.flag(stone.getx(),stone.gety()-1)=="WA"&&stone_map[x][y-1])
                {

                    stone.move(stone.getx(),stone.gety()-1);
                    stone.turn("A");
                    stone_map[x][y-1]=0;
                    stone_map[x][y]=1;
                    continue;

                }
                else if(map0.flag(stone.getx(),stone.gety()-1)=="WD"&&stone_map[x][y-1])
                {

                    stone.move(stone.getx(),stone.gety()-1);
                    stone.turn("D");
                    stone_map[x][y-1]=0;
                    stone_map[x][y]=1;
                    continue;

                } 
                else if(map0.see(stone.getx(),stone.gety()-1)==HUB)
                {stone.move(stone.getx(),stone.gety()-1);
                     stone_map[x][y]=1;
                    stone.turn("");
                     continue;

                }



            }

            else if(stone.getdi()=="S")
            {                 if(map0.see(stone.getx(),stone.gety()+1)==TRASH)
                 {
                     stone_map[x][y]=1;

                     it=stones.erase(it);
                     it--;
                     continue;

                 }
                else if(map0.flag(stone.getx(),stone.gety()+1)=="S"&&stone_map[x][y+1])
                {

                    stone.move(stone.getx(),stone.gety()+1);
                    stone_map[x][y+1]=0;
                    stone_map[x][y]=1;
                    continue;

                }
                else if(map0.flag(stone.getx(),stone.gety()+1)=="SA"&&stone_map[x][y+1])
                {

                    stone.move(stone.getx(),stone.gety()+1);
                    stone.turn("A");
                    stone_map[x][y+1]=0;
                    stone_map[x][y]=1;                    continue;

                }
                else if(map0.flag(stone.getx(),stone.gety()+1)=="SD"&&stone_map[x][y+1])
                {

                    stone.move(stone.getx(),stone.gety()+1);
                    stone.turn("D");
                    stone_map[x][y+1]=0;
                    stone_map[x][y]=1;                    continue;

                }

                else if(map0.see(stone.getx(),stone.gety()+1)==HUB)
                {
                    stone.move(stone.getx(),stone.gety()+1);
                    stone.turn("");

                    stone_map[x][y]=1;                    continue;

                }
            }
            else if(stone.getdi()=="A")
            {                if(map0.see(stone.getx()-1,stone.gety())==TRASH)
                 {
                     stone_map[x][y]=1;

                     it=stones.erase(it);
                     it--;
                     continue;


                 }
                else if(map0.flag(stone.getx()-1,stone.gety())=="A"&&stone_map[x-1][y])
                {

                    stone.move(stone.getx()-1,stone.gety());
                    stone_map[x-1][y]=0;
                    stone_map[x][y]=1;                    continue;

                }
                else if(map0.flag(stone.getx()-1,stone.gety())=="AW"&&stone_map[x-1][y])
                {

                    stone.move(stone.getx()-1,stone.gety());
                    stone.turn("W");
                    stone_map[x-1][y]=0;
                    stone_map[x][y]=1;                    continue;

                }
               else  if(map0.flag(stone.getx()-1,stone.gety())=="AS"&&stone_map[x-1][y])
                {

                    stone.move(stone.getx()-1,stone.gety());
                    stone.turn("S");
                    stone_map[x-1][y]=0;
                    stone_map[x][y]=1;                    continue;

                }

                else if(map0.see(stone.getx()-1,stone.gety())==HUB)
                {
                    stone.move(stone.getx()-1,stone.gety());
                    stone.turn("");
                    stone_map[x][y]=1;                    continue;

                }
            }
            else if(stone.getdi()=="D")
            {                 if(map0.see(stone.getx()+1,stone.gety())==TRASH)
                {
                    stone_map[x][y]=1;
                    it=stones.erase(it);
                    it--;
                    continue;


                }
                else if(map0.flag(stone.getx()+1,stone.gety())=="D"&&stone_map[x+1][y])
                {

                    stone.move(stone.getx()+1,stone.gety());
                    stone_map[x+1][y]=0;
                    stone_map[x][y]=1;                    continue;

                }
                else if(map0.flag(stone.getx()+1,stone.gety())=="DW"&&stone_map[x+1][y])
                {

                    stone.move(stone.getx()+1,stone.gety());
                    stone.turn("W");
                    stone_map[x+1][y]=0;
                    stone_map[x][y]=1;                    continue;

                }
                else if(map0.flag(stone.getx()+1,stone.gety())=="DS"&&stone_map[x+1][y])
                {

                    stone.move(stone.getx()+1,stone.gety());
                    stone.turn("S");
                    stone_map[x+1][y]=0;
                    stone_map[x][y]=1;                    continue;

                }

                else if(map0.see(stone.getx()+1,stone.gety())==HUB)
                {
                    stone.move(stone.getx()+1,stone.gety());
                    stone.turn("");
                    stone_map[x][y]=1;                    continue;


                }
            }

        }
        else  if(map0.see(stone.getx(),stone.gety())==TRASH)
        {
            stone_map[x][y]=1;

            it=stones.erase(it);
            continue;

        }

    }
    update(); // 重新绘制
}
 void GameInterface::cutMines()//切割矿石的槽函数
{//遍历所有在切割机处的矿石
     for (size_t i = 0; i <stones.size(); ++i)
     {
        Stone&stone=stones[i];
         int x=stone.getx();
         int y= stone.gety();
         if(map0.see(x,y)==CUTTER_W_L)
         {
            if(stone.get_type()==CYCLE)
             {

                 if((map0.flag(stone.getx(),stone.gety()-1)=="W")&&(map0.see(stone.getx(),stone.gety()-1)==BELT)&&(map0.see(stone.getx()+1,stone.gety()-1)==TRASH)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="W")&&stone_map[x][y-1]&&stone_map[x+1][y-1])
                 {

                     stones.emplace_back(stone.getx(), stone.gety()-1, LEFT_CYCLE,stone.getdi());
                     stone_map[x][y-1]=0;
                      stone_map[x][y]=1;


                 }
                 else  if((map0.flag(stone.getx(),stone.gety()-1)=="W")&&(map0.see(stone.getx(),stone.gety()-1)==TRASH)&&(map0.see(stone.getx()+1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="W"))
                 {


                     stones.emplace_back(stone.getx()+1, stone.gety()-1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx(),stone.gety()-1)=="W")&&(map0.see(stone.getx(),stone.gety()-1)==BELT)&&(map0.see(stone.getx()+1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="W"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()-1, LEFT_CYCLE,stone.getdi());
                     stones.emplace_back(stone.getx()+1, stone.gety()-1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }


                 else  if((map0.flag(stone.getx(),stone.gety()-1)=="WA")&&(map0.see(stone.getx(),stone.gety()-1)==BELT)&&(map0.see(stone.getx()+1,stone.gety()-1)==TRASH)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="W"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()-1, LEFT_CYCLE,"A");stone_map[x][y]=1;

                 }
                 else  if((map0.flag(stone.getx(),stone.gety()-1)=="W")&&(map0.see(stone.getx(),stone.gety()-1)==TRASH)&&(map0.see(stone.getx()+1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="WA"))
                 {


                     stones.emplace_back(stone.getx()+1, stone.gety()-1, RIGHT_CYCLE,"A");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx(),stone.gety()-1)=="WA")&&(map0.see(stone.getx(),stone.gety()-1)==BELT)&&(map0.see(stone.getx()+1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="WA"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()-1, LEFT_CYCLE,"A");
                     stones.emplace_back(stone.getx()+1, stone.gety()-1, RIGHT_CYCLE,"A");stone_map[x][y]=1;
                 }


                 else  if((map0.flag(stone.getx(),stone.gety()-1)=="WD")&&(map0.see(stone.getx(),stone.gety()-1)==BELT)&&(map0.see(stone.getx()+1,stone.gety()-1)==TRASH)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="W"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()-1, LEFT_CYCLE,"D");stone_map[x][y]=1;

                 }
                  else if((map0.flag(stone.getx(),stone.gety()-1)=="W")&&(map0.see(stone.getx(),stone.gety()-1)==TRASH)&&(map0.see(stone.getx()+1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="WD"))
                 {


                     stones.emplace_back(stone.getx()+1, stone.gety()-1, RIGHT_CYCLE,"D");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx(),stone.gety()-1)=="WD")&&(map0.see(stone.getx(),stone.gety()-1)==BELT)&&(map0.see(stone.getx()+1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()-1)=="WD"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()-1, LEFT_CYCLE,"D");
                     stones.emplace_back(stone.getx()+1, stone.gety()-1, RIGHT_CYCLE,"D");stone_map[x][y]=1;
                 }
             }
            stones.erase(stones.begin()+i);
             i--;
             update();
              continue;
            }

         else if(map0.see(x,y)==CUTTER_S_L)
         {
             if(stone.get_type()==CYCLE)
             {

                 if((map0.flag(stone.getx(),stone.gety()+1)=="S")&&(map0.see(stone.getx(),stone.gety()+1)==BELT)&&(map0.see(stone.getx()-1,stone.gety()+1)==TRASH)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="S"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()+1, LEFT_CYCLE,stone.getdi());stone_map[x][y]=1;

                 }
                  else if((map0.flag(stone.getx(),stone.gety()+1)=="S")&&(map0.see(stone.getx(),stone.gety()+1)==TRASH)&&(map0.see(stone.getx()-1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="S"))
                 {


                     stones.emplace_back(stone.getx()-1, stone.gety()+1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }
                  else if((map0.flag(stone.getx(),stone.gety()+1)=="S")&&(map0.see(stone.getx(),stone.gety()+1)==BELT)&&(map0.see(stone.getx()-1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="S"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()+1, LEFT_CYCLE,stone.getdi());
                     stones.emplace_back(stone.getx()-1, stone.gety()+1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }


                  else if((map0.flag(stone.getx(),stone.gety()+1)=="SA")&&(map0.see(stone.getx(),stone.gety()+1)==BELT)&&(map0.see(stone.getx()-1,stone.gety()+1)==TRASH)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="S"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()+1, LEFT_CYCLE,"A");stone_map[x][y]=1;

                 }
                 else  if((map0.flag(stone.getx(),stone.gety()+1)=="S")&&(map0.see(stone.getx(),stone.gety()+1)==TRASH)&&(map0.see(stone.getx()-1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="SA"))
                 {


                     stones.emplace_back(stone.getx()-1, stone.gety()+1, RIGHT_CYCLE,"A");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx(),stone.gety()+1)=="SA")&&(map0.see(stone.getx(),stone.gety()+1)==BELT)&&(map0.see(stone.getx()-1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="SA"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()+1, LEFT_CYCLE,"A");
                     stones.emplace_back(stone.getx()-1, stone.gety()+1, RIGHT_CYCLE,"A");stone_map[x][y]=1;
                 }


                 else  if((map0.flag(stone.getx(),stone.gety()+1)=="SD")&&(map0.see(stone.getx(),stone.gety()+1)==BELT)&&(map0.see(stone.getx()-1,stone.gety()+1)==TRASH)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="S"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()+1, LEFT_CYCLE,"D");stone_map[x][y]=1;

                 }
                  else if((map0.flag(stone.getx(),stone.gety()+1)=="S")&&(map0.see(stone.getx(),stone.gety()+1)==TRASH)&&(map0.see(stone.getx()-1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="SD"))
                 {


                     stones.emplace_back(stone.getx()-1, stone.gety()+1, RIGHT_CYCLE,"D");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx(),stone.gety()+1)=="SD")&&(map0.see(stone.getx(),stone.gety()+1)==BELT)&&(map0.see(stone.getx()-1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()+1)=="SD"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()+1, LEFT_CYCLE,"D");
                     stones.emplace_back(stone.getx()-1, stone.gety()+1, RIGHT_CYCLE,"D");stone_map[x][y]=1;
                 }
             }
             stones.erase(stones.begin()+i);
             i--;
             update();
              continue;
         }

         else if(map0.see(x,y)==CUTTER_A_L)
         {
             if(stone.get_type()==CYCLE)
             {

                 if((map0.flag(stone.getx()-1,stone.gety())=="A")&&(map0.see(stone.getx()-1,stone.gety())==BELT)&&(map0.see(stone.getx()-1,stone.gety()-1)==TRASH)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="A"))
                 {

                     stones.emplace_back(stone.getx()-1, stone.gety(), LEFT_CYCLE,stone.getdi());stone_map[x][y]=1;

                 }
                 else  if((map0.flag(stone.getx()-1,stone.gety())=="A")&&(map0.see(stone.getx()-1,stone.gety())==TRASH)&&(map0.see(stone.getx()-1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="A"))
                 {

                     stones.emplace_back(stone.getx()-1, stone.gety()-1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }
                  else if((map0.flag(stone.getx()-1,stone.gety())=="A")&&(map0.see(stone.getx()-1,stone.gety())==BELT)&&(map0.see(stone.getx()-1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="A"))
                 {

                     stones.emplace_back(stone.getx()-1, stone.gety(), LEFT_CYCLE,stone.getdi());
                     stones.emplace_back(stone.getx()-1, stone.gety()-1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }


                 else  if((map0.flag(stone.getx()-1,stone.gety())=="AW")&&(map0.see(stone.getx()-1,stone.gety())==BELT)&&(map0.see(stone.getx()-1,stone.gety()-1)==TRASH)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="A"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()-1, LEFT_CYCLE,"S");stone_map[x][y]=1;

                 }
                 else  if((map0.flag(stone.getx()-1,stone.gety())=="A")&&(map0.see(stone.getx()-1,stone.gety())==TRASH)&&(map0.see(stone.getx()-1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="AW"))
                 {


                     stones.emplace_back(stone.getx()-1, stone.gety()-1, RIGHT_CYCLE,"S");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx()-1,stone.gety()-1)=="AW")&&(map0.see(stone.getx()-1,stone.gety())==BELT)&&(map0.see(stone.getx()-1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="AW"))
                 {

                     stones.emplace_back(stone.getx()-1, stone.gety(), LEFT_CYCLE,"S");
                     stones.emplace_back(stone.getx()-1, stone.gety()-1, RIGHT_CYCLE,"S");stone_map[x][y]=1;
                 }


                 else  if((map0.flag(stone.getx()-1,stone.gety())=="AS")&&(map0.see(stone.getx()-1,stone.gety())==BELT)&&(map0.see(stone.getx()-1,stone.gety()-1)==TRASH)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="A"))
                 {

                     stones.emplace_back(stone.getx()-1, stone.gety(), LEFT_CYCLE,"S");stone_map[x][y]=1;

                 }
                 else  if((map0.flag(stone.getx()-1,stone.gety())=="A")&&(map0.see(stone.getx()-1,stone.gety())==TRASH)&&(map0.see(stone.getx()-1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="AS"))
                 {


                     stones.emplace_back(stone.getx()-1, stone.gety()-1, RIGHT_CYCLE,"S");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx()-1,stone.gety())=="AS")&&(map0.see(stone.getx()-1,stone.gety())==BELT)&&(map0.see(stone.getx()-1,stone.gety()-1)==BELT)&&(map0.flag(stone.getx()-1,stone.gety()-1)=="AS"))
                 {

                     stones.emplace_back(stone.getx()-1, stone.gety(), LEFT_CYCLE,"S");
                     stones.emplace_back(stone.getx()-1, stone.gety()-1, RIGHT_CYCLE,"S");stone_map[x][y]=1;
                 }
             }
             stones.erase(stones.begin()+i);
             i--;
             update();
              continue;
         }

        else  if(map0.see(x,y)==CUTTER_D_L)
         {

             if(stone.get_type()==CYCLE)
             {

                 if((map0.flag(x+1,y)=="D")&&(map0.see(x+1,y)==BELT)&&(map0.see(x+1,y+1)==TRASH)&&(map0.flag(x+1,y+1)=="D"))
                 {

                     stones.emplace_back(x+1, y, LEFT_CYCLE,stone.getdi());stone_map[x][y]=1;

                 }
                 else if((map0.flag(x+1,stone.gety())=="D")&&(map0.see(stone.getx()+1,stone.gety())==TRASH)&&(map0.see(stone.getx()+1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="D"))
                 {

                     stones.emplace_back(stone.getx()+1, stone.gety()+1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }
                 else if((map0.flag(stone.getx()+1,stone.gety())=="D")&&(map0.see(stone.getx()+1,stone.gety())==BELT)&&(map0.see(stone.getx()+1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="D"))
                 {

                     stones.emplace_back(stone.getx()+1, stone.gety(), LEFT_CYCLE,stone.getdi());
                     stones.emplace_back(stone.getx()+1, stone.gety()+1, RIGHT_CYCLE,stone.getdi());stone_map[x][y]=1;
                 }


                 else if((map0.flag(stone.getx()+1,stone.gety())=="DW")&&(map0.see(stone.getx()+1,stone.gety())==BELT)&&(map0.see(stone.getx()+1,stone.gety()+1)==TRASH)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="D"))
                 {

                     stones.emplace_back(stone.getx(), stone.gety()+1, LEFT_CYCLE,"W");stone_map[x][y]=1;

                 }
                else if((map0.flag(stone.getx()+1,stone.gety())=="D")&&(map0.see(stone.getx()+1,stone.gety())==TRASH)&&(map0.see(stone.getx()+1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="DW"))
                 {


                     stones.emplace_back(stone.getx()+1, stone.gety()+1, RIGHT_CYCLE,"W");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx()+1,stone.gety()+1)=="DW")&&(map0.see(stone.getx()+1,stone.gety())==BELT)&&(map0.see(stone.getx()+1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="DW"))
                 {

                     stones.emplace_back(stone.getx()+1, stone.gety(), LEFT_CYCLE,"W");
                     stones.emplace_back(stone.getx()+1, stone.gety()+1, RIGHT_CYCLE,"W");stone_map[x][y]=1;
                 }


                  else if((map0.flag(stone.getx()+1,stone.gety())=="DS")&&(map0.see(stone.getx()+1,stone.gety())==BELT)&&(map0.see(stone.getx()+1,stone.gety()+1)==TRASH)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="D"))
                 {

                     stones.emplace_back(stone.getx()+1, stone.gety(), LEFT_CYCLE,"S");stone_map[x][y]=1;

                 }
                 else  if((map0.flag(stone.getx()+1,stone.gety())=="D")&&(map0.see(stone.getx()+1,stone.gety())==TRASH)&&(map0.see(stone.getx()+1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="DS"))
                 {


                     stones.emplace_back(stone.getx()+1, stone.gety()+1, RIGHT_CYCLE,"S");stone_map[x][y]=1;
                 }
                 else  if((map0.flag(stone.getx()+1,stone.gety())=="DS")&&(map0.see(stone.getx()+1,stone.gety())==BELT)&&(map0.see(stone.getx()+1,stone.gety()+1)==BELT)&&(map0.flag(stone.getx()+1,stone.gety()+1)=="DS"))
                 {

                     stones.emplace_back(stone.getx()+1, stone.gety(), LEFT_CYCLE,"S");
                     stones.emplace_back(stone.getx()+1, stone.gety()+1, RIGHT_CYCLE,"S");stone_map[x][y]=1;
                 }
              }
             stones.erase(stones.begin()+i);
              i--;
             update();
             continue;
         }


     }
 }
 void GameInterface::receive()//交易中心接收矿石的槽函数
 {//遍历所有在交付中心的矿石
     for (auto it=stones.begin();it!=stones.end();++it)
     {
         Stone&stone=*it;
         if(map0.see(stone.getx(),stone.gety())==HUB)
         {
             money=money+stone.get_type()*if_money;
             if(stone.get_type()==CYCLE)
             {
                 n_cycle++;
             }
            else if(stone.get_type()==LEFT_CYCLE)
             {
                 n_cycle_l++;
             }
            else if(stone.get_type()==RIGHT_CYCLE)
             {
                 n_cycle_r++;
             }
            else if(stone.get_type()==RECT)
             {
                 n_rect++;
             }
           it=stones.erase(it);
         }
     }
      moneyLabel->setText(QString("金币: %1").arg(money));

      n_c_Label->setText(QString("已采圆形: %1").arg(n_cycle));
      n_r_Label->setText(QString("已采方形: %1").arg(n_rect));
      n_c_l_Label->setText(QString("已采左半边圆形: %1").arg(n_cycle_l));
      n_c_r_Label->setText(QString("已采右半边圆形: %1").arg(n_cycle_r));

    update(); // 重新绘制
 }
 void GameInterface::improve_v_miner()
 {
     v_miner=v_miner/2;
     mineTimer->start(v_miner);

 }
 void GameInterface::improve_v_cutter()
 {
     v_cutter=v_cutter/2;

     cutTimer->start(v_cutter);
 }
 void GameInterface::improve_v_belt()
 {
     v_belt=v_belt/2;

     moveTimer->start(v_belt);

 }

 int GameInterface::get_n_cycle()
 {
     return n_cycle;
 }
 int GameInterface::get_n_rect()
 {
     return n_rect;
 }
 int GameInterface::get_n_cycle_l()
 {
     return n_cycle_l;
 }

 void  GameInterface::improve_stone()
 {
     if_stone=1;
 }
 void  GameInterface::improve_hub()
 {
     if_hub=1;
 }
 void  GameInterface::improve_money()
 {
     if_money=4;
 }


