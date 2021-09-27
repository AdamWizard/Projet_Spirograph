#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(double x, double y);
        Point(const Point& pointCopie);

        double getX() const;
        double getY() const;

        void setX(double newX);
        void setY(double newX);

        double distanceFromPoint(Point point2);

    private:
        double x;
        double y;
};

#endif // POINT_H
