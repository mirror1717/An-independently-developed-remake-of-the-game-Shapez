#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QWidget>
#include <QTimer>
#include "start.h"
#include "gameinterface.h"
#include "choose.h"
#include "shop.h"
#include "win.h"





class control:public QWidget
{
    Q_OBJECT
public:

    control();//  创建各个界面，展示开始界面，放音乐
    ~control();


    // 界面
    Start *start;
    GameInterface *game1;
     GameInterface *game2;
     GameInterface *game3;
    Choose *choose;
    Shop *shop0;
    Win *win;


    QTimer *check;//每1s检查一下有没有通过某一关
     void CheckPassCertainRound();//判断是否通过某关，若通过了弹出choose界面
    void connections();//连接槽函数，建立各界面联系
    void improveminer(); //局部优化miner
     void improveBelt();    // 局部优化belt
    void improveCutter();//  局部优化cutter

private:
    int Round;//回合数
    int sign1;//是否通过了某关并选择了加成
    int sign2;
    int sign3;
    int buy1;//是否买了某全局强化
    int buy2;
    int buy3;

    QMediaPlayer *mediaPlayer;//放音乐用的
    QAudioOutput *audioOutput;

};

#endif // CONTROL_H
