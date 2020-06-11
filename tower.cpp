#include "tower.h"

int Tower::_attackRange=80;
int Tower::_shootFreq=10;

Tower::Tower(QPoint p)//,GameWindow * game)
{
    this->setPosX(p.x());
    this->setPosY(p.y());
 //   _window=game;

    connect(_timer, SIGNAL(timeout()), this, SLOT(shoot()));
}

void Tower::setTower(QPainter* painter, QPoint p)
{
      painter->save();

      initObj("tower");

      QPixmap tower(":/pics/fire1.png");
      painter->drawPixmap(p.x()-tower.height()/2,p.y()-tower.width()/2,tower);

      painter->setPen(Qt::darkRed);//画攻击圈
      painter->drawEllipse(p,_attackRange,_attackRange);

      painter->restore();
}

WaterEnemy* Tower::lockEnemy(WaterEnemy *enemy){
    _enemy=enemy;
    enemy->beShot(this);//!add!!!
    return _enemy;
}

void Tower::shoot(GameWindow *game){
    _timer=new QTimer(this);
    _timer->start(this->_shootFreq);
    int hurt=20;
    Bullet *bullet=new Bullet(hurt,QPoint(getPosX(),getPosY()),QPoint(_enemy->getPosX(),_enemy->getPosY()),_enemy);
    bullet->move();
 //   bullet->setBullet(painter);
//怎么画？
}

