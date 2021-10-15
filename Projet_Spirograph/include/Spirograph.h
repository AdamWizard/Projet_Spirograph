#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H

#include "MovingPoint.h"

class Spirograph
{
    public:
        Spirograph();
        ~Spirograph();

    private:
        MovingPoint** mPoints;
        MovingPoint* first;
        MovingPoint* last;
        //ajouter une couleur
};

#endif // SPIROGRAPH_H
