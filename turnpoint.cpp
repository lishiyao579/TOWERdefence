#include "turnpoint.h"
#include <QPainter>
TurnPoint::TurnPoint()//???不知道怎么构造
{

}

void TurnPoint::setNextTurn(TurnPoint *nextPoint)
{
    this->_nextTurn = nextPoint;
}

TurnPoint* TurnPoint::nextTurn() const
{
    return this->_nextTurn;
}

void TurnPoint::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(QColor(0, 255, 0));
    painter->drawEllipse(this->x(),this->y(), 6, 6);
    painter->drawEllipse(this->x(),this->y(), 2, 2);

    if (_nextTurn)
        painter->drawLine(this->x(),this->y(), _nextTurn->x(),_nextTurn->y());
    painter->restore();
}
