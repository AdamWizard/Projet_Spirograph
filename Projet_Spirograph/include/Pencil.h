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
        float getRho() const;
        float getTheta() const;
        float getAngSpeed() const;
        sf::CircleShape* getCircle();

        void setPosition(float newX, float newY);
        void setColor(sf::Color newColor);
        void setTheta(float newTheta);
        void setAngSpeed(float newAngSpeed);
        //void setRho(unsigned float newRho);

    private :
        sf::CircleShape* circle;
        sf::Color color;
        float rho;
        float theta;
        float angSpeed;
};

#endif // PENCIL_H_INCLUDED
