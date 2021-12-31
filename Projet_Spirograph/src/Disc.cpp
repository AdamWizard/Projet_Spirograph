#include "../headers/Disc.h"
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

Disc::Disc(sf::CircleShape* newCircle)
{
    circle = newCircle;
    listPencils = nullptr;
    nbPencils = 0;

    theta = 0;
    angSpeed = M_PI/120; // Default framerate, must be a multiple of 60 to work efficiently
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

void Disc::addPencil(Pencil* pencil)
{
    Pencil** newList = new Pencil*[nbPencils+1];
    std::copy(listPencils, listPencils+nbPencils, newList); // Safer than copying manually with a for loop
    newList[nbPencils] = pencil;
    nbPencils++;
    listPencils = newList;
}

void Disc::rollAround(Disc* disc, float speedFactor)
{
float R1 = disc->getRadius();
        float R2 = this->getRadius();
        float theta = this->getTheta();

        // Slowly update theta
        if(this->getAngSpeed()*disc->getAngSpeed() < 0)
            theta += this->getAngSpeed()-disc->getAngSpeed();
        else
            theta += speedFactor*(this->getAngSpeed()+disc->getAngSpeed());

        this->setTheta(theta);

        // Formulas explained in the README
        this->setPosition(disc->getX() + (R1+R2) * cos(theta),
                                 disc->getY() + (R1+R2) * sin(theta));

        for(int j = 0; j < this->getNbPencils(); j++)
        {
            Pencil* currentPencil = this->getPencil(j);
            float rho = currentPencil->getRho();
            float phi = currentPencil->getPhi();

            // Formulas explained in the README
            float penAngSpeed = (R1/R2)*this->getAngSpeed();

            phi += speedFactor*penAngSpeed;
            currentPencil->setPhi(phi);

            currentPencil->setPosition(this->getX() + rho * cos(theta + phi),
                                       this->getY() + rho * sin(theta + phi));
        }
}

void Disc::rollAround(Rectangle* rectangle, float speedFactor)
{
    float R2 = this->getRadius();

    //If the Disc is on a side of the rectangle, it just goes straight along the side

    //if the Disc is touching a corner
    //rotating around it is basically rotating around a single point i.e a Disc with radius=0
    //this->setPosition(newX, newY);
}

void Disc::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    target.draw(circle,states);
}

