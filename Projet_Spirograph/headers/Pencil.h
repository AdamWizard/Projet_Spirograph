#ifndef PENCIL_H_INCLUDED
#define PENCIL_H_INCLUDED
#include "SFML/Graphics.hpp"

/**
 *  @brief Class for the points generating the curve
 *
 *  A Pencil object is a sf::CircleShape with a color
 *  and an angular speed that will adjust its position every frame
 */
class Pencil : public sf::Drawable
{
    public :
        /**
         * @brief Constructor
         * @param newColor an sf::Color.
         * @param newRho a float, the distance between the pencil and the center of the disc it's attached to.
         * @return An instantiated Pencil
         */
        Pencil(sf::Color newColor, float newRho);

        /**
         * @brief Destructor
         *
         * Free the memory allocated by the Pencil object
         */
        ~Pencil();

        /**
         * @brief Getter
         *
         * A getter for the X coordinate of the Pencil, located in circle->getPosition()
         * @return the X coordinate
         */
        float getX() const;

        /**
         * @brief Getter
         *
         * A getter for the Y coordinate of the Pencil, located in circle->getPosition()
         * @return the Y coordinate
         */
        float getY() const;

        /**
         * @brief Getter
         *
         * A getter for the radius of the Pencil (distance between it and the center
         * of the Disc it's attached to)
         * @return the radius
         */
        float getRho() const;

        /**
         * @brief Getter
         *
         * A getter for the angle of the Pencil between it and the horizontal axis
         * @return the angle
         */
        float getPhi() const;

        /**
         * @brief Getter
         *
         * A getter for the angular speed of the Pencil
         * @return the angular speed
         */
        float getAngSpeed() const;

        /**
         * @brief Getter
         *
         * A getter for the color of the Pencil
         * @return the color
         */
        sf::Color getColor() const;

        /**
         * @brief Getter
         *
         * A getter for the circle associated with the Pencil
         * @return a pointer on the Pencil circle
         */
        sf::CircleShape* getCircle();

        /**
         * @brief Setter
         * @param newX a float for the X coordinate
         * @param newY a float for the Y coordinate
         *
         * A setter for the position of the Pencil
         */
        void setPosition(float newX, float newY);

        /**
         * @brief Setter
         * @param newPhi a float for the angle
         *
         * A setter for the angle of the Pencil
         */
        void setPhi(float newPhi);

        /**
         * @brief Setter
         * @param angSpeed a float for the angular speed
         *
         * A setter for the angular speed of the Pencil
         */
        void setAngSpeed(float newAngSpeed);

        /**
         * @brief Setter
         *
         * A setter for the color of the Pencil
         * @param newColor an sf::Color for the color
         */
        void setColor(sf::Color newColor);

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
        sf::Color color;
        float rho;
        float phi;
        float angSpeed;
};

#endif // PENCIL_H_INCLUDED
