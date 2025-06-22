#ifndef TRASH_H
#define TRASH_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class TrashData;

class Trash
{
public:
    Trash();
   Trash(int i,int j,const std::string &di);
    ~Trash();
   std::string getdi()const;//获取方向
   int getx()const;
   int gety()const;
private:

    std::string direction;
    int x;
    int y;


};

#endif // TRASH_H
