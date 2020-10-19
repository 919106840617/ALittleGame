#include "enemy.h"

enemy::enemy(int x, int y, int xx, int yy, int v, int b, int d, int a)
    :character(x,y,xx,yy,v,b,d,a)
{

}

void enemy::seek(int x, int y)
{
    int a = getx() - x;
    int b = gety() - y;
    if (a<0)
    {
        if (b<0&&-a>-b)
            setfx(3);
    }
    else
    {

    }
}
