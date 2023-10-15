#include "trianglegrad.h"
#include "math.h"
#include "fixed.h"
#include <QPoint>

#define roundf(x) floor(x + 0.5f)

TriangleGrad::TriangleGrad(QPoint p1, QPoint p2, QPoint p3):
    point1(p1),
    point2(p2),
    point3(p3)
{

}


inline void mySwap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

inline void myQswap(QPoint a, QPoint b)
{
    QPoint t;
    t = a;
    a = b;
    b = t;
}

void TriangleGrad::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Упорядочиваем точки p1(x1, y1),
    // p2(x2, y2), p3(x3, y3)
    if (point2.ry() < point1.ry()) {
        myQswap(point1, point2);
    } // точки p1, p2 упорядочены
    if (point3.ry() < point1.ry()) {
        myQswap(point1, point3);
    } // точки p1, p3 упорядочены
    // теперь p1 самая верхняя
    // осталось упорядочить p2 и p3
    if (point2.ry() > point3.ry()) {
        myQswap(point2, point3);;
    }

    // приращения по оси x для трёх сторон
    // треугольника
    fixed dx13 = 0, dx12 = 0, dx23 = 0;

    // вычисляем приращения
    // в случае, если ординаты двух точек
    // совпадают, приращения
    // полагаются равными нулю
    if (point3.ry() != point1.ry()) {
        dx13 = int_to_fixed(point3.rx() - point1.rx());
        dx13 /= point3.ry() - point1.ry();
    }
    else
    {
        dx13 = 0;
    }

    if (point2.ry() != point1.ry()) {
        dx12 = int_to_fixed(point2.rx() - point1.rx());
        dx12 /= (point2.ry() - point1.ry());
    }
    else
    {
        dx12 = 0;
    }

    if (point3.ry() != point2.ry()) {
        dx23 = int_to_fixed(point3.rx() - point2.rx());
        dx23 /= (point3.ry() - point2.ry());
    }
    else
    {
        dx23 = 0;
    }

    // "рабочие точки"
    // изначально они находятся в верхней точке
    fixed wx1 = int_to_fixed(point1.rx());
    fixed wx2 = wx1;

    // сохраняем приращение dx13 в другой переменной
    int _dx13 = dx13;

    // упорядочиваем приращения таким образом, чтобы
    // в процессе работы алгоритмы
    // точка wx1 была всегда левее wx2
    if (dx13 > dx12)
    {
        mySwap(dx13, dx12);
    }

    // растеризуем верхний полутреугольник
    for (int i = point1.ry(); i < point2.ry(); i++){
        // рисуем горизонтальную линию между рабочими точками
        for (int j = fixed_to_int(wx1); j <= fixed_to_int(wx2); j++){
            painter->drawPoint(j, i);
        }
        wx1 += dx13;
        wx2 += dx12;
    }

    // вырожденный случай, когда верхнего полутреугольника нет
    // надо разнести рабочие точки по оси x,
    // т.к. изначально они совпадают
    if (point1.ry() == point2.ry()){
        wx1 = int_to_fixed(point1.rx());
        wx2 = int_to_fixed(point2.rx());
    }

    // упорядочиваем приращения
    // (используем сохраненное приращение)
    if (_dx13 < dx23)
    {
        mySwap(_dx13, dx23);
    }

    // растеризуем нижний полутреугольник

    for (int i = point2.ry(); i <= point3.ry(); i++){
        // рисуем горизонтальную линию между рабочими точками
        for (int j = fixed_to_int(wx1); j <= fixed_to_int(wx2); j++){
               painter->drawPoint(j,i);
        }
        wx1 += _dx13;
        wx2 += dx23;
    }
}
