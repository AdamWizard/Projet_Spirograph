#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H

#include "../include/MovingPoint.h"

class Spirograph
{
    public:
        Spirograph();
        ~Spirograph();
        update();
        MovingPoint* getPoint(int i);
        //getFirst();
        //getLast();

    private:
        int nbPoints;
        MovingPoint** mPoints;
        MovingPoint* first;
        MovingPoint* last;
        //ajouter une couleur
};

#endif // SPIROGRAPH_H
