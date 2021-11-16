#include "../headers/Spirograph.h"
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

Spirograph::Spirograph(int dimX, int dimY)
{
    // ======================== DISCS =============================================
    float maxDrawableX;
    do
    {
        std::cout << "How many discs do you want ? (minimum 2)\n";
        do
            cin >> nbDiscs;
        while(nbDiscs < 2 );

        listDisc = new Disc*[nbDiscs];

        for(int i = 0; i < nbDiscs; i++)
        {
            float radius = 1;
            cout << "What is the radius of disc number "<< i+1 <<" ? (different from 0)\n" <<
                    "Entering a negative radius will result in a counter-clockwise rotation\n";
            do
                cin >> radius;
            while(radius == 0);

            Disc* discStatic = nullptr;
            Disc* discMoving = nullptr;
            int rotation = 0;
            if(radius < 0)
                rotation = -1;
            else
                rotation = 1;

            radius = abs(radius); // This way the discs will always be outside of the previous disc

            switch(i) // The 1st two discs are initialized differently so we need a switch
            {
                case 0:
                    discStatic = new Disc(radius, int(dimX/2), int(dimY/2), 0);
                    // The center of the Spirograph is now placed at the center of the window
                    listDisc[0] = discStatic;
                    break;

                case 1:
                    discMoving = new Disc(radius, getDisc(0)->getX()+getDisc(0)->getRadius()+radius, getDisc(0)->getY(), rotation*M_PI/2000);
                    listDisc[1] = discMoving;
                    break;

                default:
                    // The formula to set the coordinates of the center of each circle is
                    //      previousDiscX + previousDiscRadius + actualDiscRadius
                    // The Y stays the same so that at frame 0, each Disc is on the horizontal axis
                    // and the centers form an horizontal line
                    // Finally the formula for the angular speed is
                    //      previousDiscAngSpeed * (previousDiscRadius / actualDiscRadius)
                    Disc* discTest = new Disc(radius, getDisc(i-1)->getX()+radius+getDisc(i-1)->getRadius(),
                                          getDisc(i-1)->getY(), rotation*abs(getDisc(i-1)->getAngSpeed())*(getDisc(i-1)->getRadius()/radius));

                    listDisc[i] = discTest;
            }
        }
        // ======================== PENCILS ===================================================
        int nbPencils;
        cout<<"How many pencils do you want to put in the last disc? (enter a positive integer)\n";
        do
            cin >> nbPencils;
        while(nbPencils <= 0);

        float maxPencilDistance = 0;
        for(int i = 0; i< nbPencils ; i++){
            float distance;
            cout << "What's the distance between pencil number " << i + 1
                 << " and the center of disc number " << nbDiscs << " (enter a positive value)" << endl;
            do
                cin >> distance;
            while (distance < 0);

            if(distance > maxPencilDistance) // Avoir le crayon le plus éloigné pour le calcul de la somme des rayons
                maxPencilDistance = distance;

            // Choix des couleurs à implémenter
            sf::Color tabColor[3] = {sf::Color::Red, sf::Color::Green,sf::Color::Blue}; // To improve
            Pencil* newPencil = new Pencil(tabColor[i%3],distance);

            listDisc[nbDiscs-1]->addPencil(newPencil);
        }
        // Vérifier si on sort pas de la fenêtre
        maxDrawableX = dimX/2 + listDisc[0]->getRadius();
        for(int i = 1; i < nbDiscs-1; i++)
        {
            maxDrawableX += listDisc[i]->getRadius()*2;
        }
        maxDrawableX += listDisc[nbDiscs-1]->getRadius() + maxPencilDistance;
        if(maxDrawableX >= dimX)
            cout << "Warning ! You're trying to draw out of the window, please change your data." << endl;
    }
    while(maxDrawableX >= dimX);
}

Spirograph::~Spirograph()
{
    for(int i = 0; i < nbDiscs; i++)
    {
        delete listDisc[i];
    }
    delete listDisc; listDisc = nullptr;
}

int Spirograph::getNbDiscs() const
{
    return nbDiscs;
}

Disc* Spirograph::getDisc(int i)
{
    if(i >= 0 && i < nbDiscs) // TO avoid read memory problems
        return listDisc[i];
    else
        return nullptr;
}

void Spirograph::update()
{
    for (int i = 1;i < nbDiscs; i++) // Start at 1 because the first Disc doesn't move
    {
        float R1 = getDisc(i-1)->getRadius();
        float R2 = getDisc(i)->getRadius();
        float theta = getDisc(i)->getTheta();

        // Slowly update theta
        if(getDisc(i)->getAngSpeed()*getDisc(i-1)->getAngSpeed() < 0)
            theta += getDisc(i)->getAngSpeed()-getDisc(i-1)->getAngSpeed();
        else
            theta += getDisc(i)->getAngSpeed()+getDisc(i-1)->getAngSpeed();

        getDisc(i)->setTheta(theta);

        // Formulas explained in the README
        getDisc(i)->setPosition(getDisc(i-1)->getX() + (R1+R2) * cos(theta),
                                 getDisc(i-1)->getY() + (R1+R2) * sin(theta));

        for(int j = 0; j < getDisc(i)->getNbPencils(); j++)
        {
            Pencil* currentPencil = getDisc(i)->getPencil(j);
            float rho = currentPencil->getRho();
            float phi = currentPencil->getPhi();

            // Formulas explained in the README

            //float sumRadius =
            float penAngSpeed = (R1/R2)*getDisc(i)->getAngSpeed();

            phi += penAngSpeed;
            currentPencil->setPhi(phi);

            currentPencil->setPosition(getDisc(i)->getX() + rho * cos(theta + phi),
                                       getDisc(i)->getY() + rho * sin(theta + phi));
            }
    }
}
