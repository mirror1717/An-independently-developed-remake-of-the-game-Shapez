#include "miner.h"



Miner::Miner()

{
    direction="W";
    x=-1;
    y=-1;


}
 Miner::Miner(int i,int j, const std::string& di)
{
     x=i;
     y=j;
     direction=di;
 }

 std::string Miner::getdi()const
 {
     return direction;
 }
 int Miner::getx() const
 {
     return x;
 }
 int Miner::gety() const
 {
     return y;
 }


Miner::~Miner() {}
