#include "bullet.h"

bullet::bullet(int x, int y, int xx, int yy, int fx, int v, int a)
    :item(x, y, xx, yy, v)
{
    setfx(fx);
    setspeed(v);
    attack = a;
    start();
    if (fx==1||fx==3)
    {
        int n = xx;
        xx = yy;
        yy = n;
    }
    setPic(":/new/prefix1/picture/bullet.png",fx);
}
bullet::~bullet()
{

}

int bullet::getAttack()
{
    return attack;
}
