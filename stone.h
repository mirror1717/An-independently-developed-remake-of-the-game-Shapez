#ifndef STONE_H
#define STONE_H


#include <QMainWindow>
#include <QObject>
#include <QWidget>
class Stone
{
public:
    Stone();
    Stone(int x0,int y0,int type0,std::string direction0);
    int get_type()const;//获取矿石类型
    int getx()const;
    int gety()const;
    std::string getdi()const;//获取方向
    void move(int x0,int y0);//将矿石移动到（x0,y0）
    void turn(std::string direction0);//给矿石转向


private:
    int type;//矿石类型
    int x;
    int y;
    std::string direction;//矿石方向





};

#endif // STONE_H
