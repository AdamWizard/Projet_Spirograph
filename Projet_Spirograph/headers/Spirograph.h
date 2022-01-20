#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include "Shape.h"
#include "Disc.h"
#include "Parser.h"

using namespace std;

/**
 *  @class Spirograph
    @brief Main class that will keep track of every object position

    A Spirograph object is an "embedded" list of Disc objects with a user-given size that
    will simulate the curves created by these Discs, even if the construction
    isn't achievable in real life.
 */
class Spirograph : public sf::Drawable
{
    public:

        /**
         * @brief Constructor using a central Shape and a single Disc
         * @param dimX an int, the width of the window the Spirograph will be built in
         * @param dimY an int, the height of the window the Spirograph will be built in
         * @param centralDisc a Disc pointer, the Disc around which the Disc will roll
         * @param Disc a Disc, the Disc that will roll around the central Disc
         * @return An instantiated Spirograph
         */
        Spirograph(int dimX, int dimY, Shape* centralShape, Disc* rollingDisc);

        /**
         * @brief Constructor
         * @param dimX an int, the width of the window the Spirograph will be built in
         * @param dimY an int, the height of the window the Spirograph will be built in
         * @return An instantiated Spirograph
         */
        Spirograph(int dimX, int dimY);

        /**
         * @brief Constructor
         * @param filepath a string that gives the path to a normalized text file with which we will build the Spirograph object
         * @return An instantiated Spirograph
         */
        Spirograph(string filepath);

        /**
         * @brief Destructor
         *
         * Free the memory allocated by the Spirograph object
         */
        ~Spirograph();

        /**
         * @brief Getter
         *
         * A getter for the total number of Discs in listDisc
         * @return the number of Discs
         */
        int getNbDiscs() const;

        /**
         * @brief Getter
         * @param i an int to get the ith Disc of the list
         *
         * A getter for the Discs in listDisc
         * @return the Disc located at listDisc(i), or null if i is out of range
         */
        Disc* getDisc(int i);

        /**
         * @brief Setter
         * @param newSpeedFactor a float, the value which multiplies the speed of rotation of all Discs (1 is default value)
         *
         */
        void setSpeedFactor(float newSpeedFactor);

        /**
         * @brief Getter
         *
         * A getter for the speedFactor value
         * @return the speedFactor value of the spirograph
         */
        float getSpeedFactor();

        /**
         * @brief Main function to update the position of Discs within the spirograph
         *
         * This method will be called in each frame to adjust the coordinates
         * of the Discs and pencils thanks to the mathematical equations describing
         * the movement of the centers of all the circles relatively to each others
         */
        void update();

        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    private:
        int nbDiscs;
        Shape* centralShape;
        Disc** listDisc;
        float speedFactor;

        /**
         * @brief Small method to check if the window can contain the drawing
         * @param maxPencilDistance an int to specify the farthest pencil
         * @param dimX an int to get the length of the window
         *
         * @return true/false, i.e drawable or not
         */
        bool checkLength(int maxPencilDistance, int dimX);
};

#endif // SPIROGRAPH_H
