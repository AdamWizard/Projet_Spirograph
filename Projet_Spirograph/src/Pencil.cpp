#include "../include/Pencil.h"

Pencil::Pencil(sf::Color newColor, float newRho)
{
    circle = new sf::CircleShape(1);
    color = newColor;
    rho = newRho;
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
//void setRho(unsigned float newRho);

