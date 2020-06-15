#include "bullet.h"
#include "gamewindow.h"

Bullet::Bullet(int hurt, QPoint startpos, WaterEnemy *enemy, GameWindow* game)
{
    _hurt=hurt;//伤害值！升级的塔不一样！
    _startPos=startpos;
    _endPos=enemy->nowPos();
    _target=enemy;
    _game=game;
    _timer=new QTimer(this);
}

void Bullet::setNowPos(QPoint nowpos){
    _nowPos=nowpos;
}
QPoint Bullet::nowPos()const{
    return _nowPos;
}
void Bullet::move(){
    QPropertyAnimation * animation=new QPropertyAnimation(this,"_nowPos");
    connect(_timer, SIGNAL(timeout()), this, SLOT(hitTarget()));//打中敌人
    const int duration=1000; //设置运动总时长
    animation->setDuration(duration);
    animation->setStartValue(_startPos);
    animation->setEndValue(_target->nowPos());//_nextTurn);
    animation->start();
    _timer->start(duration);

}

void Bullet::hitTarget(){
    auto iter=find(_game->enemys.begin(), _game->enemys.end(), _target);//查找敌人是否已被打死
    if (iter !=_game->enemys.end()){
        _target->beShot(this->_hurt);
    }
    _game->eraseBullet(this);
}
void Bullet::setBullet(QPainter *pa){
    QPixmap bullet(":/pics/bullet.png");
    pa->drawPixmap(this->nowPos(),bullet);
}
