#include "../include/MovingPoint.h"

class MovingPoint
{
    public:
        MovingPoint()
        {
            origin = new Point();
            coord.setR(0); coord.setT(0);
        }

        MovingPoint(const MovingPoint& copyPoint)
        {
            origin = copyPoint.origin;
            coord.setR(copyPoint.getRho());
        }

        MovingPoint(Point* origin0, const Point& coord0)
        {
            origin = origin0;
            coord.setRho(coord0.getRho());
            coord.setTheta(coord0.setTheta());s
        }

        ~MovingPoint()
        {
            delete origin;
            origin = nullptr;
        }
}
