#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "waterenemy.h"
#include <QPainter>


class GameWindow;
class WaterEnemy;
class Bullet : public QObject  //画的时候通过塔找到对应的游戏页面然后绘制
{
    Q_OBJECT
    Q_PROPERTY(QPoint _nowPos READ nowPos WRITE setNowPos)
public:
    Bullet(int hurt, QPoint startpos, QPoint endpos, WaterEnemy *enemy);

    QPoint nowPos() const;
    void setNowPos(QPoint nowpos);
    void move();
    void setBullet(QPainter* pa );//to do 待写

signals:

public slots:

private:
    QPoint _startPos;//发射位置
    QPoint _endPos;//目标位置？？考虑是否有必要！
    QPoint _nowPos;//当前位置
    WaterEnemy* _target;//目标敌人
    int _hurt;//伤害值
    //GameWindow * _window;//对应的游戏界面




};

#endif // BULLET_H