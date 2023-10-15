#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include <triangle.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget       *ui;
    QGraphicsScene   *scene;     // Объявляем графическую сцену
    Triangle         *triangle;
};

#endif // WIDGET_H