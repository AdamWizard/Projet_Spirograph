#include "../headers/Pencil.h"
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

Pencil::Pencil(sf::Color newColor, float newRho)
{
    circle = new sf::CircleShape(3); // Radius of 1 to form a visible point
    circle->setOrigin(circle->getRadius(), circle->getRadius());
    color = newColor;
    rho = newRho;
    phi = 0;
    angSpeed = 0;
}

Pencil::~Pencil()
{
    delete circle; circle = nullptr;
}

float Pencil::getX() const
{
    return circle->getPosition().x;
}

float Pencil::getY() const
{
    return circle->getPosition().y;
}

float Pencil::getRho() const
{
    return rho;
}

float Pencil::getPhi() const
{
    return phi;
}

float Pencil::getAngSpeed() const
{
    return angSpeed;
}

sf::Color Pencil::getColor() const
{
    return color;
}

sf::CircleShape* Pencil::getCircle()
{
    return circle;
}

void Pencil::setPosition(float newX, float newY)
{
    circle->setPosition(newX, newY);
}

void Pencil::setPhi(float newPhi)
{
    phi = newPhi;
}

void Pencil::setAngSpeed(float newAngSpeed)
{
    angSpeed = newAngSpeed;
}

void Pencil::setColor(sf::Color newColor)
{
    color = newColor;
}

void Pencil::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(*circle,states);
}
