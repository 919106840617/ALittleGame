#include "item.h"

item::item(int x, int y, int xx, int yy)
{
    this->x = x;
    this->y = y;
    this->xx = xx;
    this->yy = yy;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &item::updatePlace);
    timer->setSingleShot(0);
}

item::~item()
{
    delete timer;
}

int item::getx()
{
    return x;
}
int item::gety()
{
    return y;
}
int item::getxx()
{
    return xx;
}
int item::getyy()
{
    return yy;
}

int item::getfx()
{
    return fx;
}

int item::getspeed()
{
    return v;
}

void item::setspeed(int v)
{
    this->v = v;
}

void item::setfx(int fx)
{
    this->fx = fx;
}

void item::updatePlace()
{
    switch (fx)
    {
    case 0:
        x += v;break;
    case 1:
        y -= v;break;
    case 2:
        x -= v;break;
    case 3:
        y += v;break;
    default:
        break;
    }
    move(x, y);
}

void item::start()
{
    switch (fx)
    {
    case 0:
        x += v;break;
    case 1:
        y -= v;break;
    case 2:
        x -= v;break;
    case 3:
        y += v;break;
    default:
        break;
    }
    move(x, y);
    timer->start(10);
}

void item::stop()
{
    timer->stop();
}

