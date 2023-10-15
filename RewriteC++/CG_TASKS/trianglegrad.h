#ifndef TRIANGLEGRAD_H
#define TRIANGLEGRAD_H


#include <QPainter>
#include "drawable.h"
#include <QPoint>

class TriangleGrad : public Drawable
{
public:
    TriangleGrad(QPoint p1, QPoint p2, QPoint p3);
    ~TriangleGrad();

private:
    QPoint point1;
    QPoint point2;
    QPoint point3;
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


