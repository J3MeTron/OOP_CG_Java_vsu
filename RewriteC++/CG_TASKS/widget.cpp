#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,600);          // Задаем размеры виджета, то есть окна
    this->setFixedSize(600,600);    // Фиксируем размеры виджета

    scene = new QGraphicsScene();   // Инициализируем графическую сцену
    triangle = new Triangle(QPoint(0,-50), QPoint(50,50), QPoint(-50,50));
    grad = new TriangleGrad(QPoint(50,50), QPoint(-50,50), QPoint(0,-50),QColor (255, 0, 0), QColor (0, 255, 0), QColor (0, 0, 255));
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    scene->setSceneRect(-250,-250,500,500); // Устанавливаем область графической сцены

    //scene->addItem(triangle);   // Добавляем на сцену треугольник
    //triangle->setPos(10,0);

    scene->addItem(grad);   // Добавляем на сцену треугольник
    grad->setPos(0,0);
    // Устанавливаем треугольник в центр сцены


}

Widget::~Widget()
{
    delete ui;
}
