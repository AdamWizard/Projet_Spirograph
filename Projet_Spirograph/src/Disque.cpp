#include "../include/Disque.h"
#include "../include/Point.h"

Disque::Disque()
{
    centre = new Point(0,0);
    rayon = 0;
}

Disque::Disque(Point* centreCopie, double rayonCopie)
{
    centre = centreCopie;
    rayon = rayonCopie;
}

Disque::~Disque()
{
    delete centre;
}

Point* Disque::getCentre() const
{
    return centre;
}

double Disque::getRayon() const
{
    return rayon;
}

Disque::Disque(const Disque& disqueCopie)
{
    centre = disqueCopie.getCentre();
    rayon = disqueCopie.getRayon();
}

void Disque::setCentre(Point* newCentre)
{
    centre = newCentre;
}

void Disque::setRayon(double newRayon)
{
    rayon = newRayon;
}
