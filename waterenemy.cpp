#include "waterenemy.h"

WaterEnemy::WaterEnemy(QPoint nowpos, QPoint endpos)
{
    this->_pix=QPixmap(":/pics/water1.png");
    this->_nowPos=nowpos;
    this->_endPos=endpos;
    _speed=1;
    _maxHp=100;
    _hp=100;
}

void WaterEnemy::setEnermy(QPainter *pa){
    pa->drawPixmap(_nowPos,_pix);

    pa->save();//画hp
    static const int HpWidth = 50;
    static const int HpHeight = 3;

    QPoint hpBarPoint = _nowPos + QPoint(0, -HpHeight);
    pa->setPen(Qt::NoPen);
    pa->setBrush(Qt::red);
    QRect maxHp(hpBarPoint, QSize(HpWidth, HpHeight));
    pa->drawRect(maxHp);
    pa->setBrush(Qt::green);
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
bool WaterEnemy::inShootCircle(QPoint ener,QPoint tow,int range){
    //????怎么调攻击范围


}

void WaterEnemy::onErase(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/crash.mp3"));
    player->setVolume(30);
    player->play();
}


void WaterEnemy::move(){
    QPropertyAnimation *animation = new QPropertyAnimation(this,"_nowPos");
    const int duration=20000; //设置运动总时长
    animation->setDuration(duration);
    animation->setStartValue(this->_nowPos);
    animation->setKeyValueAt(1.0/8*2,QPoint(840,160));
    animation->setKeyValueAt(1.0/8*3,QPoint(840,540));
    animation->setKeyValueAt(1.0/8*4,QPoint(600,540));
    animation->setKeyValueAt(1.0/8*5,QPoint(600,285));
    animation->setKeyValueAt(1.0/8*6,QPoint(190,285));
    animation->setKeyValueAt(1.0/8*7,QPoint(190,540));
    animation->setEndValue(QPoint(0,540));//_nextTurn);
    animation->start();



   /* if(atTurnPoint(_nowPos, _pos.getNowTurn(),10/*!!!to do 如何调用攻击范围？？？))
    {

        }
        else
        {
        //到终点，死，擦除?????怎么处理
            this->onErase();
        }
    }
    */
}
void WaterEnemy::beShot(Tower *tower){

}
