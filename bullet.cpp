#include "bullet.h"

bullet::bullet(int x, int y, int xx, int yy, int fx, int v, int a)
    :item(x, y, xx, yy)
{
    setfx(fx);
    setspeed(v);
    attack = a;
}

int bullet::getAttack()
{
    return attack;
}
