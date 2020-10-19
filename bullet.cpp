#include "bullet.h"

bullet::bullet(int x, int y, int xx, int yy, int fx, int v, int a)
    :item(x, y, xx, yy, v)
{
    setfx(fx);
    setspeed(v);
    attack = a;
    start();
}
bullet::~bullet()
{

}

int bullet::getAttack()
{
    return attack;
}
