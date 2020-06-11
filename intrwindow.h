#ifndef INTRWINDOW_H
#define INTRWINDOW_H

#include <QMainWindow>
#include "button.h"

class IntrWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit IntrWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:
    void back();
public slots:
};

#endif // INTRWINDOW_H
