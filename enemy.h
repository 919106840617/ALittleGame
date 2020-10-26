#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class enemy: public character
{
    bool shoot;
    int cd, time;
public:
    enemy(int x, int y, int xx, int yy, int k);//k=0,1,2
    void seek(int x, int y, int xx, int yy);
    bool isShoot();//
};

#endif // ENEMY_H
