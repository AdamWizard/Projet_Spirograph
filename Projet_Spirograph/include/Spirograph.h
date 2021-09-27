#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H
#include "Disque.h"

class Spirograph
{
    public:
        Spirograph();
        Spirograph(Disc* discs);
        virtual ~Spirograph();

    private:
        Disc* discs;
        //ajouter une couleur
};

#endif // SPIROGRAPH_H
