#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QPixmap>
#include <QPainter>

QPixmap setTransp(QPixmap image, int alpha)
{
    QPixmap temp(image.size());
    temp.fill(Qt::transparent);

    QPainter p1(&temp);
    p1.setCompositionMode(QPainter::CompositionMode_Source);
    p1.drawPixmap(0, 0, image);
    p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p1.fillRect(temp.rect(), QColor(0, 0, 0, alpha));
    p1.end();
    return temp;
}

#endif // FUNCTIONS_H
