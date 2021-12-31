#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
    public:
        Rectangle(int aX,int aY,int bX,int bY,int cX,int cY,int dX,int dY);
        virtual ~Rectangle();

    private:
        int aX;
        int aY;
        int bX;
        int bY;
        int cX;
        int cY;
        int dX;
        int dY;
};

#endif // RECTANGLE_H
