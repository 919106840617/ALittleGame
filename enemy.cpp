#include "enemy.h"

enemy::enemy(int x, int y, int xx, int yy, int k)
    :character(x,y,xx,yy,0,0,0,0)
{
    int fx = qrand() % 4;
    int picnum = k + 3;
    if (picnum>6)
        picnum=6;
    shoot = false;
    time = 0;

    if (k<7)
    {
        setspeed(1+k/2);
    }
    cd = 80;
            //300 / (k+1);

    setBlood(3*(k+1)*(k+1));
    setDefend(0);
    setAttack(1+k/2);

    setPic(":/new/prefix1/picture/TANK"+QString::number(picnum)+"_1.png",fx);
}

void enemy::seek(int x, int y, int xx, int yy)
{
    int x1=getx(), y1=gety(), xx1=getxx(), yy1=getyy();
    if (y1+yy1/2>y && y1+yy1/2<y+yy)
    {
        if (x1>x)
        {
            setfx(2);
        }
        else
        {
            setfx(0);
        }
        shoot = true;
        stop();
    }
    else if (x1+xx1/2>x && x1+xx1/2<x+xx)
    {
        if (y1>y)
        {
            setfx(1);
        }
        else
        {
            setfx(3);
        }
        shoot = true;
        stop();
    }
    else
    {
        if ((y1+yy1/2)<(y+yy/2))
        {
            if ((x1+xx1/2)<(x+xx/2) && (x+xx/2)-(x1+xx1/2) < (y+yy/2)-(y1+yy1/2))
            {
                setfx(0);
            }
            else if ((x1+xx1/2)>(x+xx/2) && -(x+xx/2)+(x1+xx1/2) < (y+yy/2)-(y1+yy1/2))
            {
                setfx(2);
            }
            else
            {
               setfx(3);
            }
        }
        else
        {
            if ((x1+xx1/2)<(x+xx/2) && (x+xx/2)-(x1+xx1/2) < -(y+yy/2)+(y1+yy1/2))
            {
                setfx(0);
            }
            else if ((x1+xx1/2)>(x+xx/2) && -(x+xx/2)+(x1+xx1/2) < -(y+yy/2)+(y1+yy1/2))
            {
                setfx(2);
            }
            else
            {
                setfx(1);
            }
        }
        shoot = false;
        start();
    }
}

bool enemy::isShoot()
{
    if (shoot)
    {
        if (time<cd)
        {
            time++;
            return false;
        }
        else
        {
            time = 0;
            return true;
        }
    }
    else
    {
        return false;
    }
}
