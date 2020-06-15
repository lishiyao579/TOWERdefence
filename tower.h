#ifndef TOWER_H
#define TOWER_H
#include "rpgobj.h"
#include <QMediaPlayer>
#include <vector>
#include <QPoint>
#include <QTimer>
#include "bullet.h"
#include "waterenemy.h"
#include<QCoreApplication>

class WaterEnemy;
class GameWindow;
class Tower : public RPGObj
{
    Q_OBJECT
public:
    Tower(QPoint p, GameWindow *game);
    ~Tower();
    virtual void setTower(QPainter *painter, QPoint p);
    void lockEnemy(WaterEnemy * enemy);
    void searchEnemy();
    QPoint corr;

protected slots:
    void shoot();


protected:
    QPixmap _pix;
    static int _attackRange;//攻击范围
    static int _shootFreq;//发射频率
    WaterEnemy* _enemy;//某一时刻下只会锁定一个攻击对象
    QTimer* _timer;
    GameWindow* _game;



};

#endif // TOWER_H
