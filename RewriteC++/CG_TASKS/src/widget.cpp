#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    const int absX = 800;
    const int absY = 600;

    ui->setupUi(this);
    this->resize(absX, absY);          // Задаем размеры виджета, то есть окна
    this->setFixedSize(absX, absY);    // Фиксируем размеры виджета

    scene = new QGraphicsScene();   // Инициализируем графическую сцену
    triangle = new Triangle(QPoint(0,-50), QPoint(50,50), QPoint(-50,50));

    trig = new TriangleGrad_alt(absX, absY, QPoint(0,0), QPoint(-100, -100), QPoint(100, -100), QColor (255, 0, 0), QColor (0, 255, 0), QColor (0, 0, 255));

    std::shared_ptr<Drawable> m_sun = std::make_shared<Sun>(2);
    m_objs.push_back(m_sun);
    std::shared_ptr<Drawable> m_raimbow = std::make_shared<Rainbow>();
    m_objs.push_back(m_raimbow);
    std::shared_ptr<Drawable> m_house = std::make_shared<House>(QColor(97, 67, 18),QColor(255,0,0),QColor(0,0,255));
    m_objs.push_back(m_house);

    house = new House(QColor(97, 67, 18),QColor(255,0,0),QColor(0,0,255));
    rainbow = new Rainbow();
    sun = new Sun(2);
    sun2 = new Sun(3);


    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    scene->setSceneRect(-250,-250,500,500); // Устанавливаем область графической сцены


    scene->addItem(trig);   // Добавляем на сцену треугольник
    trig->setPos(0,0);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::addObj(const std::shared_ptr<Drawable> &obj)
{
    m_objs.push_back(obj);
}
