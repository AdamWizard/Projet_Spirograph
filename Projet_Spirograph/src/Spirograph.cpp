#include "Spirograph.h"

Spirograph::Spirograph()
{
    //initialiser avec un disque1 de taille 100 au centre et un disque 2 de taille 50 collé au premier (point a distance 150)
}

Spirograph::Spirograph(Disque*disques)
{
    this->disques=disques;
}

Spirograph::~Spirograph()
{
    delete this->disques;
}
