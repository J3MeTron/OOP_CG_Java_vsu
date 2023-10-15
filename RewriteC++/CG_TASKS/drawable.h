#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QGraphicsItem>
#include <QPainter>

// Наследуемся от QGraphicsItem
class Drawable : public QGraphicsItem
{
public:
    Drawable();
    ~Drawable();

protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится треугольник
                                     * */
    /* Определяем метод для отрисовки треугольника
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // DRAWABLE_H


