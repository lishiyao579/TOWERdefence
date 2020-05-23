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
    void keyPressEvent(QKeyEvent *);
    void loadTowerPos();

protected slots:
    void randomMove();

private slots:
    void mousePressEvent(QMouseEvent *event);
    bool checkTower(QPoint P) const;
    bool canBuyTower() const;

private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
    vector<Tower*> tower;           //存已经安放了的塔
    int	totalGold=1000;
};

#endif // MW1_H
