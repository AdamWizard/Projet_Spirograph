#include "../include/Disc.h"
#include "../include/Point.h"
#include <stdlib.h>

Disc::Disc()
{
    center = new Point(0,0);
    radius = 0;
}

Disc::Disc(Point* copyCenter, float copyRadius)
{
    center = copyCenter;
    radius = copyRadius;
}

Disc::~Disc()
{
    delete center;
    free(center);
}

Point* Disc::getCenter() const
{
    return center;
}

float Disc::getRadius() const
{
    return radius;
}

Disc::Disc(const Disc& copyDisc)
{
    center = copyDisc.getCenter();
    radius = copyDisc.getRadius();
}

void Disc::setCenter(Point* newCenter)
{
    center = newCenter;
}

void Disc::setRadius(float newRadius)
{
    radius = newRadius;
}
