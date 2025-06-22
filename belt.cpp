#include "belt.h"



Belt::Belt()

{
    direction='W';
    x=-1;
    y=-1;

}
Belt::Belt(int i,int j,const std::string& di)
{
    x=i;
    y=j;
    direction=di;
}

std::string Belt::getdi()const
{
    return direction;
}
int Belt::getx() const
{
    return x;
}
int Belt::gety() const
{
    return y;
}
Belt::~Belt() {}
