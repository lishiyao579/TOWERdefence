#include "bossenemy.h"

BossEnemy::BossEnemy(QPoint nowpos,QPoint endpos,GameWindow * game):WaterEnemy(nowpos,endpos,game)
{
    this->_pix=QPixmap(":/pics/water2.png");
    this->_nowPos=nowpos;
    this->_endPos=endpos;
    _speed=1.5;
    _maxHp=150;
    _hp=150;
}
void BossEnemy::setEnermy(QPainter *pa){
    setHp(pa);
    pa->drawPixmap(_nowPos,_pix);
   // onSet();//???为什么报错
}
