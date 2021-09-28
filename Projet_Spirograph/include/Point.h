#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(float x, float y);
        Point(const Point& copyPoint);

        float getX() const;
        float getY() const;

        void setX(float newX);
        void setY(float newX);

        double distanceFromPoint(Point point2);

    private:
        float x;
        float y;
};

#endif // POINT_H
