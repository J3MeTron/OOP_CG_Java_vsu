#ifndef HOUSE_H
#define HOUSE_H

#include <QPainter>
#include "src/drawable.h"

// Наследуемся от QGraphicsItem
class House : public Drawable
{
public:
    House(QColor roof, QColor window, QColor walls);
    ~House();

private:
    QColor roof;
    QColor window;
    QColor walls;
protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится треугольник
                                     * */
    /* Определяем метод для отрисовки треугольника
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};


#endif // HOUSE_H
