#ifndef DISC_H_INCLUDED
#define DISC_H_INCLUDED
#include "SFML/Graphics.hpp"
#include "Pencil.h"

/**
 *  @class Disc
    @brief Class for the discs that will build our Spirograph

    A Disc object is an extension of a sf::CircleShape with
    an angular speed (to update its position every frame), and
    a list of Pencil objects to create several curves simultaneously
    with some offset between them
 */
class Disc
{
    public :
        /**
         * @brief Constructor
         * @param radius a float,
         * @param x a float,
         * @param y and another float to initialize the sf::CircleShape circle
         * @param newAngSpeed a last float to set the initial angular speed
         * @param newRotation an int to set the internal/external rotation
         *
         * No need to set the number of pencils, it'll be done later and
         * dynamically by the Spirograph
         * @return An instantiated Disc
         */
        Disc(float radius, float x, float y, float newAngSpeed, int newRotation);

        /**
         * @brief Destructor
         *
         * Free the memory allocated by the Disc object
         */
        ~Disc();

        /**
         * @brief Getter
         *
         * A getter for the circle associated with the Disc
         * @return a pointer on the Disc circle
         */
        sf::CircleShape* getCircle() const;

        /**
         * @brief Getter
         *
         * A getter for the total number of pencils in listPencils
         * @return the number of pencils
         */
        unsigned int getNbPencils() const;

        /**
         * @brief Getter
         * @param i an int to get the ith Pencil of the list
         *
         * A getter for the pencils in listPencils
         * @return the Pencil located at listPencils(i), or null if i is out of range
         */
        Pencil* getPencil(int i);

        /**
         * @brief Getter
         *
         * A getter for the radius of the Disc
         * @return the radius
         */
        float getRadius() const;

        /**
         * @brief Getter
         *
         * A getter for the X coordinate of the Disc, located in circle->getPosition()
         * @return the X coordinate
         */
        float getX() const;

        /**
         * @brief Getter
         *
         * A getter for the Y coordinate of the Disc, located in circle->getPosition()
         * @return the Y coordinate
         */
        float getY() const;

        /**
         * @brief Getter
         *
         * A getter for the angle of the Disc between its center and the horizontal axis
         * @return the angle
         */
        float getTheta() const;

        /**
         * @brief Getter
         *
         * A getter for the angular speed of the Disc
         * @return the angular speed
         */
        float getAngSpeed() const;

        /**
         * @brief Getter
         *
         * A getter for the rotation of the Disc
         * @return the rotation
         */
        int getRotation() const;

        /**
         * @brief Getter
         *
         * A getter for the direction of the Disc
         * @return the direction
         */
        int getDirection() const;

        /**
         * @brief Setter
         * @param newX a float for the X coordinate
         * @param newY a float for the Y coordinate
         *
         * A setter for the position of the Disc
         */
        void setPosition(float newX, float newY);

        /**
         * @brief Setter
         * @param newTheta a float for the angle
         *
         * A setter for the angle of the Disc
         */
        void setTheta(float newTheta);

        /**
         * @brief Setter
         * @param newAngSpeed a float for the angular speed
         *
         * A setter for the angular speed of the Disc
         */
        void setAngSpeed(float newAngSpeed);

        /**
         * @brief Setter
         * @param newRotation an int for the rotation
         *
         * A setter for the rotation (internal or external) of the Disc
         */
        void setRotation(int newRotation);

        /**
         * @brief Setter
         * @param newDirection an int for the direction
         *
         * A setter for the direction (clockwise or trigonometric) of the Disc
         */
        void setDirection(int newDirection);

        /**
         * @brief Setter
         * @param pencil a pointer to a Pencil
         *
         * A setter which add dynamically a Pencil pointer to listPencils
         */
        void addPencil(Pencil* pencil);

    private :
        sf::CircleShape* circle;
        Pencil** listPencils;
        unsigned int nbPencils;
        float theta;
        float angSpeed;
        int rotation; // (1 or -1)
        int direction; // (1 or -1)
};


#endif // DISC_H_INCLUDED
