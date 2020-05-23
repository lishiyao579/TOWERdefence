#ifndef TURNPOINT_H
#define TURNPOINT_H
#include<QPoint>
#include<QPainter>

class TurnPoint:public QPoint
{
public:
    TurnPoint();
    void setNextTurn(TurnPoint *nextPoint);
    TurnPoint* nextTurn() const;
    void draw(QPainter *painter) const;

protected:
    TurnPoint * _nextTurn;

};

#endif // TURNPOINT_H
