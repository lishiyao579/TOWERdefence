#include "position.h"

Position::Position()
{

}
QPoint Position::towerPos[]={
    QPoint(3,3),QPoint(11,3),QPoint(19,3),
    QPoint(7,6),QPoint(15,6),
    QPoint(24,8),QPoint(24,13),QPoint(22,18),
    QPoint(16,12),QPoint(7,12)
};
bool Position::checkTowerPosition(QPoint p)//检查是不是可以放塔的地方
{
    for(int i=0;i<posNum; i++){
        if(p.x()-Position::towerPos[i].x()<=2*ICON::GRID_SIZE && p.y()-Position::towerPos[i].y()<=2*ICON::GRID_SIZE)
            return false;
    }
    return true;
}

