#include "tower.h"
#include"rpgobj.h"

int Tower::_attackRange=30;

Tower::Tower(QPoint p)
{

}

void Tower::setTower(QPainter *painter, QPoint p)
{

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


