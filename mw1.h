#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "rpgobj.h"
#include "world.h"
#include "position.h"
#include "tower.h"
#include<QPoint>
#include<math.h>
#include<turnpoint.h>
namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);
    void loadTurnPoints();
//    void keyPressEvent(QKeyEvent *);

protected slots:
  //  void random3Move();
    void mousePressEvent(QMouseEvent *event);
private slots:

    bool checkTower(QPoint P) const;
    bool canBuyTower() const;
   // Tower test;

private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
    vector<Tower*> _tower;           //存已经安放了的塔
    vector<TurnPoint*> _turnPoint;   //存拐点
    int	totalGold=1000;     //起始金币数
    int totalTower=0;       //总塔数
};

#endif // MW1_H
