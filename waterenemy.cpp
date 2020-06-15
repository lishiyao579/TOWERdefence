#include "waterenemy.h"
#include "gamewindow.h"
WaterEnemy::WaterEnemy(QPoint nowpos, QPoint endpos,GameWindow * game)
{
    this->_pix=QPixmap(":/pics/water1.png");
    corr=QPoint(_pix.width()/2,_pix.height()/2);
    this->_nowPos=nowpos;
    this->_endPos=endpos;
    _speed=1;
    _maxHp=100;
    _hp=100;
    _game=game;
}

void WaterEnemy::setEnermy(QPainter *pa){
    setHp(pa);
    pa->drawPixmap(_nowPos,_pix);
   // onSet();//???为什么报错
}
void WaterEnemy::setHp(QPainter *pa){

    pa->save();//画hp
    const int HpWidth = 50;
    const int HpHeight = 3;

    QPoint hpBarPoint = _nowPos + QPoint(0, -HpHeight);
    pa->setPen(Qt::blue);
    pa->setBrush(Qt::red);
    QRect maxHp(hpBarPoint, QSize(HpWidth, HpHeight));
    pa->drawRect(maxHp);
    pa->setBrush(Qt::green);
    pa->setPen(Qt::NoPen);
    QRect hp(hpBarPoint, QSize((double)_hp/_maxHp*HpWidth, HpHeight));
    pa->drawRect(hp);
    pa->restore();
}
QPoint WaterEnemy::nowPos() const{
    return this->_nowPos;
}
void WaterEnemy::setNowPos(QPoint nowpos){
    this->_nowPos=nowpos;
}
bool WaterEnemy::inShootCircle(QPoint tow,int range){
    QPoint c=_nowPos+corr;
    int dis=sqrt((tow.x()-c.x())*(tow.x()-c.x())+(tow.y()-c.y())*(tow.y()-c.y()));
    if(dis<=range)
        return 1;
    return 0;

}

void WaterEnemy::move(){
    QPropertyAnimation *animation = new QPropertyAnimation(this,"_nowPos");
    const double duration=80000.0/_speed; //设置运动总时长
    animation->setDuration(duration);
    animation->setStartValue(*_game->turnPoints[0]);
    for(int i=1;i<_game->turnPoints.size()-1;i++){
        animation->setKeyValueAt(0.125*(i+1), *_game->turnPoints[i]);
    }
    animation->setEndValue(*_game->turnPoints.back());
    animation->start();


        //到终点，死，擦除?????处理
}
void WaterEnemy::beShot(int hurt){
    //_hp-=hurt;
    if(_hp-hurt >0){
        _hp-=hurt;
    }
    else{
        _game->eraseEnemy(this);
        onErase();

    }
}
void WaterEnemy::onSet(){
    QMediaPlayer *p = new QMediaPlayer;
    p->setMedia(QUrl(("qrc:/sounds/e-b.wav")));
    p->setVolume(10);
    p->play();
}
void WaterEnemy::onErase(){
    QMediaPlayer *p = new QMediaPlayer;
    p->setMedia(QUrl("qrc:/sounds/e-mp3"));
    p->setVolume(10);
    p->play();

}
