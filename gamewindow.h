#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

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

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void loadTurnPoints();
//    void keyPressEvent(QKeyEvent *);


protected slots:
  //  void randomMove();
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:



private slots:

    bool checkTower(QPoint P) const;
    bool canBuyTower() const;
   // Tower test;

private:
    World _game;
    QTimer *timer;
    vector<Tower*> _tower;           //存已经安放了的塔
    vector<TurnPoint*> _turnPoint;   //存拐点
    int	totalGold=1000;     //起始金币数
    int totalTower=0;       //总塔数
};

#endif // GAMEWINDOW_H

