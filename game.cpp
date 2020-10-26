#include "game.h"
#include <QMatrix>
#include <QTransform>
#include <QDebug>
#include <QMessageBox>
#include <QTime>

#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

game::game(QWidget *parent)
    :QWidget(parent)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    resize(gameWide, gameLength);

    score = 0;
    up = 25;
    level = 0;
    enetime = 10000;

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &game::update);
    timer->start(8);

    QLabel* label;
    for (int i=0; i<16; i++)
    {
        for (int j=0; j<9; j++)
        {
            label = new QLabel(this);
            label->resize(80,80);
            label->move(i*80,j*80);
            label->setStyleSheet("QLabel{border-image: url(:/new/prefix1/picture/floot_1.jpg)}");
            label->show();
            floot.append(label);
            label = nullptr;
        }
    }

    a = new hero(500,200,56,56, 0,2, 15,0,1);
    a->setParent(this);
    a->show();

    s = new QLabel("your score: 0",this);
    s->resize(320,72);
    s->move(gameWide-s->geometry().width(),0);
    s->setStyleSheet("QLabel{border-image: url(:/new/prefix1/picture/score_1.png)}");
    s->show();
    QFont ft("Microsoft YaHei", 15);
    s->setFont(ft);
    s->setContentsMargins(20,0,0,10);

    bl = new QLabel(this);
    bl->setStyleSheet("QLabel{background-color:rgb(200,0,0);}");
    bl->show();

    bul = new QList<bullet*>;
    ene = new QList<enemy*>;

}

game::~game()
{
    qDeleteAll(floot.begin(),floot.end());
    floot.clear();
    if (bul!=nullptr)
    {
        qDeleteAll(bul->begin(),bul->end());
        bul->clear();
    }
    bul = nullptr;
    if (ene!=nullptr)
    {
        qDeleteAll(ene->begin(), ene->end());
        ene->clear();
    }
    ene = nullptr;
    delete timer;
    delete s;
    delete bl;
    delete a;
}

void game::keypress_w()
{
    if (!a->isAlive())
        return;
    if (a->isMove())
        a->addPrefx(a->getfx());
    a->setfx(1);
    a->start();
}
void game::keypress_a()
{
    if (!a->isAlive())
        return;
    if (a->isMove())
        a->addPrefx(a->getfx());
    a->setfx(2);
    a->start();
}
void game::keypress_s()
{
    if (!a->isAlive())
        return;
    if (a->isMove())
        a->addPrefx(a->getfx());
    a->setfx(3);
    a->start();
}
void game::keypress_d()
{
    if (!a->isAlive())
        return;
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
    int x, y, w=10, h=20, v=3;
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
   for (int i=0;i<ene->size();i++)
   {
       e = ene->at(i);
       if (!e->isAlive())
       {
           continue;
       }
       e->seek(a->getx(),a->gety(),a->getxx(),a->getyy());
       e->update();
       if (e->isShoot())
       {
           shoot(e);
       }
       w = e->getx();
       l = e->gety();
       if (w>gameWide||w<0||l>gameLength||l<0)
       {
           ene->removeAt(i);
           delete e;
           e = nullptr;
       }
   }
   check();
   dead();

   if (ene->size()<level+2)
   {
        if (enetime<10000)
        {
            enetime+=qrand()%(level+1)*5+10;
        }
        else
        {
            addEnemy();
            enetime = 0;
        }
   }

   if (score>up)
   {
       a->levelUp();
       level++;
       if (up < 50)
       {
           up += 25;
       }
       else if (up < 100)
       {
           up += 50;
       }
       else
       {
           up += 100;
       }
   }

   bl->resize(a->getBlood()*24,40);

   QString str = "your score: "+QString::number(score)+"\nyour level: "+QString::number(level+1);
   s->setText(str);
}

void game::check()
{
    bullet *b;
    enemy *e;
    bool check;
    for (int i=0;i<bul->size();i++)
    {
        check = true;
        b = bul->at(i);

        if (a->isCrash(b))
        {
            a->hurt(b->getAttack());
            bul->removeAt(i);
            delete b;
            b = nullptr;
            check = false;
        }

        for (int j=0;check&&j<ene->size();j++)
        {
            e = ene->at(j);
            if (!e->isAlive())
            {
                continue;
            }

            if (e->isCrash(b))
            {
                e->hurt(b->getAttack());
                bul->removeAt(i);
                delete b;
                b = nullptr;
                check = false;
            }
        }
        if (!check)
        {
            i--;
        }
    }
}

void game::shoot(enemy* e)
{
    int x, y, w=10, h=20, v=2;
    x = e->getx();
    y = e->gety();
//    cout<<"fx:  "<<a->getfx();
    switch (e->getfx()) {
    case 0:
    {
        x += e->getxx();
        y += (e->getxx()-h)/2;
        break;
    }
    case 1:
    {
        x += (e->getxx()-w)/2;
        y += -h;
        break;
    }
    case 2:
    {
        y += (e->getyy()-h)/2;
        x += -w;
        break;
    }
    case 3:
    {
        y += e->getyy();
        x += (e->getxx()-w)/2;
        break;
    }
    default:
        break;
    }
    bullet *b = new bullet(x, y, w, h, e->getfx(), v, e->getAttack());
    b->setParent(this);
    b->show();
    bul->append(b);
}

void game::addEnemy()
{
    int x, y, w=56, h=56, dis=80;

    bool check = true;
    while (check)
    {
        x = qrand() % gameWide;
        y = qrand() % gameLength;
        int disx = x - a->getx();
        int disy = y - a->gety();
        if ((disx<a->getxx()+dis&&disx>-w-dis)&&(disy<a->getyy()+dis&&disy>-h-dis))
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }

    enemy *e = new enemy(x,y,w,h,level);
    e->setParent(this);
    e->show();
    ene->append(e);
}

void game::dead()
{
    enemy *e;
    if (!a->isAlive())
    {
        a->stop();
        if (a->dead())
        {
            timer->stop();
            QMessageBox::critical(0 , "游戏结束", "你的得分为： "+QString::number(score), QMessageBox::Ok | QMessageBox::Default, 0,  0 );
            emit gameover(score);
        }
    }

    for (int i=0;i<ene->size();i++)
    {
        e = ene->at(i);
        if (!e->isAlive())
        {
            e->stop();
            if (e->dead())
            {
                score += e->getAttack()*5;
                ene->removeAt(i);
                delete e;
                e = nullptr;
                i--;
            }
        }
    }
}
