#include "trash.h"



Trash::Trash()

{

    direction='W';
    x=-1;
    y=-1;

}
Trash::Trash(int i,int j, const std::string& di)
{
    x=i;
    y=j;
    direction=di;
}

std::string Trash::getdi()const
{
    return direction;
}
int Trash::getx() const
{
    return x;
}
int Trash::gety() const
{
    return y;
}


Trash::~Trash() {}
