#ifndef WATERENERMY_H
#define WATERENERMY_H
#include<QPoint>
#include<QPainter>
#include<turnpoint.h>
#include"rpgobj.h"
#include"tower.h"
#include<QPropertyAnimation>
class Tower;
class WaterEnemy : public RPGObj
{
    Q_OBJECT
    Q_PROPERTY(QPoint _nowPos READ nowPos WRITE setNowPos)
public:
    WaterEnemy(QPoint nowpos,QPoint endpos);
    void move();
    void setEnermy(QPainter *painter);
    void onErase();
    bool inShootCircle(QPoint ener,QPoint tow,int range);
    QPoint nowPos() const;
    void beShot(Tower * tower);
    void setNowPos(QPoint nowpos);
    void loadTurns();
    //搞一个函数加载拐弯点??

protected:
    QPixmap _pix;
    int _speed;
    int _hp;
    int _maxHp;
    QPoint _nowPos;
    QPoint _endPos;
    vector<QPoint> _Turns;


};

#endif // WATERENERMY_H
