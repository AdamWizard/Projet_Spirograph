#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(float r, float theta);
        Point(const Point& copyPoint);

        float getR() const;
        float getT() const;

        void setR(float newX);
        void setT(float newX);

        double distanceFromPoint(Point point2);

    private:
        float r;
        float theta;
};

#endif // POINT_H
