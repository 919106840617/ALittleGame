#include "hero.h"
#include <QPixmap>
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

hero::hero(int x, int y, int xx, int yy, int fx, int v, int b, int d, int a)
    :character(x,y,xx,yy,v,b,d,a)
{
    setPic(":/new/prefix1/picture/TANK2_1.png",fx);//默认机甲图片朝上
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
