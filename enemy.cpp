#include "enemy.h"

enemy::enemy(int x, int y, int xx, int yy, int fx, int v, int b, int d, int a)
    :character(x,y,xx,yy,v,b,d,a)
{
    setPic(":/new/prefix1/picture/TANK4_1.png",fx);
}

void enemy::seek(int x, int y)
{
    int a = x - getx();
    int b = y - gety();
    if (b>getyy()/2)
    {
        setfx(3);
    }
    else if (b<-getyy()/2)
    {
        setfx(1);
    }
    else if (a>getxx()/2)
    {
        setfx(0);
    }
    else
    {
        setfx(2);
    }
}
