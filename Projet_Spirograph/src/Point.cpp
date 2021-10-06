#include "../include/Point.h"
#include <cmath>

Point::Point()
{
    r = 0;
    theta = 0;
}

Point::Point(float r0, float t0)
{
    r = r0;
    theta = t0;
}

float Point::getR() const
{
    return r;
}

float Point::getT() const
{
    return t;
}

Point::Point(const Point& copyPoint)
{
    r = copyPoint.getR();
    theta = copyPoint.getT();
}

void Point::setR(float newR)
{
    r = newR;
}

void Point::setT(float newT)
{
    theta = newT;
}

double Point::distanceFromPoint(Point point2)
{
    return((getR())^2+(point2.getR())^2 - 2*getR()*point2.getR()*cos(point2.getT()-getT()));
}

