#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPainter>
#include "drawable.h"

// Наследуемся от QGraphicsItem
class Triangle : public Drawable
{
public:
    Triangle(QPoint p1, QPoint p2, QPoint p3);
    ~Triangle();

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

#endif // TRIANGLE_H
