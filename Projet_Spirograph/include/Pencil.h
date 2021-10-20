#ifndef PENCIL_H_INCLUDED
#define PENCIL_H_INCLUDED
#include "SFML/Graphics.hpp"

class Pencil
{
    public :
        Pencil(sf::Color newColor, float newRho);
        ~Pencil();
        float getX();
        float getY();
        void setPosition(float newX, float newY);
        void setColor(sf::Color newColor);
        float getRho() const;
        //void setRho(unsigned float newRho);

    private :
        sf::CircleShape* circle;
        sf::Color color;
        float rho;
};

#endif // PENCIL_H_INCLUDED
