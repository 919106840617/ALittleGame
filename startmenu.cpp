#include "startmenu.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__":"<<__LINE__<<"]"

startmenu::startmenu(QWidget *parent)
    :QWidget(parent)
{
    resize(gameWide,gameLength);

    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/picture/start.png")));
    setPalette(pal);

    p = new QPushButton("",this);
    p->resize(200,80);
    p->move((gameWide-p->width())/2,(gameLength)/3*2+50);

    p->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/startpushbutton.png)}");
    p->show();


    connect(p,&QPushButton::clicked,[=](){emit gamestart();});
}

startmenu::~startmenu()
{
    delete p;
}

void startmenu::addScore(int s)
{
    sco.append(s);
    qSort(sco.begin(),sco.end(),subListSort);
    if (sco.size()>3)
    {
        sco.removeLast();
    }
}

bool startmenu::subListSort(int info1, int info2)
{
    return info1 < info2;
 //return info1 < info2;
}

void startmenu::showScore()
{
    for (int i=0; i<sco.size(); i++)
    {
        cout<<sco.at(i)<<endl;
    }
}
