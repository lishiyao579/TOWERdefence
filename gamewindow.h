#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "rpgobj.h"
#include "tower.h"
#include<QPoint>
#include<math.h>
#include "waterenemy.h"
#include "icon.h"
#include <QMouseEvent>
#include <QTime>
#include <map>
#include <iostream>
#include "button.h"
#include "bullet.h"
#include "world.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void loadTurnPoints();

//    void keyPressEvent(QKeyEvent *);


protected slots:
    void updateMap();
    void mousePressEvent(QMouseEvent *event);
    void setTower(QPoint pos);
    void setEnemy();
    void removeEnemy(WaterEnemy *enemy);
    bool loadWave();
    void setBullet(Bullet *bullet);

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
    vector<QPoint*> _turnPoint;   //存拐点
    vector<WaterEnemy*> _enemy;    //存怪
    int	_totalGold;     //起始金币数
    int _totalTower;       //总塔数
    int _waves;
    QPoint _startPos;
    QPoint _endPos;
    void showGold(QPainter *p);
    void showWave(QPainter *p);
};

#endif // GAMEWINDOW_H

