#ifndef ITEM_H
#define ITEM_H

#include <QLabel>
#include <QTimer>

class item: public QLabel
{
    QTimer *timer;
    int x, y, fx, v, xx, yy;//xy为位置，fx为运动方向，xxyy为大小
    void updatePlace();

public:
    item(int, int, int, int);
    ~item();
    int getx();
    int gety();
    int getxx();
    int getyy();
    int getfx();
    int getspeed();
    void setspeed(int v);
    void setfx(int fx);
    void start();
    void stop();
};

#endif // ITEM_H

//fx 0右1上2左3下
