#ifndef CUTTER_H
#define CUTTER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class CutterData;

class Cutter
{
public:
    Cutter();
    Cutter(int i,int j,const std::string &di);
    ~Cutter();
    std::string getdi()const;//获取方向
    int getx()const;
    int gety()const;
private:
     std::string direction;//方向，W,A,S,D
    int x;
    int y;


};

#endif // CUTTER_H
