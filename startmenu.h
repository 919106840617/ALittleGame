#ifndef STARTMENU_H
#define STARTMENU_H

#define gameWide 1280
#define gameLength 720

#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QtAlgorithms>
#include <QLabel>

class startmenu : public QWidget
{
    Q_OBJECT
public:
    startmenu(QWidget *parent);
    ~startmenu();

    void addScore(int s);//把上把分数加进去
    void showScore();

private:
    QPushButton *p, *showsco;

    QList<int> sco;

signals:
    void gamestart();
};

#endif // STARTMENU_H
