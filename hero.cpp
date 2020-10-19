#include "hero.h"
#include <QPixmap>
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

hero::hero(int x, int y, int xx, int yy, int v, int b, int d, int a)
    :character(x,y,xx,yy,v,b,d,a)
{
    QImage Im;
    Im.load(":/new/prefix1/0.1.png");
    pix = QPixmap::fromImage(Im);
    pix = pix.scaled(xx, yy, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pix);
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
