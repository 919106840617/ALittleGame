#ifndef BULLET_H
#define BULLET_H

#include "item.h"

class bullet: public item
{
    int attack;
public:
    bullet(int x, int y, int xx, int yy, int fx, int v, int a);
    int getAttack();
};

#endif // BULLET_H
