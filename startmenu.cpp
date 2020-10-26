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
    p->move((gameWide-p->width())/2,(gameLength)/3*2);

    p->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/startpushbutton.png)}");
    p->show();

    showsco = new QPushButton("",this);
    showsco->resize(200,80);
    showsco->move((gameWide-p->width())/2,(gameLength)/3*2+100);

    showsco->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/score_2.png)}");
    showsco->show();

    connect(p,&QPushButton::clicked,[=](){emit gamestart();});

    connect(showsco,&QPushButton::clicked,this,&startmenu::showScore);
}

startmenu::~startmenu()
{
    delete p;
}

void startmenu::addScore(int s)
{
    sco.append(s);
    std::sort(sco.begin(),sco.end());
    if (sco.size()>3)
    {
        sco.removeFirst();
    }
}

void startmenu::showScore()
{
    QString str;
    if (sco.isEmpty())
    {
        str = "无";
    }
    else
    {
        for (int i=sco.size()-1; i>=0; i--)
        {
            str += "第" + QString::number(sco.size()-i)+"名: "+QString::number(sco.at(i))+"\n";
        }
    }
    QWidget *mess = new QWidget;
    mess->resize(300,400);
    mess->setWindowTitle("HIGH SCORE");
    mess->show();

    QLabel *scoreboard = new QLabel(mess);
    scoreboard->resize(mess->size());
    scoreboard->move(0,0);
    scoreboard->setStyleSheet("QLabel{border-image: url(:/new/prefix1/picture/score_3.png)}");

    scoreboard->setText(str);
    scoreboard->setAlignment(Qt::AlignCenter);QFont ft("Microsoft YaHei", 15);
    scoreboard->setFont(ft);
    scoreboard->show();

}
