#ifndef POSITION_H
#define POSITION_H
#include<QPoint>
#include<tower.h>
#include"rpgobj.h"

const int posNum=10;

class Position: public RPGObj
{

public:
    Position();
    static bool checkTowerPosition(QPoint p);
    int X()const {return _x; }
    int Y()const {return _y; }
    //& QPoint isthisPosition() ;

    static char a[5];
    static QPoint towerPos[posNum];
private:

    int _x;
    int _y;   //只初始化一次，就不用new了
};

#endif // POSITION_H
