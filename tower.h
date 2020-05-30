#ifndef TOWER_H
#define TOWER_H
#include "rpgobj.h"
#include <QMediaPlayer>
#include <vector>
#include<QPoint>

class Tower : public RPGObj
{
public:
  //  Tower(){};
    Tower(QPoint p);
    bool canUpdate();
    void setTower(QPainter *painter, QPoint p);    

protected:
    static int _attackRange;       //攻击范围
    static int _hurt;              //伤害值
    static int _hurtFreq;          //发射频率


};

#endif // TOWER_H
