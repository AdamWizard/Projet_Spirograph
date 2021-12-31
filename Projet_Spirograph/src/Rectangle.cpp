#include "Rectangle.h"

Rectangle::Rectangle(int aX,int aY,int bX,int bY)
{
        this->aX=aX;
        this->aY=aY;

        this->bX=bX;
        this->bY=bY;
}

Rectangle::~Rectangle()
{

}

float Rectangle::getArea(){
    return (bX-aX)*(bY-aY);
}

float Rectangle::getPerimeter(){
    return 2*(bX-aX) +2*(bY-aY) ;
}
