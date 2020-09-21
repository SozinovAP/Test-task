#pragma once

#define _USE_MATH_DEFINES
#include "cmath"

#include "circle.h"
#include <iostream>

//класс описани€ Ёллипса
class Elipse : public Circle
{
private:
    double brad;                //больша€ полуось
    double srad;                //мала€ полуось
protected:

    //метод вычислени€ площадь
    void calcArea() override;
public:

    Elipse();
    Elipse(Point _center, double _brad, double _srad);
    Elipse(double _xcent, double _ycent, double _brad, double _srad);
    ~Elipse() override;
};