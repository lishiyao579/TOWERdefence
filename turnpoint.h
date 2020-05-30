#ifndef TURNPOINT_H
#define TURNPOINT_H
#include<QPoint>
#include<QPainter>

class TurnPoint:public QPoint
{
public:
    TurnPoint(){};
    TurnPoint(QPoint p);
    void setNextTurn(TurnPoint *nextPoint);
    TurnPoint *getNextTurn() const;
    TurnPoint *getNowTurn() const;
    bool haveNextTurn() const;
    void setTurnPoint();
    void draw(QPainter *painter) const;


protected:
    TurnPoint* _nextTurn;
    TurnPoint*  _nowTurn;

};

#endif // TURNPOINT_H
