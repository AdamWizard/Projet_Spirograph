#include "../include/Spirograph.h"
#include <iostream>
using namespace std;

Spirograph::Spirograph(int dimX, int dimY)
{
    //discs
    std::cout << "How many discs do you want ? (enter a positive integer)\n";
    do
        std::cin >> nbDiscs;
    while(nbDiscs<=0);

    listDisc = new Disc*[nbDiscs];

    for(int i = 0; i < nbDiscs; i++)
    {
        //float angSpeed = M_PI/120;
        float radius = 1;
        cout << "What is the radius of disc n"<< i+1 <<" ? (enter  a positive integer)\n";
        do
            cin >> radius;
        while(radius<=0);
        if (i==0)
        {
            Disc discTest(radius, int(dimX/2), int(dimY/2));
            listDisc[i] = &discTest;
        }

        else
        {
            Disc discTest(radius, listDisc[i-1]->getX()+radius+listDisc[i-1]->getRadius(),
                                  listDisc[i-1]->getY());
            listDisc[i] = &discTest;
        }

    }
    //pencils
    int nbPencils;
    cout<<"How many pencils do you want to put in the last disc? (enter a positive integer)\n";
    do
        cin>>nbPencils;
    while(nbPencils<0);

    for(int i=0;i<nbPencils;i++){
        float distance;
        cout<<"what's the distance between pencil n"<<i+1<<" and the center of disc n"<<nbDiscs<<" (enter a positive value)"<<endl;
        do
            cin>>distance;
        while (distance<0);

        Pencil* newPencil = new Pencil(sf::Color::Red,distance);
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

int Spirograph::getNbDiscs()
{
    return nbDiscs;
}

Disc* Spirograph::getDisc(int i)
{
    if(i >= 0 && i < nbDiscs)
        return listDisc[i];
    else
        return nullptr;
}

void Spirograph::update()
{
    for (int i=1;i<nbDiscs;i++){

        float R1 = listDisc[i-1]->getRadius();
        float R2 = listDisc[i]->getRadius();
        float diffX = listDisc[i]->getX()-listDisc[i-1]->getX();
        float diffY = listDisc[i]->getY()-listDisc[i-1]->getY();

        listDisc[i]->setPosition(listDisc[i-1]->getX() + (R1+R2) * ((R1+R2)/diffX),
                                 listDisc[i-1]->getY() + (R1+R2) * (diffY/diffX));

        for(int j=0;j<listDisc[i]->getNbPencils();j++){

            Pencil* currentPencil = listDisc[i]->getPencil(j);
            float rho = currentPencil->getRho();

            currentPencil->setPosition(listDisc[i]->getX() + (rho) * ((rho)/diffX),
                                       listDisc[i]->getY() + (rho) * (diffY/diffX));
            }
    }
}
