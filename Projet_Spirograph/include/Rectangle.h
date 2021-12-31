#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(int aX,int aY,int cX,int cY);
        virtual ~Rectangle();
        float getArea();
        float getPerimeter();

    private:
        int aX;
        int aY;

        int bX;
        int bY;
};

#endif // RECTANGLE_H
