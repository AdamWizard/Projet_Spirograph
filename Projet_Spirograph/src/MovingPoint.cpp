#include "../include/MovingPoint.h"

MovingPoint::MovingPoint()
{
    origin = nullptr;
    rho = 0;
    theta = 0;
    angSpeed = 0;
}

MovingPoint::MovingPoint(const MovingPoint& copyPoint)
{
    origin = copyPoint.origin;
    rho = copyPoint.getRho();
    theta = copyPoint.getTheta();
    angSpeed = copyPoint.getAngSpeed();
}

MovingPoint::MovingPoint(MovingPoint* origin0, float rho0, float theta0, float angSpeed0)
{
    origin = origin0;
    rho = rho0;
    theta = theta0;
    angSpeed = angSpeed0;
}

MovingPoint::~MovingPoint()
{
    delete origin;
    origin = nullptr;
}

float MovingPoint::getRho() const
{
    return rho;
}
float MovingPoint::getTheta() const
{
    return theta;
}

float MovingPoint::getAngSpeed() const
{
    return angSpeed;
}

void MovingPoint::setRho(float newRho)
{
    rho = newRho;
}

void MovingPoint::setTheta(float newTheta)
{
    theta = newTheta;
}
void MovingPoint::setAngSpeed(float newAngSpeed)
{
    angSpeed = newAngSpeed;
}

