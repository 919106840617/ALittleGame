#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"

class character: public item
{
    int blood, defend, attack;
public:
    character(int ,int, int, int, int, int, int);
    void hurt(int h);
    void addBlood(int b);
    void addDefend(int d);
    void addAttack(int a);
    void setBlood(int b);
    void setDefend(int d);
    void setAttack(int a);
    bool isAlive();
};

#endif // CHARACTER_H
