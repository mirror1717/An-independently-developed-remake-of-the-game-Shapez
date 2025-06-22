#ifndef MINER_H
#define MINER_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QWidget>

class MinerData;

class Miner
{
public:
    Miner();
    Miner(int i,int j,const std::string &di);
    ~Miner();
    std::string getdi()const;//获取设备方向
    int getx()const;
    int gety()const;


private:
    std::string direction;
    int x;
    int y;


};

#endif // MINER_H
