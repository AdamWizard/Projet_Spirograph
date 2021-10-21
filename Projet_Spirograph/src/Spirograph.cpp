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

    std::cout << "How many discs do you want ? (enter a positive integer)\n";
    do
        cin >> nbDiscs;
    while(nbDiscs <= 0 );

    listDisc = new Disc*[nbDiscs];

    for(int i = 0; i < nbDiscs; i++)
    {
        float radius = 1;
        cout << "What is the radius of disc number "<< i+1 <<" ? (enter  a positive integer)\n";
        do
            cin >> radius;
        while(radius <= 0);

        if (i == 0) // The first disc doesn't move and thus must me initialized differently
        {
            Disc* discTest = new Disc(radius, int(dimX/2), int(dimY/2), M_PI/500);
            // The center of the Spirograph is now placed at the center of the window

            listDisc[i] = discTest;
        }
        else
        {
            // The formula to set the coordinates of the center of each circle is
            //      previousDiscX + previousDiscRadius + actualDiscRadius
            // The Y stays the same so that at frame 0, each Disc is on the horizontal axis
            // and the centers form an horizontal line
            // Finally the formula for the angular speed is
            // ALED
            Disc* discTest = new Disc(radius, getDisc(i-1)->getX()+radius+getDisc(i-1)->getRadius(),
                                  getDisc(i-1)->getY(), getDisc(i-1)->getAngSpeed()*(getDisc(i-1)->getRadius()/radius));
            listDisc[i] = discTest;
        }

    }
    // ======================== PENCILS ===================================================
    int nbPencils;
    cout<<"How many pencils do you want to put in the last disc? (enter a positive integer)\n";
    do
        cin >> nbPencils;
    while(nbPencils <= 0);

    for(int i = 0; i< nbPencils ; i++){
        float distance;
        cout << "What's the distance between pencil number " << i + 1
             << " and the center of disc number " << nbDiscs << " (enter a positive value)" << endl;
        do
            cin >> distance;
        while (distance < 0);

        sf::Color tabColor[3] = {sf::Color::Red, sf::Color::Green,sf::Color::Blue}; // To improve
        Pencil* newPencil = new Pencil(tabColor[i%3],distance);
        listDisc[nbDiscs-1]->addPencil(newPencil);
    }
    speed = 1;
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

        theta += getDisc(i)->getAngSpeed(); // Slowly update theta
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
            float penAngSpeed = R1/R2*getDisc(i)->getAngSpeed();

            phi += penAngSpeed;
            currentPencil->setPhi(phi);

            // Formulas explained in the README
            currentPencil->setPosition(getDisc(i)->getX() + rho * cos(theta + phi),
                                       getDisc(i)->getY() + rho * sin(theta + phi));
            }
    }
}
