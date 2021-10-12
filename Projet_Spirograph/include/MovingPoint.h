#ifndef MOVINGPOINT_H
#define MOVINGPOINT_H

//#include "Point.h"

class MovingPoint
{
    public:
        MovingPoint();
        MovingPoint(const MovingPoint& copyPoint);
        MovingPoint(MovingPoint* origin0, float rho0, float theta0, float angSpeed0);
        ~MovingPoint();*

        float getRho() const;
        float getTheta() const;
        float getAngSpeed() const;

        void setRho(float newRho);
        void setTheta(float newTheta);
        void setAngSpeed(float newAngSpeed);

    private:
        Point* origin;
        float rho;
        float theta;
        float angSpeed;
};

#endif // MOVINGPOINT_H
