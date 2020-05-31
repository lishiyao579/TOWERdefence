#ifndef WATERENERMY_H
#define WATERENERMY_H
#include<QPoint>
#include<turnpoint.h>
#include"rpgobj.h"
int turnPointNum=6;
class WaterEnermy : public RPGObj
{
public:
    WaterEnermy();
    void run();
    void onErase();
    bool inShootCircle(QPoint ener,QPoint tow,int range);
    bool atTurnPoint(QPoint ener, TurnPoint *tur, int range);
    //搞一个函数加载拐弯点??

protected:

    int _runSpeed;
    int _hp;
    double _rotationAngle;
    QPoint _nowPos;
    TurnPoint _pos;
   // vector<TurnPoint> _way;




};

#endif // WATERENERMY_H
