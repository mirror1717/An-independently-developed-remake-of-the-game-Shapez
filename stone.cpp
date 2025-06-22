#include "stone.h"

Stone::Stone() {

    type=-1;

}


int Stone::get_type()const
{
    return type;
}

int Stone::getx()const
{
    return x;
}
int Stone::gety() const
{
    return y;
}
 std::string Stone::getdi()const
{
     return direction;
 }
Stone::Stone(int x0,int y0,int type0,std::string direction0)
{
    x=x0;
    y=y0;
    type=type0;
    direction=direction0;
}
void Stone::move(int x0,int y0)
{
    x=x0;
    y=y0;
}
void Stone::turn(std::string direction0)
{
    direction=direction0;
}
