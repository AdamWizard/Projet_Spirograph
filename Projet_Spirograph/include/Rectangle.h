#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(float x,float y,float width,float height);
        virtual ~Rectangle();
        float getArea();
        float getPerimeter();
        /**
         * @brief Getter
         *
         * A getter for the X coordinate of the Rectangle, located in rectangle->getPosition()
         * @return the X coordinate
         */
        float getX() const;
        /**
         * @brief Getter
         *
         * A getter for the Y coordinate of the Rectangle, located in rectangle->getPosition()
         * @return the Y coordinate
         */
        float getY() const;

        sf::RectangleShape* getRectangle() const;

        /**
         * @brief Setter
         * @param newX a float for the X coordinate
         * @param newY a float for the Y coordinate
         *
         * A setter for the position of the Rectangle
         */
        void setPosition(float newX, float newY);



    private:
        sf::RectangleShape* rectangle;
};

#endif // RECTANGLE_H
