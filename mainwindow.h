#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define gameWide 1280
#define gameLength 720

#include <QMainWindow>
#include <QKeyEvent>
#include "hero.h"

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
    hero *a;
};

#endif // MAINWINDOW_H
