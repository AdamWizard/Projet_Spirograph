#ifndef DISC_H_INCLUDED
#define DISC_H_INCLUDED
#include "Shape.h"
#include "Pencil.h"

/**
 *  @class Disc
    @brief Class for the discs that will build our Spirograph

    A Disc object contains a sf::CircleShape,
    an angular speed (to adjust its position every frame), and
    a list of Pencil objects to create multiple curves simultaneously
 */
class Disc : public Shape
{
    public :
        /**
         * @brief Constructor
         * @param radius a double,
         * @param x a double,
         * @param y and another double to initialize the sf::CircleShape circle
         * @param newAngSpeed a last double to set the initial angular speed
         * @param newRotation an int to set the internal/external rotation
         *
         * No need to set the number of pencils, it'll be done later and
         * dynamically by the Spirograph
         * @return An instantiated Disc
         */
        Disc(double radius, double x, double y, double newAngSpeed, int newRotation);

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
        virtual unsigned int getNbPencils() const;

        /**
         * @brief Getter
         * @param i an int to get the ith Pencil of the list
         *
         * A getter for the pencils in listPencils
         * @return the Pencil located at listPencils(i), or null if i is out of range
         */
        virtual Pencil* getPencil(int i);

        /**
         * @brief Getter
         *
         * A getter for the radius of the Disc
         * @return the radius
         */
        double getRadius() const;

        /**
         * @brief Getter
         *
         * A getter for the X coordinate of the Disc, located in circle->getPosition()
         * @return the X coordinate
         */
        virtual float getX() const;


        /**
         * @brief Getter
         *
         * A getter for the Y coordinate of the Disc, located in circle->getPosition()
         * @return the Y coordinate
         */
        virtual float getY() const;

        /**
         * @brief Getter
         *
         * A getter for the angle of the "theta" polar coordinate of the Disc
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
         * @param newX a double for the X coordinate
         * @param newY a double for the Y coordinate
         *
         * A setter for the position of the Disc
         */
        void setPosition(double newX, double newY);

        /**
         * @brief Setter
         * @param newTheta a double for the angle
         *
         * A setter for the angle of the Disc
         */
        void setTheta(double newTheta);

        /**
         * @brief Setter
         * @param newAngSpeed a double for the angular speed
         *
         * A setter for the angular speed of the Disc
         */
        void setAngSpeed(double newAngSpeed);

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

        /**
         * @brief Method to update the coordinates
         * @param disc a pointer on the Disc it rolls around
         * @param speedFactor a float to determine the disc velocity
         *
         * This is the main method to simulate the Spirograph movement by updating the Disc members, along with rollInside
         */
        void rollAround(Disc* disc, float speedFactor);

         /**
         * @brief Method to update the coordinates
         * @param disc a pointer on the Disc it rolls inside
         * @param speedFactor a float to determine the disc velocity
         *
         * This is the main method to simulate the Spirograph movement by updating the Disc members, along with rollAround
         */
        void rollInside(Disc* disc, float speedFactor);

         /**
         * @brief Method to draw the moving structure
         * @param target an sf::RenderTarget object in which the disc will be drawn (i.e the window)
         * @param states an sf::RenderStates object used by SFML to draw
         *
         * This method is used to draw the Spirograph structure (Discs and Pencils white circles)
         */
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    private :
        sf::CircleShape* circle;
        Pencil** listPencils;
        unsigned int nbPencils;
        double theta;
        double angSpeed;
        int rotation; // (1 or -1)
        int direction; // (1 or -1)
};


#endif // DISC_H_INCLUDED
