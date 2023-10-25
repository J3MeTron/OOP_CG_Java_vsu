#include "trianglegrad.h"
#include "math.h"
#include "fixed.h"
#include <QPoint>

#define roundf(x) floor(x + 0.5f)

TriangleGrad::TriangleGrad(QPoint p1, QPoint p2, QPoint p3, QColor c1,QColor c2,QColor c3):
    point1(p1),
    point2(p2),
    point3(p3),
    color1(c1),
    color2(c2),
    color3(c3)
{

}

TriangleGrad::~TriangleGrad()
{

}

QRectF TriangleGrad::boundingRect() const
{
    return QRectF(-25,-40,50,80);   // Ограничиваем область, в которой лежит треугольник
}

inline void mySwap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void myQswap(QPoint &a, QPoint &b) {
    QPoint temp = a;
    a = b;
    b = temp;
}

void myCswap(QColor &a, QColor &b) {
    QColor temp = a;
    a = b;
    b = temp;
}

int interpolate(int start, int end, int current, int startRange, int endRange)
{
    if (current <= startRange) {
        return start;
    }
    if (current >= endRange) {
        return end;
    }

    double t = static_cast<double>(current - startRange) / (endRange - startRange);
    int result = start + static_cast<int>(t * (end - start));
    return result;
}

QColor interpolateColor(const QColor &startColor, const QColor &endColor, int current, int start, int end)
{
    int r = interpolate(startColor.red(), endColor.red(), current, start, end);
    int g = interpolate(startColor.green(), endColor.green(), current, start, end);
    int b = interpolate(startColor.blue(), endColor.blue(), current, start, end);
    return QColor(r, g, b);
}

#include <QColor>
#include <QPoint>

QColor ShadeBackgroundPixel(QPoint& point1, QPoint& point2, QPoint& point3, const QColor& colorA, const QColor& colorB, const QColor& colorC)
{
    QColor pixelColor(Qt::white); // Присваиваем цвет фона - белый

    double l1, l2, l3;

        l1 = ((point2.ry() - point3.ry()) * (point1.rx() - point3.rx()) + (point3.rx() - point2.rx()) * (point1.ry() - point3.ry())) /
            ((point2.ry() - point3.ry()) * (point1.rx() - point3.rx()) + (point3.rx() - point2.rx()) * (point1.ry() - point3.ry()));

        l2 = ((point3.ry() - point1.ry()) * (point1.rx() - point3.rx()) + (point1.rx() - point3.rx()) * (point1.ry() - point3.ry())) /
            ((point2.ry() - point3.ry()) * (point1.rx() - point3.rx()) + (point3.rx() - point2.rx()) * (point1.ry() - point3.ry()));

        l3 = 1 - l1 - l2;

        if (l1 >= 0 && l1 <= 1 && l2 >= 0 && l2 <= 1 && l3 >= 0 && l3 <= 1)
        {
            int red = l1 * colorA.red() + l2 * colorB.red() + l3 * colorC.red();
            int green = l1 * colorA.green() + l2 * colorB.green() + l3 * colorC.green();
            int blue = l1 * colorA.blue() + l2 * colorB.blue() + l3 * colorC.blue();

            pixelColor = QColor(red, green, blue);
        }

    return pixelColor;
}



void TriangleGrad::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Упорядочиваем точки p1(x1, y1),
    // p2(x2, y2), p3(x3, y3)
    if (point2.ry() < point1.ry()) {
        myQswap(point1, point2);
        myCswap(color1, color2);
    } // точки p1, p2 упорядочены
    if (point3.ry() < point1.ry()) {
        myQswap(point1, point3);
        myCswap(color1, color3);
    } // точки p1, p3 упорядочены
    // теперь p1 самая верхняя
    // осталось упорядочить p2 и p3
    if (point2.ry() > point3.ry()) {
        myQswap(point2, point3);
        myCswap(color2, color3);
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
        myCswap(color1, color2);
    }

    // растеризуем верхний полутреугольник
    for (int i = point1.ry(); i < point2.ry(); i++) {
        int x1 = fixed_to_int(wx1);
        int x2 = fixed_to_int(wx2);

        QColor startColor = interpolateColor(color1, color3, i - point1.ry(), 0, point3.ry() - point1.ry());
        QColor endColor = interpolateColor(color1, color2, i - point1.ry(), 0, point2.ry() - point1.ry());

        for (int j = x1; j <= x2; j++) {
            int current = j - x1;
            QColor pixelColor = interpolateColor(startColor, endColor, current, 0, x2 - x1);
            painter->setPen(pixelColor);
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
        myCswap(color1, color3);
    }

    // растеризуем нижний полутреугольник

    for (int i = point2.ry(); i <= point3.ry(); i++) {
        int x1 = fixed_to_int(wx1);
        int x2 = fixed_to_int(wx2);

        QColor startColor = interpolateColor(color2, color3, i - point2.ry(), 0, point3.ry() - point2.ry());
        QColor endColor = interpolateColor(color1, color2, i - point1.ry(), 0, point2.ry() - point1.ry());

        for (int j = x1; j <= x2; j++) {
            int current = j - x1;
            QColor pixelColor = interpolateColor(startColor, endColor, current, 0, x2 - x1);
            painter->setPen(pixelColor);
            painter->drawPoint(j, i);
        }

        wx1 += _dx13;
        wx2 += dx23;
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


