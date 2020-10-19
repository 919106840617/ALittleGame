#ifndef GAME_H
#define GAME_H

#define gameWide 1280
#define gameLength 720

#include <QTimer>
#include <QList>
#include "hero.h"
#include "bullet.h"

class game : public QWidget
{
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
    void keyrelease_j();
    void update();
    void check();

private:
    QList<bullet*> *bul;
    QTimer *timer;
    hero *a;
};

#endif // GAME_H
