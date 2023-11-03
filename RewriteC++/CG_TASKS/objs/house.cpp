#include "house.h"
House::House(QColor roof, QColor window, QColor walls):
    roof(roof),
    window(window),
    walls(walls)
{


}

House::~House()
{

}

QRectF House::boundingRect() const
{
    return QRectF(-25,-40,50,80);   // Ограничиваем область, в которой лежит треугольник
}

void House::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
            QColor linesColor(walls);
            QPen apen = QPen(linesColor);
            apen.setWidth(3);
            painter->setPen(apen);

            //Квадрат - дом
            painter->drawRect(100,100,100,100);

            apen = QPen(QColor(window));
            apen.setWidth(2);
            painter->setPen(apen);

            //Квадрат - окно
            painter->drawRect(120,120,60,60);

            apen = QPen(QColor(roof));
            apen.setWidth(2);
            painter->setPen(apen);
            //Полигон - крыша и дымоход
            static const QPointF points[7] = {
                QPointF(100.0, 100.0),
                QPointF(150.0, 50.0),
                QPointF(170.0, 70.0),
                QPointF(170.0, 50.0),
                QPointF(180.0, 50.0),
                QPointF(180.0, 80.0),
                QPointF(200.0, 100.0)
            };
            painter->drawConvexPolygon(points, 7);


            //Линия - крышка дымохода
            painter->drawLine(QLine(165,50,185,50));
            painter->drawLine(QLine(165,50,175,40));
            painter->drawLine(QLine(175,40,185,50));

        // Рисуем треугольник по полигональной модели
        Q_UNUSED(option);
        Q_UNUSED(widget);



}
