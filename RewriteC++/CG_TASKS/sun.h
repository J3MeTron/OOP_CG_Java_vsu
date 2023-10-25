#ifndef SUN_H
#define SUN_H


#include <QPainter>
#include "drawable.h"

// Наследуемся от QGraphicsItem
class Sun : public Drawable
{
public:
    Sun(int size);
    ~Sun();

private:
    int size;
protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится треугольник
                                     * */
    /* Определяем метод для отрисовки треугольника
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // SUN_H
