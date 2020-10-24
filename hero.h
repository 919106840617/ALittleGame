#ifndef HERO_H
#define HERO_H

#include "character.h"
#include <QVector>

class hero: public character
{
    QVector<int> *prefx;

public:
    hero(int x, int y, int xx, int yy, int fx, int v, int b, int d, int a);
    ~hero();
    void addPrefx(int fx);
    void removePrefx(int fx);
    bool isPrefx();
    int getPrefx();
};

#endif // HERO_H
