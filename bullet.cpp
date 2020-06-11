#include "bullet.h"

Bullet::Bullet(int hurt, QPoint startpos, QPoint endpos, WaterEnemy *enemy)
{
    _hurt=hurt;//伤害值！升级的塔不一样！
    _startPos=startpos;
    _endPos=endpos;
    _target=enemy;
}

void Bullet::setNowPos(QPoint nowpos){
    _nowPos=nowpos;
}
QPoint Bullet::nowPos()const{
    return _nowPos;
}
void Bullet::move(){
    QPropertyAnimation * animation=new QPropertyAnimation(this,"_nowPos");
    const int duration=1000; //设置运动总时长
    animation->setDuration(duration);
    animation->setStartValue(this->_nowPos);
    animation->setEndValue(QPoint(_target->getPosX(),_target->getPosY()));//_nextTurn);
    animation->start();


}
void Bullet::setBullet(QPainter *pa){
    QPixmap bullet(":/pics/bullet.png");
    pa->drawPixmap(this->_nowPos,bullet);
}
