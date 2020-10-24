#include "game.h"
#include <QMatrix>
#include <QTransform>
#include <QDebug>
#include <QMessageBox>

#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

game::game(QWidget *parent)
    :QWidget(parent)
{
    this->resize(gameWide, gameLength);
    a = new hero(500,200,50,50, 0,2, 10,0,1);
    a->setParent(this);

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &game::update);
    timer->start(7);

    bul = new QList<bullet*>;
    ene = new QList<enemy*>;
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
    int x, y, w=5, h=5, v=3;
    x = a->getx();
    y = a->gety();
//    cout<<"fx:  "<<a->getfx();
    switch (a->getfx()) {
    case 0:
    {
        x += a->getxx();
        y += (a->getxx()-h)/2;
        break;
    }
    case 1:
    {
        x += (a->getxx()-w)/2;
        y += -h;
        break;
    }
    case 2:
    {
        y += (a->getyy()-h)/2;
        x += -w;
        break;
    }
    case 3:
    {
        y += a->getyy();
        x += (a->getxx()-w)/2;
        break;
    }
    default:
        break;
    }
    bullet *b = new bullet(x, y, w, h, a->getfx(), v, a->getAttack());
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
   enemy *e;
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
//   for (int i=0;i<ene->size();i++)
//   {
//       e = ene->at(i);
//       e->seek(a->getx(),a->gety());
//       e->update();
//       w = e->getx();
//       l = e->gety();
//       if (w>gameWide||w<0||l>gameLength||l<0)
//       {
//           ene->removeAt(i);
//           delete e;
//           e = nullptr;
//       }
//   }
   check();
}

void game::check()
{
    bullet *b;
    enemy *e;
    for (int i=0;i<bul->size();i++)
    {
        b = bul->at(i);
        if (a->isCrash(b))
        {
            a->hurt(b->getAttack());
            if (!a->isAlive())
            {
                QMessageBox::critical(0 , "游戏结束", "你嗝屁了。", QMessageBox::Ok | QMessageBox::Default, 0,  0 );
            }
            bul->removeAt(i);
            delete b;
            b = nullptr;
        }
        for (int i=0;i<ene->size();i++)
        {
            e = ene->at(i);
            if (e->isCrash(b))
            {
                e->hurt(b->getAttack());
                if (!e->isAlive())
                {
                    ene->removeAt(i);
                    delete e;
                    e = nullptr;
                }
                bul->removeAt(i);
                delete b;
                b = nullptr;
            }

        }
    }
}

void game::shoot(enemy* e)
{
    int x, y, w=10, h=10, v=0;
    x = e->getx();
    y = e->gety();
//    cout<<"fx:  "<<a->getfx();
    switch (e->getfx()) {
    case 0:
    {
        x += e->getxx();
        y += e->getxx()/5*3 +4;
        break;
    }
    case 1:
    {
        x += e->getxx()/5*3 +4;
        y += -h;
        break;
    }
    case 2:
    {
        y += e->getyy()/5+6;
        x += -w;
        break;
    }
    case 3:
    {
        y += e->getyy();
        x += e->getxx()/5+6;
        break;
    }
    default:
        break;
    }
    bullet *b = new bullet(x, y, w, h, e->getfx(), v, e->getAttack());
    b->setParent(this);
    b->show();
    b->setStyleSheet("QLabel{background-color:rgb(200,101,102);}");
    bul->append(b);
}

void game::addEnemy()
{
    int x, y, w=50, h=50, v=1, fx;
    fx = qrand()%4;
    bool check = true;
    while (check)
    {
        x = qrand() % gameWide;
        y = qrand() % gameLength;
        int disx = x - a->getx();
        int disy = y - a->gety();
        if ((disx<a->getxx()&&disx>-w)&&(disy<a->getyy()&&disy>-h))
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }

    enemy *e = new enemy(x,y,w,h,fx,v,5,0,1);
    e->setParent(this);
    e->show();
    e->start();
    ene->append(e);
}
