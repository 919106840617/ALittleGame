#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class enemy: public character
{
public:
    enemy(int x, int y, int xx, int yy, int v, int b, int d, int a);
    void seek(int x, int y);
};

#endif // ENEMY_H
