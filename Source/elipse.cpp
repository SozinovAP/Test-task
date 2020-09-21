#include "elipse.h"

void Elipse::calcArea()
{
    area = brad * srad * M_PI;
}

Elipse::Elipse() : brad(0), srad(0)
{
    center = {0,0};
    calcArea();
}

Elipse::Elipse(Point _center, double _brad, double _srad) : brad(fmax(_srad, _brad)), srad(fmin(_srad, _brad))
{
    center = _center;
    calcArea();
}

Elipse::Elipse(double _xcent, double _ycent, double _brad, double _srad) : brad(fmax(_srad, _brad)), srad(fmin(_srad, _brad))
{
    center = {_xcent, _ycent};
    calcArea();
}

Elipse::~Elipse()
{
}
