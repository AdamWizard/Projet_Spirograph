#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include "Disc.h"
#include "Parser.h"

using namespace std;

/**
 *  @class Spirograph
    @brief Main class that will keep track of every object position

    A Spirograph object is an "embedded" list of Disc with a user-given size that
    will simulate the curves created by these discs, even if the construction
    isn't achievable in real life.
 */
class Spirograph
{
    public:
        /**
         * @brief Constructor
         * @param dimX an int, the width of the window the Spirogrpah will be built in
         * @param dimY an int, the height of the window the Spirogrpah will be built in
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
         * A getter for the total number of discs in listDisc
         * @return the number of discs
         */
        int getNbDiscs() const;

        /**
         * @brief Getter
         * @param i an int to get the ith Disc of the list
         *
         * A getter for the discs in listDisc
         * @return the Disc located at listDisc(i), or null if i is out of range
         */
        Disc* getDisc(int i);

        /**
         * @brief Main method to change the coordinates
         *
         * This method will be called in each frame to adjust the coordinates
         * of the discs and pencils thanks to the mathematical equations describing
         * the movement of the centers of all the circles relatively to each others
         */
        void update();


    private:
        int nbDiscs;
        Disc** listDisc;

        /**
         * @brief Small method to check if the window can contain the drawing
         * @param maxPencilDistance an int to specify the farthest pencil
         * @param dimX an int to get the length of the window
         *
         * @return true/false, i.e drawable or not
         */
        bool checkLength(int maxPencilDistance, int dimX);

        /**
         * @brief Check if the Spirograph has done a full rotation
         *
         * This is done by checking if theta of every Disc is >= 2*Pi
         * @return true/false, the reset happened or not
         */
        bool checkReset();
};

#endif // SPIROGRAPH_H
