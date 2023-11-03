#include "rainbow.h"

Rainbow::Rainbow(): Drawable()
{


}

Rainbow::~Rainbow()
{

}

QRectF Rainbow::boundingRect() const
{
    return QRectF(-25,-40,50,80);   // Ограничиваем область, в которой лежит треугольник
}

void Rainbow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Дуга - Радуга

    QColor linesColor(QColor("red"));
    QPen apen = QPen(linesColor);
    apen = QPen(QColor("red"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,10,100,100,30*16,120*16);

    apen = QPen(QColor("orange"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,12,100,100,30*16,120*16);

    apen = QPen(QColor("yellow"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,14,100,100,30*16,120*16);

    apen = QPen(QColor("green"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,16,100,100,30*16,120*16);

    apen = QPen(QColor("lightblue"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,18,100,100,30*16,120*16);

    apen = QPen(QColor("blue"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,20,100,100,30*16,120*16);

    apen = QPen(QColor("violet"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,22,100,100,30*16,120*16);


        Q_UNUSED(option);
        Q_UNUSED(widget);



}
