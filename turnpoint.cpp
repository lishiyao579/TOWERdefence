#include "turnpoint.h"
#include <QPainter>
TurnPoint::TurnPoint(QPoint p)//???不知道怎么构造
{
    setX(p.x());
    setY(p.y());
    /*
WayPoint::WayPoint(QPoint pos)
    : m_pos(pos)
    , m_nextWayPoint(NULL)
{
*/
}

void TurnPoint::setNextTurn(TurnPoint *nextPoint)
{
    this->_nextTurn = nextPoint;
}
bool TurnPoint::haveNextTurn() const{
    if(this->_nextTurn)
        return true;
    return false;
}
TurnPoint* TurnPoint::getNextTurn() const
{
    return this->_nextTurn;
}

TurnPoint* TurnPoint::getNowTurn() const
{
    return this->_nowTurn;
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
