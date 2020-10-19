#include "item.h"

item::item(int x, int y, int xx, int yy, int v)
{
    this->x = x;
    this->y = y;
    this->xx = xx;
    this->yy = yy;
    this->v = v;
    ismove = false;
    move(x, y);
    resize(xx, yy);
}

item::~item()
{
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
    QMatrix matrix;
    switch (fx) {
    case 0:
        matrix.rotate(90);
        break;
    case 1:
        matrix.rotate(0);
        break;
    case 2:
        matrix.rotate(270);
        break;
    case 3:
        matrix.rotate(180);
        break;
    default:
        break;
    }
    setPixmap(pix.transformed(matrix, Qt::SmoothTransformation));
}

void item::update()
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
    ismove = true;
}

void item::stop()
{
    ismove = false;
}

bool item::isMove()
{
    return ismove;
}
