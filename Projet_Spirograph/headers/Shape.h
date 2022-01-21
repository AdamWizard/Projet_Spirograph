#ifndef SHAPE_H
#define SHAPE_H

#include "../headers/pencil.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Drawable.hpp"


/**
 *  @class Shape
    @brief Virtual class that represents a 2D shape
 */
class Shape : public sf::Drawable
{
    public:
        /**
        *@brief Getter
        *@return the X coordinate of the Shape
        */
        virtual float getX() const =0;

        /**
        *@brief Getter
        *@return the Y coordinate of the Shape
        */
        virtual float getY() const =0;

        /**
        *@brief Getter
        *@return NbPencils an int, the amount of Pencil objects contained in the Shape
        */
        virtual unsigned int getNbPencils() const =0;

        /**
        *@brief Getter
        *@param i an int, the index of the Pencil you want to get
        *@return the ieth Pencil of the Shape
        */
        virtual Pencil* getPencil(int i) =0;
};

#endif // SHAPE_H
