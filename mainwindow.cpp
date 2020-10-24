#include "mainwindow.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("our litle game");
    this->resize(gameWide, gameLength);
    g = new game(this);
    g->show();
}

MainWindow::~MainWindow()
{
    delete g;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
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
    if (!event->isAutoRepeat())
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


