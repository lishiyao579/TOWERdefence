#ifndef WATERENERMY_H
#define WATERENERMY_H
#include<QPoint>
#include<QPainter>
#include"rpgobj.h"
#include"tower.h"
#include<QPropertyAnimation>
#include<math.h>
class GameWindow;
class Tower;
class WaterEnemy : public RPGObj
{
    Q_OBJECT
    Q_PROPERTY(QPoint _nowPos READ nowPos WRITE setNowPos)
public:
    WaterEnemy(QPoint nowpos,QPoint endpos,GameWindow * game);
    void move();
    void setEnermy(QPainter *pa);
    void onErase();
    void onSet();
    bool inShootCircle(QPoint tow, int range);
    QPoint nowPos() const;
    void beShot(int hurt);
    void beSlow(double slow);
    void setNowPos(QPoint nowpos);
    void loadTurns();
    void setHp(QPainter* pa);
    QPoint corr;//用于修正位置，传入的是地图拐点，修正成怪的图片中点
    //搞一个函数加载拐弯点??

protected:
    GameWindow* _game;
    QPixmap _pix;
    double _speed;
    int _hp;
    int _maxHp;
    QPoint _nowPos;
    QPoint _endPos;
    vector<QPoint> _Turns;
protected slots:
    void atEnd();



};

#endif // WATERENERMY_H
