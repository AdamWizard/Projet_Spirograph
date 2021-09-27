#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H
#include "Disque.h"

class Spirograph
{
    public:
        Spirograph();
        Spirograph(Disque* disques);
        virtual ~Spirograph();

    private:
        Disque* disques;
        //ajouter une couleur
};

#endif // SPIROGRAPH_H
