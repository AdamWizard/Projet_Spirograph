#include "../include/Point.h"
#include <cmath>

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double x0, double y0)
{
    x = x0;
    y = y0;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

Point::Point(const Point& pointCopie)
{
    x = pointCopie.getX();
    y = pointCopie.getY();
}

void Point::setX(double newX)
{
    x = newX;
}

void Point::setY(double newY)
{
    y = newY;
}

double Point::distanceFromPoint(Point point2)
{
    int X = point2.getX()-getX();
    int Y = point2.getY() - getY();
    return sqrt(X^2 + Y^2);
}

