#include "tower.h"
#include"rpgobj.h"

int Tower::_attackRange=80;

Tower::Tower(QPoint p)
{
    this->setPosX(p.x());
    this->setPosY(p.y());
}

void Tower::setTower(QPainter* painter, QPoint p)
{
      painter->save();

      QPixmap tower;//画塔
      tower.load(":/pics/fire1.png");
      painter->drawPixmap(p.x()-tower.height()/2,p.y()-tower.width()/2,tower);


      initObj("tower");
      painter->setPen(Qt::darkRed);//画攻击圈
      painter->drawEllipse(p,_attackRange,_attackRange);

      painter->restore();
}
/*{
    Tower *p1 = new Tower;
    p1->initObj("tower");
    p1->setPosX(p.x());
    p1->setPosY(p.y());

    painter->save();
    painter->setPen(Qt::white);
    // 绘制攻击范围
    painter->drawEllipse(p.x(),p.y(), _attackRange,_attackRange);

    painter->restore();
}

*/
