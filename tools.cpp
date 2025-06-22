#include "tools.h"


int Tool::gettype()
{
    return type;
}
std::string  Tool::getdi()
{
    return direction;
}

Tool::Tool()
{
    type=-1;
    direction="";
}
Tool::Tool(int type0,std::string di)
{
    type=type0;
    direction=di;
}

void Tool::change(int type0,std::string direction0)
{
    type=type0;
    direction=direction0;
}





Tools::Tools() {
    //先标定交付中心位置
    Tool hubcenter(HUB,"");

    map[13][6]=hubcenter;
    map[13][7]=hubcenter;
    map[14][6]=hubcenter;
    map[14][7]=hubcenter;


}
 int Tools::see(int x,int y)
{
     return map[x][y].gettype();
 }
 std::string Tools::flag(int x,int y)
 {

     return map[x][y].getdi();

 }

  void Tools::add(int x,int y,int type,std::string direction)
 {
      map[x][y].change(type,direction);
  }

 void Tools::improve()
  {Tool hubcenter(HUB,"");
     map[13][8]=hubcenter;
     map[13][9]=hubcenter;
     map[14][8]=hubcenter;
     map[14][9]=hubcenter;
     map[15][6]=hubcenter;
     map[15][7]=hubcenter;
     map[16][6]=hubcenter;
     map[16][7]=hubcenter;
     map[15][8]=hubcenter;
     map[15][9]=hubcenter;
     map[16][8]=hubcenter;
     map[16][9]=hubcenter;

 }
