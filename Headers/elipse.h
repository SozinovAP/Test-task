#pragma once

#define _USE_MATH_DEFINES
#include "cmath"

#include "circle.h"
#include <iostream>

//����� �������� �������
class Elipse : public Circle
{
private:
    double brad;                //������� �������
    double srad;                //����� �������
protected:

    //����� ���������� �������
    void calcArea() override;
public:

    Elipse();
    Elipse(Point _center, double _brad, double _srad);
    Elipse(double _xcent, double _ycent, double _brad, double _srad);
    ~Elipse() override;
};