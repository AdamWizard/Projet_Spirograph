#include "../include/Disc.h"
#include <iostream>
Disc::Disc(sf::CircleShape newCircle)
{
    circle = newCircle;
    listPencils = nullptr;
    nbPencils = 0;
}

Disc::Disc(float radius, float x, float y)
{
    circle.setRadius(radius);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setOutlineThickness(1);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::White);
    circle.setPosition(x, y);

    listPencils = nullptr;
    nbPencils = 0;
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
    return &circle;
}

float Disc::getRadius()
{
    circle.getRadius();
}

float Disc::getX()
{
    return circle.getPosition().x;
}

float Disc::getY()
{
    return circle.getPosition().y;
}


unsigned int Disc::getNbPencils(){
    return nbPencils;
}

void Disc::setPosition(float newX, float newY)
{
    circle.setPosition(newX, newY);
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
    for(int i = 0; i < nbPencils; i++)
    {
        newList[i] = listPencils[i];
    }
    newList[nbPencils] = pencil;
    nbPencils++;
    listPencils = newList;
    delete newList; newList = nullptr;
}
