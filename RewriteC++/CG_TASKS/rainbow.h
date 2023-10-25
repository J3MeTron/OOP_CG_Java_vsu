#ifndef RAINBOW_H
#define RAINBOW_H

#include <QPainter>
#include "drawable.h"

// Наследуемся от QGraphicsItem
class Rainbow : public Drawable
{
public:
    Rainbow();
    ~Rainbow();

private:
protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится треугольник
                                     * */
    /* Определяем метод для отрисовки треугольника
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // RAINBOW_H
