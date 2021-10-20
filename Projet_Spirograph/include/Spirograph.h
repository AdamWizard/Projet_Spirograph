#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H
#include <SFML/Window.hpp>
#include "../include/Disc.h"

class Spirograph
{
    public:
        Spirograph(int dimX, int dimY);
        ~Spirograph();

        int getNbDiscs();
        Disc* getDisc(int i);

        void update();

    private:
        int nbDiscs;
        Disc** listDisc;
        float speed;
};

#endif // SPIROGRAPH_H
