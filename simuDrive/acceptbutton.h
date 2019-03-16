#ifndef ACCEPTBUTTON_H
#define ACCEPTBUTTON_H

#include <QPushButton>

class AcceptButton : public QPushButton
{
    Q_OBJECT

private:
    int red, green, blue;
    int s_length;
    //QPixmap *pix;
};

#endif // ACCEPTBUTTON_H
