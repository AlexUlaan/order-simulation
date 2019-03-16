#ifndef REFUSEBUTTON_H
#define REFUSEBUTTON_H

#include <QPushButton>

class RefuseButton : public QPushButton
{
    Q_OBJECT

private:
    int red, green, blue;
    int s_length;
    //QPixmap *pix;
};

#endif // REFUSEBUTTON_H
