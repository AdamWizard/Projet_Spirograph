#include "../headers/Disc.h"
#include <cmath>

Disc::Disc(float radius, float x, float y, float newAngSpeed, int newRotation)
{
    circle = new sf::CircleShape();
    circle->setRadius(radius);
    circle->setOrigin(circle->getRadius(), circle->getRadius());
    circle->setOutlineThickness(1);
    circle->setFillColor(sf::Color::Transparent);
    circle->setOutlineColor(sf::Color::White);
    circle->setPosition(x, y);

    listPencils = nullptr;
    nbPencils = 0;

    theta = 0; angSpeed = newAngSpeed; rotation = newRotation;
}

Disc::~Disc()
{
    for(int i = 0; i < nbPencils; i++)
    {
        delete listPencils[i];
        listPencils[i] = nullptr;
    }
    delete listPencils; listPencils = nullptr;

    //delete circle; circle = nullptr;
}

sf::CircleShape* Disc::getCircle() const
{
    return circle;
}

unsigned int Disc::getNbPencils() const
{
    return nbPencils;
}

Pencil* Disc::getPencil(int i)
{
    if(i>=0 && i < nbPencils) // To avoid memory read problems
        return listPencils[i];
    else
        return nullptr;
}

float Disc::getRadius() const
{
    return getCircle()->getRadius();
}

float Disc::getX() const
{
    return getCircle()->getPosition().x;
}

float Disc::getY() const
{
    return getCircle()->getPosition().y;
}

float Disc::getTheta() const
{
    return theta;
}

float Disc::getAngSpeed() const
{
    return angSpeed;
}

int Disc::getRotation() const
{
    return rotation;
}

int Disc::getDirection() const
{
    return direction;
}

void Disc::setPosition(float newX, float newY)
{
    getCircle()->setPosition(newX, newY);
}

void Disc::setTheta(float newTheta)
{
    theta = newTheta;
}

void Disc::setAngSpeed(float newAngSpeed)
{
    angSpeed = newAngSpeed;
}

void Disc::setRotation(int newRotation)
{
    rotation = newRotation;
}

void Disc::setDirection(int newDirection)
{
    direction = newDirection;
}

void Disc::addPencil(Pencil* pencil)
{
    Pencil** newList = new Pencil*[nbPencils+1];
    std::copy(listPencils, listPencils+nbPencils, newList); // Safer than copying manually with a for loop
    newList[nbPencils] = pencil;
    nbPencils++;
    listPencils = newList;
}
