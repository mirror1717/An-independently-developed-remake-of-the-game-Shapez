#ifndef TOOLS_H
#define TOOLS_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "stastic.h"


class Tool
{
public:
    int gettype();
    std::string getdi();
    Tool();
    Tool(int type0,std::string di);
    void change(int type0,std::string direction0);//改变设备类型和方向

private:
    int type;//类型
    std::string direction;//方向

};

class Tools
{
public:
    Tools();
    int see(int x,int y);//获取(x,y)处设备类型
    std::string flag(int x,int y);//获取(x,y)处设备方向
    void add(int x,int y,int type,std::string direction);//添加设备
    void improve();//扩建交付中心


private:

    Tool map[WIDTH][HEIGHT];//设备地图


};

#endif // TOOLS_H
