#include "Spirograph.h"
#include <malloc.h>
Spirograph::Spirograph()
{
    //initialiser avec un disque1 de taille 100 au centre et un disque 2 de taille 50 collé au premier (point a distance 150)
    discs = (Disc**) malloc(sizeof(Disc*)*10);
    Point* center1 = new Point(0,0); // Ca va changer avec les coordonnées polaires
    Point* center2 = new Point(150, 0); // Ca va changer avec les coordonnées polaires
    Disc* disc1= new Disc(center1, 100);
    Disc* disc2= new Disc(center2, 50);
    discs[0] = disc1; discs[1] = disc2;
}

Spirograph::~Spirograph()
{
    while(*discs != nullptr)
    {
        delete *discs;
        discs++;
    }
    delete this->discs;
}
