#ifndef DISC_H_INCLUDED
#define DISC_H_INCLUDED
#include "SFML/Graphics.hpp"
#include "Pencil.h"

class Disc
{
    public :
        Disc(sf::CircleShape* newCircle);
        Disc(float radius, float x, float y, float newAngSpeed);
        ~Disc();

        sf::CircleShape* getCircle();
        float getRadius();
        float getX();
        float getY();
        float getTheta();
        float getAngSpeed();

        void setPosition(float newX, float newY);
        void setTheta(float newTheta);
        void setAngSpeed(float newAngSpeed);

        unsigned int getNbPencils();
        Pencil* getPencil(int i);
        void setPencil(int i,Pencil* pencil);
        void addPencil(Pencil* pencil);

    private :
        sf::CircleShape* circle;
        Pencil** listPencils;
        unsigned int nbPencils;
        float theta;
        float angSpeed;
};


#endif // DISC_H_INCLUDED
