#pragma once

#define _USE_MATH_DEFINES
#include "cmath"
#include <iostream>

struct Point //��������� �������� �����
{
    double x;
    double y;
};

//����� �������� ����������
class Circle 
{
private:
    double rad;                 //������
protected:
    Point center;               //���������� ������
    double area;                //�������

    //����� ���������� �������
    virtual void calcArea();
public:
    Circle();
    Circle(Point _center, double _rad);
    Circle(double _xcent, double _ycent, double _rad);
    virtual ~Circle();

    //�������� �������
    double GetArea();
};