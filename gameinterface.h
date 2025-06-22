#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QLabel>
#include <QRect>
#include <QDebug>
#include <QMouseEvent>
#include<QTimer>
#include <QKeyEvent>
#include <vector>
#include "mine.h"
#include "miner.h"
#include "trash.h"
#include "cutter.h"
#include "stastic.h"
#include "belt.h"
#include "tools.h"
#include "stone.h"

class GameInterface : public QWidget
{
    Q_OBJECT

public:
    explicit GameInterface(int round0,int need_cycle0,int need_cycle_l0,int need_rect0,QWidget *parent = nullptr);
    ~GameInterface();
    bool isMiner(int i,int j);//判断是否可以放采矿机
    bool cantrash(int i,int j);//判断是否可以放垃圾桶或传送带
     bool cancutter(int i,int j);//判断是否可以放切割机
    QPushButton *shop_button;//商店的按钮
    void improve_v_miner();//加速采矿机的函数
     void improve_v_cutter();//加速切割机的函数
      void improve_v_belt();//加速传送带的函数
      int get_n_cycle();//获取当前已获得的圆形矿数量
     int get_n_rect();//获取当前已获得的方形矿数量
      int get_n_cycle_l();//获取当前已获得的左半边圆形矿数量
     int get_money()//获取当前已获得的金币数量
      {
         return money;
      };
      void change_money(int i)//改变金币数量
      {
          money=money-i;
      };
     void improve_stone();//增加矿地函数
      void improve_hub();//扩建交易中心函数
     void improve_money();//涨价函数


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
private:
    void drawGrid(QPainter *painter);
    //创建放几种设备的容器，以便更新画面
    std::vector<Miner>miners;
    std::vector<Belt>belts;
    std::vector<Cutter>cutters;
    std::vector<Trash>trashs;
    //插入各设备的按钮图像
    QPixmap belt_button;
    QPixmap cutter_button;
    QPixmap eraser_button;
    QPixmap miner_button;
    QPixmap trash_button;
    //插入各设备，矿物的图像
    QPixmap hub_small;
    QPixmap hub_big;
    QPixmap cycle_mine;
    QPixmap rect_mine;
    QPixmap barrier;
    QPixmap miner_p[4];
    QPixmap cutter_p[4];
    QPixmap trash_p[4];
    QPixmap belt_p[13];
    QPixmap stone_p[4];
    mine map;//记录了矿地的分布
    Tools map0;//记录了设备的分布
    int rows;//行数
    int cols;//列数
    //标记是否在放置某设备，便于拖拽图像生成
    bool placing_belt;
    bool  placing_cutter;
    bool  placing_trash;
    bool placing_miner;
     bool placing_eraser;
    //记录鼠标位置
     QPoint currentPos;
    QPoint startPos;
     //记录键盘标识的设备方向
     std::string currentdi;
    QTimer* mineTimer; // 定时器用于生成矿石
     QTimer* moveTimer; // 定时器用于传输矿石
    QTimer* cutTimer;// 定时器用于切割矿石
      QTimer* receiveTimer;// 定时器用于接收矿石
    std::vector<Stone> stones; // 存储所有的矿石
    int money;//金币数量
    int n_cycle;//采集的圆形矿石数量
    int n_rect;//采集的方形矿石数量
    int n_cycle_l;//采集的左半边圆形矿石数量
    int n_cycle_r;//采集的右半边圆形矿石数量
    int need_cycle;//需要的的圆形矿石数量
    int need_cycle_l;//需要的的左半边圆形矿石数量
    int need_cycle_r;//需要的的右半边圆形矿石数量
    int need_rect;//需要的的方形矿石数量
    //显示各个量的文字
    QLabel *moneyLabel;
    QLabel *need_c_Label;
    QLabel *n_c_Label;
    QLabel *need_r_Label;
    QLabel *n_r_Label ;
    QLabel *need_c_l_Label;
    QLabel *n_c_l_Label;
    QLabel *need_c_r_Label;
    QLabel *n_c_r_Label;
    QLabel *round_Label;
    int round;//关卡数
    int v_miner;//采矿机速度
    int v_cutter;//切割机速度
    int v_belt;//传送带速度
    int if_stone;//标记是否购买过增加矿地
    int if_hub;//标记是否购买过扩建交付中心
    int if_money;//标记是否购买过涨价
    int stone_map[WIDTH][HEIGHT];//标记这个位置是否有矿石（用于堵塞效果）




private slots:
    void generateMine(); // 生成矿石的槽函数
    void moveMines(); // 移动矿石的槽函数
    void cutMines();//切割矿石的槽函数
    void receive();//交易中心接收矿石的槽函数


};

#endif // GAMEINTERFACE_H
