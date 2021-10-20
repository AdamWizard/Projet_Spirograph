#include "../include/Spirograph.h"
#include <malloc.h>
#include <iostream>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

Spirograph::Spirograph()
{
    int nbDisc;
    std::cout << "How many discs do you want ? (enter a positive integer)\n";
    do
        std::cin >> nbDisc;
    while(nbDisc<=0);

    mPoints = (MovingPoint**)malloc(sizeof(MovingPoint*)*(nbDisc+1));

    mPoints[0] = new MovingPoint(nullptr, 0,0,0); //Point central immobile
    first = mPoints[0];

    for(int i = 1; i <= nbDisc; i++)
    {
        float angSpeed = M_PI/120; float radius = 0;
        std::cout << "What is the radius of disc number "<< i <<" ? (enter  a positive integer)\n";
        do
            std::cin >> radius;
        while(radius<=0);

        /*std::cout << "What is the angular speed of disc number "<< i <<" in radians/seconds ? (enter a positive integer)\n";
        do
            std::cin >> angSpeed;
        while(angSpeed<=0);*/

        mPoints[i] = new MovingPoint(mPoints[i-1], radius, 0, angSpeed);
    }
    nbPoints = nbDisc+1;
}

Spirograph::~Spirograph()
{
    while(*mPoints != nullptr)
    {
        delete *mPoints;
        mPoints++;
    }
    delete this->mPoints;

    delete first; delete last;
    first = nullptr, last = nullptr;
}

int Spirograph::getNbPoints()
{
    return nbPoints;
}

MovingPoint* Spirograph::getPoint(int i)
{
    if(i >= 0 && i < nbPoints)
        return mPoints[i];
    else
        return nullptr;
}

