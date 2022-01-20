#ifndef SHAPE_H
#define SHAPE_H

#include "../headers/pencil.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Drawable.hpp"


class Shape : public sf::Drawable
{
    public:
        virtual float getX() const =0;
        virtual float getY() const =0;
        virtual unsigned int getNbPencils() const =0;
        virtual Pencil* getPencil(int i) =0;
};

#endif // SHAPE_H
