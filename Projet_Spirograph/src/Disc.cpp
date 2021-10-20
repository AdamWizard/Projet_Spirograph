#include "../include/Disc.h"
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

Disc::Disc(sf::CircleShape* newCircle)
{
    circle = newCircle;
    listPencils = nullptr;
    nbPencils = 0;

    theta = 0; angSpeed = M_PI/120;
}

Disc::Disc(float radius, float x, float y, float newAngSpeed)
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

    theta = 0; angSpeed = newAngSpeed;
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

sf::CircleShape* Disc::getCircle()
{
    return circle;
}

float Disc::getRadius()
{
    return getCircle()->getRadius();
}

float Disc::getX()
{
    return getCircle()->getPosition().x;
}

float Disc::getY()
{
    return getCircle()->getPosition().y;
}

float Disc::getTheta()
{
    return theta;
}

float Disc::getAngSpeed()
{
    return angSpeed;
}

unsigned int Disc::getNbPencils(){
    return nbPencils;
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

Pencil* Disc::getPencil(int i)
{
    if(i>=0 && i < nbPencils)
        return listPencils[i];
    else
        return nullptr;
}

void Disc::addPencil(Pencil* pencil)
{
    Pencil** newList = new Pencil*[nbPencils+1];
    std::copy(listPencils, listPencils+nbPencils, newList);
    newList[nbPencils] = pencil;
    nbPencils++;
    listPencils = newList;
}
