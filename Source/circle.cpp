#include "circle.h"

void Circle::calcArea()
{
    area = rad * rad * M_PI;
}

Circle::Circle() : center({0,0}), rad(0)
{
    calcArea();
}

Circle::Circle(Point _center, double _rad) : center(_center), rad(_rad)
{
    calcArea();
}

Circle::Circle(double xcent, double ycent, double _rad) : center({xcent, ycent}), rad(_rad)
{
    calcArea();
}

Circle::~Circle()
{
}

double Circle::GetArea()
{
    return area;
}
