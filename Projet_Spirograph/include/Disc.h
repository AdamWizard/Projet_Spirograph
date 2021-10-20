#ifndef DISC_H_INCLUDED
#define DISC_H_INCLUDED
#include "SFML/Graphics.hpp"
#include "Pencil.h"
class Disc
{
    public :
        Disc(sf::CircleShape newCircle);
        Disc(float radius, float x, float y);
        ~Disc();

        sf::CircleShape* getCircle();
        float getRadius();
        float getX();
        float getY();
        float getTheta();

        void setPosition(float newX, float newY);

        unsigned int getNbPencils();
        Pencil* getPencil(int i);
        void setPencil(int i,Pencil* pencil);
        void addPencil(Pencil* pencil);

    private :
        sf::CircleShape circle;
        Pencil** listPencils;
        unsigned int nbPencils;
        float theta;
};


#endif // DISC_H_INCLUDED
