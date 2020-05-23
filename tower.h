#ifndef TOWER_H
#define TOWER_H
#include "rpgobj.h"
#include <QMediaPlayer>
#include <vector>
#include<QPoint>
class Tower : public RPGObj
{
public:
    Tower(){};
    Tower(QPoint p);
    bool canUpdate();
    static void setTower(QPainter *painter, QPoint p);
  //?怎么处理  static int _towerNum;          //塔总数

protected:
    static int _attackRange;       //攻击范围
    static int _hurt;              //伤害值
    static int _hurtFreq;          //发射频率


};

#endif // TOWER_H
