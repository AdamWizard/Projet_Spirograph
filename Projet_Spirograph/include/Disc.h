#ifndef DISC_H
#define DISC_H
#include "Point.h"

class Disc
{
    public:
        Disc();
        Disc(const Disc& copyDisc);
        Disc(Point* center, float radius);
        ~Disc();

        Point* getCenter() const;
        float getRadius() const;

        void setCenter(Point* newCenter);
        void setRadius(float newRadius);

    private:
        float radius;
        Point* center;
};

#endif // Disc_H
