#include "../include/Point.h"
#include <cmath>

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(float x0, float y0)
{
    x = x0;
    y = y0;
}

float Point::getX() const
{
    return x;
}

float Point::getY() const
{
    return y;
}

Point::Point(const Point& copyPoint)
{
    x = copyPoint.getX();
    y = copyPoint.getY();
}

void Point::setX(float newX)
{
    x = newX;
}

void Point::setY(float newY)
{
    y = newY;
}

double Point::distanceFromPoint(Point point2)
{
    float X = (point2.getX()-getX())*(point2.getX()-getX());
    float Y = (point2.getY() - getY())*(point2.getY() - getY());
    return sqrt(X + Y);
}

