#include "mainwindow.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("our litle game");
    this->resize(gameWide, gameLength);
    a = new hero(10,10,40,40,20,20,20);
    a->setParent(this);
    a->setPixmap(QPixmap(":/new/prefix1/0.1.png"));
    a->setScaledContents(true);
    a->setGeometry(a->getx(), a->gety(), a->getxx(), a->getyy());
    a->setspeed(2);
}

MainWindow::~MainWindow()
{
    delete a;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch (event->key()) {
        case Qt::Key_W:
        {
            if (a->isMove())
                a->addPrefx(a->getfx());
            a->setfx(1);
            break;
        }
        case Qt::Key_A:
        {
            if (a->isMove())
                a->addPrefx(a->getfx());
            a->setfx(2);
            break;
        }
        case Qt::Key_S:
        {
            if (a->isMove())
                a->addPrefx(a->getfx());
            a->setfx(3);
            break;
        }
        case Qt::Key_D:
        {
            if (a->isMove())
                a->addPrefx(a->getfx());
            a->setfx(0);
            break;
        }
        default:
            break;
        }
        a->start();
        a->startMove();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch (event->key()) {
        case Qt::Key_W:
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
                    a->stopMove();
                }
            }
            else
            {
                a->removePrefx(1);
            }
            break;
        }
        case Qt::Key_A:
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
                    a->stopMove();
                }
            }
            else
            {
                a->removePrefx(2);
            }
            break;
        }
        case Qt::Key_S:
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
                    a->stopMove();
                }
            }
            else
            {
                a->removePrefx(3);
            }
            break;
        }
        case Qt::Key_D:
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
                    a->stopMove();
                }
            }
            else
            {
                a->removePrefx(0);
            }
            break;
        }
        default:
            break;
        }
    }
}


