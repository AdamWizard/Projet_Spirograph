#ifndef MOVINGPOINT_H
#define MOVINGPOINT_H

#include "Point.h"

class MovingPoint
{
    public:
        MovingPoint();
        MovingPoint(const MovingPoint& copyPoint);
        MovingPoint(Point* origin0, const Point& coord0);
        ~MovingPoint();*



    private:
        Point* origin;
        Point coord;
};

#endif // MOVINGPOINT_H
