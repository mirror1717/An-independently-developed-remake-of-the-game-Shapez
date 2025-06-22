#ifndef BELT_H
#define BELT_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QWidget>

class BeltData;

class Belt
{
public:
    Belt();
    Belt(int i,int j,const std::string &di);
    ~Belt();
    std::string getdi()const;//获取方向
    int getx()const;//获取横向坐标
    int gety()const;//获取纵向坐标

private:
    std::string direction;//方向，有：W,A,S,D,WA,WD,SA,SD,AW,AS,DW,DS
    int x;//第几行
    int y;//第几列


};

#endif // BELT_H
