#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"

class character: public item
{
    int blood, defend, attack;
public:
    character(int x, int y, int xx, int yy, int v, int b, int d, int a);
    void hurt(int h);//受伤
    void addBlood(int b);
    void addDefend(int d);
    void addAttack(int a);
    void setBlood(int b);
    void setDefend(int d);
    void setAttack(int a);
    int getAttack();
    bool isAlive();//检测血量
    void dead();
};

#endif // CHARACTER_H
