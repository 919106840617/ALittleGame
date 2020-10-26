#ifndef STARTMENU_H
#define STARTMENU_H

#define gameWide 1280
#define gameLength 720

#include <QWidget>
#include <QPushButton>
#include <QList>

class startmenu : public QWidget
{
    Q_OBJECT
public:
    startmenu(QWidget *parent);
    ~startmenu();

private:
    QPushButton *p;

    QList<int> sco;

signals:
    void gamestart();
    void addScore(int s);
    void showScore();
    bool subListSort(int info1, int info2);
};

#endif // STARTMENU_H
