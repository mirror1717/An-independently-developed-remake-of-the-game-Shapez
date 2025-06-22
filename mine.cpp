#include "mine.h"


mine::mine()

{
    for(int i=0;i<HEIGHT;i++)
    {
        for(int j=0;j<WIDTH;j++)
        {
            thing[j][i]=NONE;
        }
    }

    thing[2][5]=CYCLE;
    thing[3][3]=CYCLE;
    thing[3][5]=CYCLE;
    thing[5][4]=CYCLE;
    thing[4][5]=CYCLE;
    thing[3][4]=CYCLE;
    thing[4][4]=CYCLE;

    thing[20][11]=RECT;
    thing[20][12]=RECT;
    thing[21][12]=RECT;
    thing[21][10]=RECT;
    thing[22][10]=RECT;
    thing[22][11]=RECT;
    thing[22][12]=RECT;

    thing[12][5]=BARRIER;
    thing[9][6]=BARRIER;
    thing[12][10]=BARRIER;
    thing[10][9]=BARRIER;
    thing[18][8]=BARRIER;
    thing[19][10]=BARRIER;


}

int mine::see(int x,int y)
{
    return thing[x][y];
}

 void mine::improve()
{
     thing[19][2]=CYCLE;
     thing[19][3]=CYCLE;
     thing[20][2]=CYCLE;
     thing[20][3]=CYCLE;
     thing[21][2]=CYCLE;
     thing[18][3]=CYCLE;
     thing[18][4]=CYCLE;

     thing[2][11]=RECT;
     thing[2][10]=RECT;
     thing[2][12]=RECT;
     thing[3][10]=RECT;
     thing[3][11]=RECT;
     thing[4][11]=RECT;
     thing[4][12]=RECT;

 }

mine::~mine() {}


