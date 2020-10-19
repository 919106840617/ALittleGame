#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class enemy: public character
{
public:
    enemy(int x, int y, int xx, int yy, int b, int d, int a);
};

#endif // ENEMY_H
