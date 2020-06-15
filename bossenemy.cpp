#include "bossenemy.h"

BossEnemy::BossEnemy(QPoint nowpos,QPoint endpos,GameWindow * game):WaterEnemy(nowpos,endpos,game)
{
    this->_pix=QPixmap(":/pics/water2.png");
    this->_nowPos=nowpos;
    this->_endPos=endpos;
    _speed=1.8;
    _maxHp=150;
    _hp=150;
}
