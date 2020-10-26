#ifndef GAME_H
#define GAME_H

#define gameWide 1280
#define gameLength 720

#include <QWidget>
#include <QTimer>
#include <QList>
#include <QLabel>
#include "hero.h"
#include "bullet.h"
#include "enemy.h"

class game : public QWidget
{
    Q_OBJECT

public:
    game(QWidget *parent);
    ~game();
    void keypress_w();
    void keypress_a();
    void keypress_s();
    void keypress_d();
    void keyrelease_w();
    void keyrelease_a();
    void keyrelease_s();
    void keyrelease_d();
    void keypress_j();
    void update();//更新状态
    void check();//检测碰撞
    void shoot(enemy* e);//敌人发射子弹
    void addEnemy();
    void dead();

private:
    int score, up, level, enetime;

    QList<bullet*> *bul;
    QList<enemy*> *ene;
    QList<QLabel*> floot;
    QTimer *timer;
    QLabel *s,*bl;
    hero *a;

signals:
    void gameover(int score);
};

#endif // GAME_H
