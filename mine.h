#ifndef MINE_H
#define MINE_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QRect>
#include "stastic.h"

class mineData;

class mine
{
public:
    mine();

    ~mine();
    int see(int x,int y);//看这个位置是什么矿物
    void improve();//增加矿物



private:
    int thing[WIDTH][HEIGHT];//矿物地图

};

#endif // MINE_H
