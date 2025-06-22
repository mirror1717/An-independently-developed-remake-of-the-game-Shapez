#include "control.h"
#include "start.h"
#include <QIcon>
#include <QPainter>
#include <QPen>


control::control( )

{//创建各界面并初始化各变量
    Round=1;
    sign1=1;
    sign2=1;
    sign3=1;
    buy1=1;
    buy2=1;
    buy3=1;
    start=new Start;
    game1=new  GameInterface(1,20,0,0);
    game2=new  GameInterface(2,0,0,30);
    game3=new  GameInterface(3,0,50,0);
   choose=new Choose;
    shop0=new Shop;
    win =new Win;
    start->show();
    //放背景音乐
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->setSource(QUrl("qrc:/picture/background.mp3"));
    audioOutput->setVolume(0.25);
    mediaPlayer->setLoops(QMediaPlayer::Infinite);
    mediaPlayer->play();

    connections();//连接槽函数
    check= new QTimer(this);
    connect(check, &QTimer::timeout, this, &control::CheckPassCertainRound);
    check->start(1000);//开启计时器，每秒检查是否通过某关
}

void control::connections()
{
//点击开始游戏进入游戏第一关
    connect(start->starting, &QPushButton::clicked, this,  [=]()
            {
        game1->show();
        start->hide();
         });
    //这里本来想整存档功能但是时间有点来不及就放弃了
    connect(start->conti, &QPushButton::clicked, this,[=]()
            {
                qDebug() << "Button clicked!";
            });
    //点击退出游戏可以退出游戏
    connect(start->end, &QPushButton::clicked, this,[=]()
            {
        start->close();
     });

//点击游戏界面的商店图标可以进入商店
    connect(game1->shop_button, &QPushButton::clicked, this,[=]()
            {
                shop0->show();
                game1->hide();
            });


    connect(game2->shop_button, &QPushButton::clicked, this,[=]()
            {
                shop0->show();
                game2->hide();
            });


    connect(game3->shop_button, &QPushButton::clicked, this,[=]()
            {
                shop0->show();
                game3->hide();
            });

    //点击过关界面的各个按钮选择局部强化并切换到下一关
    connect(choose->belt_button, &QPushButton::clicked,this,[=]()
            {
        if(Round==1)
            {
            game2->improve_v_belt();
            choose->hide();
            game2->show();
             Round=2;
        }
       else if(Round==2)
        {
            game3->improve_v_belt();
            choose->hide();
            game3->show();
             Round=3;
        }
    });
    connect(choose->cutter_button, &QPushButton::clicked,this,[=]()
            {
                if(Round==1)
                {
                    game2->improve_v_cutter();
                    choose->hide();
                    game2->show();
                    Round=2;
                }
                else if(Round==2)
                {
                    game3->improve_v_cutter();
                    choose->hide();
                    game3->show();
                    Round=3;
                }
            });
    connect(choose->miner_button, &QPushButton::clicked,this,[=]()
            {
                if(Round==1)
                {
                    game2->improve_v_miner();
                    choose->hide();
                    game2->show();
                     Round=2;
                }
                else if(Round==2)
                {
                    game3->improve_v_miner();
                    choose->hide();
                    game3->show();
                     Round=3;
                }
            });

//点击商店的返回按钮返回游戏
    connect(shop0->return_button, &QPushButton::clicked,this,[=]()
            {
                if(Round==1)
                {
                    shop0->hide();
                    game1->show();
                }
                else if(Round==2)
                {

                    shop0->hide();
                    game2->show();

                }
                else if(Round==3)
                {

                    shop0->hide();
                    game3->show();

                }
            });
//点击商店的各个按钮可以判断金币是否足够，足够则扣除相应金币并记录已购买该强化，并在游戏中实行强化
    connect(shop0->money_button, &QPushButton::clicked,this,[=]()
            {
        if(Round==1)
        {
            if(game1->get_money()>=200&&buy1)
            {
                game1->change_money(200);
                game1->improve_money();
                game2->improve_money();
                game3->improve_money();
                buy1=0;
                shop0->buy1();

            }
        }
        else if(Round==2)
        {

            if(game2->get_money()>=200&&buy1)
            {
                game2->change_money(200);
                game1->improve_money();
                game2->improve_money();
                game3->improve_money();
                buy1=0;
                shop0->buy1();
            }

        }
        else if(Round==3)
        {
            if(game3->get_money()>=200&&buy1)
            {
                game3->change_money(200);
                game1->improve_money();
                game2->improve_money();
                game3->improve_money();
                buy1=0;
                shop0->buy1();
            }

        }
    });


    connect(shop0->hub_button, &QPushButton::clicked,this,[=]()
            {
        if(Round==1)
        {
            if(game1->get_money()>=300&&buy2)
            {
                game1->change_money(300);
                game1->improve_hub();
                game2->improve_hub();
                game3->improve_hub();
                buy2=0;
                shop0->buy2();

            }
        }
                else if(Round==2)
                {
            if(game2->get_money()>=300&&buy2)
            {
                game2->change_money(300);
                game1->improve_hub();
                game2->improve_hub();
                game3->improve_hub();
                buy2=0;
                shop0->buy2();

            }
                }
                else if(Round==3)
                {

            if(game3->get_money()>=300&&buy2)
            {
                game3->change_money(300);
                game1->improve_hub();
                game2->improve_hub();
                game3->improve_hub();
                buy2=0;
                shop0->buy2();

            }

                }
            });


    connect(shop0->stone_button, &QPushButton::clicked,this,[=]()
            {
                if(Round==1)
                {
            if(game1->get_money()>=400&&buy3)
            {
                game1->change_money(400);
                game1->improve_stone();
                game2->improve_stone();
                game3->improve_stone();
                buy3=0;
                shop0->buy3();

            }
                }
                else if(Round==2)
                {
                    if(game2->get_money()>=400&&buy3)
                    {
                        game2->change_money(400);
                        game1->improve_stone();
                        game2->improve_stone();
                        game3->improve_stone();
                        buy3=0;
                        shop0->buy3();


                    }

                }
                else if(Round==3)
                {

                    if(game3->get_money()>=400&&buy3)
                    {
                        game3->change_money(400);
                        game1->improve_stone();
                        game2->improve_stone();
                        game3->improve_stone();
                        buy3=0;
                        shop0->buy3();


                    }

                }
            });




}
void control::CheckPassCertainRound()//检查是否通过某关
{
    if(Round==1)
    {
        if(game1->get_n_cycle()>=20&&sign1)
        {
            game1->hide();
            choose->show();
            sign1=0;

        }
    }
    else if(Round==2)
    {
        if(game2->get_n_rect()>=30&&sign2)
        {
            game2->hide();
            choose->show();
            sign2=0;

        }
    }
    else if(Round==3)
    {
        if(game3->get_n_cycle_l()>=50&&sign3)
        {
            game3->hide();
            win->show();
            sign3=0;
        }
    }





}



control::~control() {
    delete game1;
    delete game2;
    delete game3;
    delete choose;
    delete shop0;
    delete start;
    delete win;
    delete mediaPlayer;
    delete audioOutput;
}
