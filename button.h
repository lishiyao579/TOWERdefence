#ifndef BUTTOM_H
#define BUTTOM_H

#include <QWidget>
#include <QPushButton>
#include <string>
#include <QPropertyAnimation>
#include <QPainter>
class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QString pix);
    void zoomDown();
    void zoomUp();

signals:

public slots:
};

#endif // BUTTOM_H
