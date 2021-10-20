#ifndef DISC_H_INCLUDED
#define DISC_H_INCLUDED
#include "SFML/Graphics.hpp"
#include "Pencil.h"
class Disc
{
    public :
        Disc(sf::CircleShape* newCircle);
        Disc(float radius, float x, float y);
        ~Disc();

        float getRadius();
        float getX();
        float getY();

        void setPosition(float newX, float newY);

        Pencil* getPencil(int i);
        void addPencil(Pencil* pencil);

    private :
        sf::CircleShape* circle;
        Pencil** listPencils;
        unsigned int nbPencils;
};


#endif // DISC_H_INCLUDED
