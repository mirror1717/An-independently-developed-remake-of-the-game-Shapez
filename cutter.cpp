#include "cutter.h"



Cutter::Cutter()

{
    direction='W';
    x=-1;
    y=-1;
}
Cutter::Cutter(int i,int j, const std::string& di)
{
    x=i;
    y=j;
    direction=di;
}

std::string Cutter::getdi()const
{
    return direction;
}
int Cutter::getx() const
{
    return x;
}
int Cutter::gety() const
{
    return y;
}
Cutter::~Cutter() {}
