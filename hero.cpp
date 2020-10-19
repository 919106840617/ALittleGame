#include "hero.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

hero::hero(int x, int y, int xx, int yy, int b, int d, int a)
    :character(x,y,xx,yy,b,d,a)
{
    move = false;
    prefx = new QVector<int>;
}

void hero::startMove()
{
    move = true;
}

void hero::stopMove()
{
    move = false;
}

bool hero::isMove()
{
    return move;
}

void hero::addPrefx(int fx)
{
    prefx->prepend(fx);
}

void hero::removePrefx(int fx)
{
    int num = prefx->size();
    for (int i=0;i<num;i++)
    {
        if (prefx->at(i)==fx)
        {
            prefx->remove(i);
            i--;
            num--;
        }
    }
}

int hero::getPrefx()
{
    return prefx->first();
}

bool hero::isPrefx()
{
    bool check = prefx->isEmpty();
    if (check)
        return false;
    return true;
}
