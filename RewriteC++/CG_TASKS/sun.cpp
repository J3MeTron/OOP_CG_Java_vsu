#include "sun.h"

Sun::Sun(int size):
    size(size)
{


}

Sun::~Sun()
{

}

QRectF Sun::boundingRect() const
{
    return QRectF(-25,-40,50,80);   // Ограничиваем область, в которой лежит треугольник
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor linesColor(QColor(242, 255, 0));
    QPen apen = QPen(linesColor);
    apen = QPen(QColor(255, 255, 0));
    apen.setWidth(2);
    painter->setPen(apen);
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawEllipse(220*size, 30*size, 50*size,50*size);

}
