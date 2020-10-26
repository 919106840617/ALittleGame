#include "mainwindow.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    grabKeyboard();
    setWindowTitle("our litle game");
    setFixedSize(gameWide, gameLength);

    g = nullptr;
    menu = new startmenu(this);
    menu->show();
    connect(menu,SIGNAL(gamestart()),this,SLOT(gamestart()));
}

MainWindow::~MainWindow()
{
    if (g!=nullptr)
    {
        delete g;
    }
    if (menu!=nullptr)
    {
        delete menu;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat()&&g!=nullptr)
    {
        switch (event->key()) {
        case Qt::Key_W:
        {
            g->keypress_w();
            break;
        }
        case Qt::Key_A:
        {
            g->keypress_a();
            break;
        }
        case Qt::Key_S:
        {
            g->keypress_s();
            break;
        }
        case Qt::Key_D:
        {
            g->keypress_d();
            break;
        }
        case Qt::Key_J:
        {
            g->keypress_j();
            break;
        }
        case Qt::Key_P:
        {
            g->addEnemy();
            break;
        }
        default:
            break;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat()&&g!=nullptr)
    {
        switch (event->key()) {
        case Qt::Key_W:
        {
            g->keyrelease_w();
            break;
        }
        case Qt::Key_A:
        {
            g->keyrelease_a();
            break;
        }
        case Qt::Key_S:
        {
            g->keyrelease_s();
            break;
        }
        case Qt::Key_D:
        {
            g->keyrelease_d();
            break;
        }
        default:
            break;
        }
    }
}

void MainWindow::gameOver(int score)
{
    g->deleteLater();
    g = nullptr;
    menu->addScore(score);
    menu->show();
}

void MainWindow::gamestart()
{
//    cout<<"start begin";
    g = new game(this);
    g->show();
    connect(g,SIGNAL(gameover(int)),this,SLOT(gameOver(int)));
//    cout<<"start over";
}
