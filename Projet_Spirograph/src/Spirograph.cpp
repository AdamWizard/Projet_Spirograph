#include "../include/Spirograph.h"
#include <malloc.h>
Spirograph::Spirograph()
{
    int nbDisc;
    cout << "How many discs do you want ? (enter a positive integer)" << endl;
    do
        cin >> nbDisc;
    while(nbDisc<=0);

    mPoints = (MovingPoint**)malloc(sizeof(MovingPoint*)*nbDisc);

    mPoints[0] = new MovingPoint(nullptr, 0,0,0); //Point central immobile
    first = mPoints[0];

    float angSpeed = 0; float radius = 0;
    for(int i = 1; i < nbDisc; i++)
    {
        cout << "What is the radius of the " << i << " th disc ? (enter  an integer > 0)" << endl;
        do
            cin >> radius;
        while(radius<=0);

        cout << "What is the angular speed of the " << i << " th disc in revolutions/min ? (enter  an integer > 0)" << endl;
        do
            cin >> angSpeed;
        while(angSpeed<=0);

        mPoints[i] = new MovingPoint(mPoints[i-1], radius, 0, angSpeed);
    }
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
