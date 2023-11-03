#ifndef TRIANGLEGRAD_ALT_H
#define TRIANGLEGRAD_ALT_H


#include "src/drawable.h"
#include <QPainter>
#include <QPoint>

class TriangleGrad_alt : public Drawable
{
public:
    TriangleGrad_alt(const int absX, const int absY, QPoint p1, QPoint p2, QPoint p3,
                                                     QColor colorA, QColor colorB, QColor colorC);
    ~TriangleGrad_alt();

private:
    const int absX;
    const int absY;
    QPoint p1;
    QPoint p2;
    QPoint p3;
    QColor colorA;
    QColor colorB;
    QColor colorC;

protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится треугольник
                                     * */
    /* Определяем метод для отрисовки треугольника
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);




};

#endif // TRIANGLEGRAD_ALT_H

