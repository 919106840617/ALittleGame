#include "character.h"

character::character(int x, int y, int xx, int yy, int v, int b, int d, int a)
    :item(x, y, xx, yy, v)
{
    blood = b;
    defend = d;
    attack = a;
    deadnum = 0;
}


void character::hurt(int h)
{
    if (h>defend)
        blood -= h - defend;
}

void character::addBlood(int b)
{
    blood += b;
}

void character::addDefend(int d)
{
    defend += d;
    if (defend<0)
        defend = 0;
}

void character::addAttack(int a)
{
    attack += a;
    if (attack<0)
        attack = 0;
}

void character::setBlood(int b)
{
    blood = b;
}
void character::setDefend(int d)
{
    defend = d;
}
void character::setAttack(int a)
{
    attack = a;
}
int character::getAttack()
{
    return attack;
}

bool character::isAlive()
{
    return blood > 0;
}

bool character::dead()
{
    int i = 10;
    int fx = 1;
    if (deadnum<i)
    {
        setPic(":/new/prefix1/picture/boom_1.png",fx);
    }
    else if (deadnum<i*2)
    {
        setPic(":/new/prefix1/picture/boom_2.png",fx);
    }
    else if (deadnum<i*3)
    {
        setPic(":/new/prefix1/picture/boom_3.png",fx);
    }
    else if (deadnum<i*4)
    {
        setPic(":/new/prefix1/picture/boom_4.png",fx);
    }
    else if (deadnum<i*5)
    {
        setPic(":/new/prefix1/picture/boom_5.png",fx);
    }
    else if (deadnum<i*6)
    {
        return true;
    }
    deadnum++;
    return false;
}

int character::getBlood()
{
    return blood;
}
