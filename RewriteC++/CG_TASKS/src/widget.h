#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include <objs/triangle.h>
#include <objs/house.h>
#include <objs/rainbow.h>
#include <objs/sun.h>
#include <objs/trianglegrad_alt.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void addObj(const std::shared_ptr<Drawable> &obj);

private:
    Ui::Widget                          *ui;
    QGraphicsScene                      *scene;     // Объявляем графическую сцену

    QList<std::shared_ptr<Drawable>>    m_objs;
    Triangle                            *triangle;
    House                               *house;
    Rainbow                             *rainbow;
    Sun                                 *sun;
    Sun                                 *sun2;
    TriangleGrad_alt                    *trig;
};

#endif // WIDGET_H
