#include "character.h"

character::character(int x, int y, int xx, int yy, int v, int b, int d, int a)
    :item(x, y, xx, yy, v), blood(b), defend(d), attack(a){}

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

bool character::isAlive()
{
    return blood > 0;
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
