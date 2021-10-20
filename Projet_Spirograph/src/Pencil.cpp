#include "../include/Pencil.h"
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

Pencil::Pencil(sf::Color newColor, float newRho)
{
    circle = new sf::CircleShape(1);
    color = newColor;
    rho = newRho;
    theta = 0;
    angSpeed = 0;
}

Pencil::~Pencil()
{
    delete circle; circle = nullptr;
}

float Pencil::getX()
{
    return circle->getPosition().x;
}

float Pencil::getY()
{
    return circle->getPosition().y;
}

void Pencil::setPosition(float newX, float newY)
{
    circle->setPosition(newX, newY);
}

void Pencil::setColor(sf::Color newColor)
{
    color = newColor;
}

float Pencil::getRho() const
{
    return rho;
}

float Pencil::getTheta() const
{
    return theta;
}

void Pencil::setTheta(float newTheta)
{
    theta = newTheta;
}

float Pencil::getAngSpeed() const
{
    return angSpeed;
}

void Pencil::setAngSpeed(float newAngSpeed)
{
    angSpeed = newAngSpeed;
}

sf::CircleShape* Pencil::getCircle()
{
    return circle;
}
