#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QPainter>
#include "button.h"
#include "gamewindow.h"
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

protected slots:
  //  void random3Move();

private slots:



private:
    Ui::MW1 *ui;

};

#endif // MW1_H
