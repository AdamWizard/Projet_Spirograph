#ifndef DISQUE_H
#define DISQUE_H
#include "Point.h"

class Disque
{
    public:
        Disque();
        Disque(const Disque& disqueCopie);
        Disque(Point* centre, double rayon);
        ~Disque();

        Point* getCentre() const;
        double getRayon() const;

        void setCentre(Point* newCentre);
        void setRayon(double newRayon);

    private:
        double rayon;
        Point* centre;
};

#endif // DISQUE_H
