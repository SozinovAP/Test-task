#pragma once

#define _USE_MATH_DEFINES
#include "cmath"
#include <iostream>

struct Point //структуры описания точки
{
    double x;
    double y;
};

//класс описания окружности
class Circle 
{
private:
    double rad;                 //радиус
protected:
    Point center;               //координаты центра
    double area;                //площадь

    //метод вычисления площадь
    virtual void calcArea();
public:
    Circle();
    Circle(Point _center, double _rad);
    Circle(double _xcent, double _ycent, double _rad);
    virtual ~Circle();

    //получить площадь
    double GetArea();
};