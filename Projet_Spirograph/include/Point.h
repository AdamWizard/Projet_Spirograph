#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(float rho0, float theta0);
        Point(const Point& copyPoint);

        float getRho() const;
        float getTheta() const;

        void setRho(float newRho);
        void setTheta(float newTheta);

        double distanceFromPoint(Point point2);

    private:
        float rho;
        float theta;
};

#endif // POINT_H
