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
    _game.initWorld();//TODO 应该是输入有效的地图文件

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
    pa->drawPixmap(0, 0, QPixmap(":/pics/bg.jpg"));

   // pa->drawPixmap(0,0, QPixmap(":/pics/bg.png"));//,QRect(3,3,4,1));


    this->_game.show(pa);
    pa->end();
    delete pa;
}

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


bool MW1::checkTower(QPoint p) const//检查是不是有塔
{
    for(int i =0;i<tower.size();i++ ){
        if(p.x()==tower[i]->getPosX() && p.y()==tower[i]->getPosY()){
            return false;
        }
    }
    return false;
}

void MW1::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QPoint pressPos = event->pos();
        if(checkTower(pressPos) && Position::checkTowerPosition(pressPos) && canBuyTower())
        {
            QPainter *painter;
            Tower::setTower(painter, pressPos);
     //   tower.push_back();
            totalGold -= towerCost;
        }
    }

}
bool MW1::canBuyTower() const
{
    if(this->totalGold >= towerCost)
        return true;
    return false;
}
