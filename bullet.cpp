#include "bullet.h"
#include "gamewindow.h"

Bullet::Bullet(int hurt, QPoint startpos, WaterEnemy *enemy, GameWindow* game,bool canslow)
{
    _hurt=hurt;//伤害值！升级的塔不一样！
    _startPos=startpos;
    _endPos=enemy->nowPos();
    _target=enemy;
    _game=game;
    _timer=new QTimer(this);
    _canSlow=canslow;
}

void Bullet::setNowPos(QPoint nowpos){
    _nowPos=nowpos;
}
QPoint Bullet::nowPos()const{
    return _nowPos;
}
void Bullet::move(){
    QPropertyAnimation * animation=new QPropertyAnimation(this,"_nowPos");
    connect(_timer, &QTimer::timeout, this, [=](){
        hitTarget();
        slowTarget();
    });//打中敌人
    const int duration=1000; //设置运动总时长
    animation->setDuration(duration);
    animation->setStartValue(_startPos);
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->setEndValue(_target->nowPos());//_nextTurn);
    animation->start();
    _timer->start(duration);

}

void Bullet::hitTarget(){
    auto iter=find(_game->enemys.begin(), _game->enemys.end(), _target);//查找敌人是否已被打死
    if (iter !=_game->enemys.end()){
        _target->beShot(_hurt);//伤害值为1
    }
    _game->eraseBullet(this);
}

void Bullet::slowTarget(){              ////!!!!!!!!
    if(_canSlow){
        auto iter=find(_game->enemys.begin(), _game->enemys.end(), _target);//查找敌人是否已被打死
        if (iter !=_game->enemys.end()){
            _target->beSlow(1.5);
        }
        _game->eraseBullet(this);
    }
}
void Bullet::setBullet(QPainter *pa){
    QPixmap bullet(":/pics/bullet.png");
    pa->drawPixmap(this->nowPos(),bullet);
}

