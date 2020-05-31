#include "button.h"

Button::Button(QString pixmap):QPushButton(0){
    QPixmap pix(pixmap);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
