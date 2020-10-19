#include "game.h"
#include <QMatrix>
#include <QTransform>
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

game::game(QWidget *parent)
    :QWidget(parent)
{
    this->resize(gameWide, gameLength);
    a = new hero(500,200,100,100,2,20,20,20);
    a->setParent(this);

    a->move(a->getx(), a->gety());
    a->resize(a->getxx(), a->getyy());
    a->setspeed(2);

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &game::update);
    timer->start(7);

    bul = new QList<bullet*>;
}

game::~game()
{
    delete bul;
    delete timer;
    delete a;
}


void game::keypress_w()
{
    if (a->isMove())
        a->addPrefx(a->getfx());
    a->setfx(1);
    a->start();
}
void game::keypress_a()
{
    if (a->isMove())
        a->addPrefx(a->getfx());
    a->setfx(2);
    a->start();
}
void game::keypress_s()
{
    if (a->isMove())
        a->addPrefx(a->getfx());
    a->setfx(3);
    a->start();
}
void game::keypress_d()
{
    if (a->isMove())
        a->addPrefx(a->getfx());
    a->setfx(0);
    a->start();
}
void game::keyrelease_w()
{
    if (a->getfx()==1)
    {
        if (a->isPrefx())
        {
            a->setfx(a->getPrefx());
            a->removePrefx(a->getPrefx());
        }
        else
        {
            a->stop();
        }
    }
    else
    {
        a->removePrefx(1);
    }
}
void game::keyrelease_a()
{
    if (a->getfx()==2)
    {
        if (a->isPrefx())
        {
            a->setfx(a->getPrefx());
            a->removePrefx(a->getPrefx());
        }
        else
        {
            a->stop();
        }
    }
    else
    {
        a->removePrefx(2);
    }
}
void game::keyrelease_s()
{
    if (a->getfx()==3)
    {
        if (a->isPrefx())
        {
            a->setfx(a->getPrefx());
            a->removePrefx(a->getPrefx());
        }
        else
        {
            a->stop();
        }
    }
    else
    {
        a->removePrefx(3);
    }
}
void game::keyrelease_d()
{
    if (a->getfx()==0)
    {
        if (a->isPrefx())
        {
            a->setfx(a->getPrefx());
            a->removePrefx(a->getPrefx());
        }
        else
        {
            a->stop();
        }
    }
    else
    {
        a->removePrefx(0);
    }
}


void game::keypress_j()
{
    int x, y, w=10, h=10;
    x = a->getx();
    y = a->gety();
    switch (a->getfx()) {
    case 0:
    {
        x += a->getxx()-4;
        y += a->getxx()/5*3 +4;
        break;
    }
    case 1:
    {
        x += a->getxx()/5*3 +4;
        y += -5;
        break;
    }
    case 2:
    {
        y += a->getyy()/5+6;
        x += -5;
        break;
    }
    case 3:
    {
        y += a->getyy()-4;
        x += a->getxx()/5+6;
        break;
    }
    default:
        break;
    }
    bullet *b = new bullet(x, y, w, h, a->getfx(), 0, 1);
    b->setParent(this);
    b->show();
    b->setStyleSheet("QLabel{background-color:rgb(200,101,102);}");
    bul->append(b);
}

void game::update()
{
   if (a->isMove())
       a->update();
   bullet *b;
   int w, l;
   for (int i=0;i<bul->size();i++)
   {
       b = bul->at(i);
       if (b->isMove())
       {
           b->update();
       }
       w = b->getx();
       l = b->gety();
       if (w>gameWide||w<0||l>gameLength||l<0)
       {
           bul->removeAt(i);
           delete b;
           b = nullptr;
       }
   }
   check();
}

void game::check()
{
    bullet *b;
    int w, l;
    for (int i=0;i<bul->size();i++)
    {
        b = bul->at(i);
        w = b->getx() - a->getx();
        l = b->gety() - a->gety();
        if ((w<a->getxx()||w>-b->getxx())&&(l<a->getyy()||l>-b->getyy()))
        {
            bul->removeAt(i);
            delete b;
            b = nullptr;
        }
    }
}
