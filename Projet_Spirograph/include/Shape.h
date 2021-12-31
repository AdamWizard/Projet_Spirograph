#ifndef SHAPE_H
#define SHAPE_H

#include "SFML/Graphics.hpp"


class Shape : public sf::Drawable
{
    public:
        virtual float getX() const ;
        virtual float getY() const ;
};

#endif // SHAPE_H
