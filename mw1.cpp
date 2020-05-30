
#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include <QMouseEvent>
#include <QTime>
#include <QTimer>
#include <map>
#include <iostream>
#include "position.h"

using namespace std;

const int towerCost = 100;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);
    setFixedSize(32*32,22*32);
    //init game world
    _game.initWorld();            //TODO 应该是输入有效的地图文件

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(randomMove()));
        //randomMove()为自定义槽函数
    timer->start(50);
    timer->setInterval(500);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置随机种子
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
  //  setFixedSize(500,1001);
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    QPixmap bgpic(":/pics/bg.jpg");
    pa->drawPixmap(0, 0, bgpic);

    this->_game.show(pa);
    pa->setPen(QPen(Qt::blue,10));

    pa->drawPoint(0,175);
   for(int i=0;i<_tower.size();i++){
        _tower[i]->setTower(pa,QPoint(_tower[i]->getPosX(),_tower[i]->getPosY()));
    }

    pa->end();
    delete pa;
}
/*
void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);
    }
    this->repaint();
}

void MW1::randomMove(){

    int d = 1 + rand()%4;//生成随机运动的方向
    this->_game.handlePlayerMove(d,1);
    this->repaint();
}
*/

bool MW1::checkTower(QPoint p) const//检查附近一定范围内是不是有塔 保证不重叠
{
    for(int i =0;i<_tower.size();i++ ){
        if(abs(p.x()-_tower[i]->getPosX())<=2*ICON::GRID_SIZE && abs(p.y()-_tower[i]->getPosY())<=2*ICON::GRID_SIZE){
            return true;
        }
    }
    return false;
}

void MW1::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    if(event->button() == Qt::LeftButton)
    {
        if(!checkTower(pressPos) && Position::checkTowerPosition(pressPos) && canBuyTower())
        {
            Tower *t=new Tower(pressPos);
            _tower.push_back(t);

            update();

            totalTower++;
            totalGold -= towerCost;
        }
    }

}
bool MW1::canBuyTower() const
{
  //  if(this->totalGold >= towerCost)
        return true;
  //  return false;
}

void MW1::loadTurnPoints()
{
    TurnPoint *begin= new TurnPoint(QPoint(0,175));
    _turnPoint.push_back(begin);

    TurnPoint *p1=new TurnPoint(QPoint(880,175));
    _turnPoint.push_back(p1);

    TurnPoint *p2=new TurnPoint(QPoint(880,555));
    _turnPoint.push_back(p2);

    TurnPoint *p3=new TurnPoint(QPoint(607,555));
    _turnPoint.push_back(p3);

    TurnPoint *p4=new TurnPoint(QPoint(610,290));
    _turnPoint.push_back(p4);

    TurnPoint *p5=new TurnPoint(QPoint(200,290));
    _turnPoint.push_back(p5);

    TurnPoint *p6=new TurnPoint(QPoint(212,555));
    _turnPoint.push_back(p6);

    TurnPoint *des=new TurnPoint(QPoint(0,555));
    _turnPoint.push_back(des);

}
