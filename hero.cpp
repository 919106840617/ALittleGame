#include "hero.h"
#include <QPixmap>
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

hero::hero(int x, int y, int xx, int yy, int fx, int v, int b, int d, int a)
    :character(x,y,xx,yy,v,b,d,a)
{
    setPic(":/new/prefix1/picture/TANK2_1.png",fx);//默认机甲图片朝上
    maxblood = b;
    prefx = new QVector<int>;
}
hero::~hero()
{
    delete prefx;
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

void hero::levelUp()
{
    if (qrand() % 100<75)
    {
        maxblood = maxblood * 4 / 3;
        setBlood(maxblood);
    }
    if (qrand() % 100<50)
    {
        addAttack(3);
    }

    if (qrand() % 100<15)
    {
        setspeed(getspeed()+1);
    }
    else if (qrand() % 100<25)
    {
        addDefend(1);
    }
}
