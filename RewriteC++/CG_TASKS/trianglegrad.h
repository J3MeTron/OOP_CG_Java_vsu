#ifndef TRIANGLEGRAD_H
#define TRIANGLEGRAD_H

#include "drawable.h"
#include <QPainter>
#include <QPoint>

class TriangleGrad : public Drawable
{
public:
    TriangleGrad(QPoint p1, QPoint p2, QPoint p3, QColor c1,QColor c2,QColor c3);
    ~TriangleGrad();

private:
    QPoint point1;
    QPoint point2;
    QPoint point3;
    QColor color1;
    QColor color2;
    QColor color3;
protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится треугольник
                                     * */
    /* Определяем метод для отрисовки треугольника
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // TRIANGLEGRAD_H


