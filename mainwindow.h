#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define gameWide 1280
#define gameLength 720

#include <QMainWindow>
#include <QKeyEvent>
#include "game.h"
#include "startmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    game* g;
    startmenu* menu;

private slots:
    void gameOver(int score);
    void gamestart();
};

#endif // MAINWINDOW_H
