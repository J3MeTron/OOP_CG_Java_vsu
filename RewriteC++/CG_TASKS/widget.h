#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include <triangle.h>
#include <trianglegrad.h>
#include <house.h>
#include <rainbow.h>
#include <sun.h>
#include <trianglegrad_alt.h>

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
    Ui::Widget       *ui;
    QGraphicsScene   *scene;     // Объявляем графическую сцену

    QList<std::shared_ptr<Drawable>> m_objs;
    Triangle         *triangle;
    TriangleGrad     *grad1;
    TriangleGrad     *grad2;
    TriangleGrad     *grad3;
    House            *house;
    Rainbow          *rainbow;
    Sun              *sun;
    Sun              *sun2;
    TriangleGrad_alt *trig;
};

#endif // WIDGET_H
