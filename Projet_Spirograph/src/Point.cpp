#include "../include/Point.h"
#include <cmath>

Point::Point()
{
    rho = 0;
    theta = 0;
}

Point::Point(float rho0, float theta0)
{
    rho = rho0;
    theta = theta0;
}

float Point::getRho() const
{
    return rho;
}

float Point::getTheta() const
{
    return theta;
}

Point::Point(const Point& copyPoint)
{
    rho = copyPoint.getRho();
    theta = copyPoint.getTheta();

void Point::setRho(float newRho)
{
    rho = newRho;
}

void Point::setTheta(float newTheta)
{
    theta = newTheta;
}

double Point::distanceFromPoint(Point point2)
{
    return((getRho())^2+(point2.getRho())^2 - 2*getRho()*point2.getRho()*cos(point2.getTheta()-getTheta()));
}

