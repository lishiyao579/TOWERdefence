#ifndef TOWER_H
#define TOWER_H
#include "rpgobj.h"
#include <QMediaPlayer>
#include <vector>
#include <QPoint>
#include <QTimer>
#include "bullet.h"
#include "waterenemy.h"

class WaterEnemy;
class GameWindow;
class Tower : public RPGObj
{
public:
    Tower(QPoint p);//,GameWindow* game);
    virtual void setTower(QPainter *painter, QPoint p);
    void shoot(GameWindow *game);
    WaterEnemy *lockEnemy(WaterEnemy * enemy);


protected:
    static int _attackRange;//攻击范围
    static int _shootFreq;//发射频率
    WaterEnemy* _enemy;//某一时刻下只会锁定一个攻击对象
    QTimer* _timer;
    //GameWindow* _window;


};

#endif // TOWER_H
