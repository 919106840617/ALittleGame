#ifndef ITEM_H
#define ITEM_H

#include <QLabel>
#include <QPixmap>

class item: public QLabel
{
    int x, y, fx, v, xx, yy;//xy为位置，fx为运动方向，xxyy为大小
    bool ismove;

public:
    item(int x, int y, int xx, int yy, int v);
    ~item();
    int getx();
    int gety();
    int getxx();
    int getyy();
    int getfx();
    int getspeed();
    void setspeed(int v);
    void setfx(int fx);
    void update();
    void start();
    void stop();
    bool isMove();

    QPixmap pix;
};

#endif // ITEM_H

//fx 0右1上2左3下
