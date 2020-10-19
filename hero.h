#ifndef HERO_H
#define HERO_H

#include "character.h"
#include <QVector>

class hero: public character
{
    bool move;
    QVector<int> *prefx;

public:
    hero(int x, int y, int xx, int yy, int b, int d, int a);
    void startMove();
    void stopMove();
    bool isMove();
    void addPrefx(int fx);
    void removePrefx(int fx);
    bool isPrefx();
    int getPrefx();
};

#endif // HERO_H
