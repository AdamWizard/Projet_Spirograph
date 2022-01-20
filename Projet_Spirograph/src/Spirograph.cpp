#include "../headers/Spirograph.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

Spirograph::Spirograph(string filepath)
{
    speedFactor = 1.0;
    double maxPencilDistance = 0;
    int dimX = 960; int dimY = 960;
    ifstream myFile(filepath);
    string line;
    int lineNumber = 0;
    if (myFile.is_open())
    {
        while(getline(myFile, line))
        {
            if(line.empty())
                continue;
            vector<string> result = Parser::explode(line, ' ');
            if (lineNumber == 0) // Number of discs
            {
                Parser::M_Assert(result[0] == "Number_of_discs", "Text file corrupted on line 1, should start by Number_of_discs");

                int res = stoi(result[1]);
                Parser::M_Assert(res >= 2, "Number of discs should be >= 2");
                nbDiscs = res;

                listDisc = new Disc*[nbDiscs];
            }
            if (lineNumber >= 1 && lineNumber <= getNbDiscs()) // Discs radius
            {
                Parser::M_Assert(result[0] == "Disc", "Text file corrupted on line " + std::to_string(lineNumber+1) + ", should start by Disc");
                double res = stof(result[1]);
                Parser::M_Assert(res > 0, "Radius should be strictly positive");
                double radius = res;
                Parser::M_Assert(result[2][0] == 'e'|| result[2][0] == 'i', "You should write e or i (external or internal rotation)");
                char rotaChar = result[2][0];
                Parser::M_Assert((result[3][0]== 'c'||result[3][0] == 't'), "You should write c or t (clockwise or trigonometric rotation");
                char sensChar = result[3][0];
                Disc* currentDisc;

                int rotation = (rotaChar=='e' ? 1 : -1);

                int direction = (sensChar=='c' ? 1 : -1);

                int i = lineNumber - 1;
                switch(i) // The 1st two discs are initialized differently so we need a switch
                {
                    case 0:
                        currentDisc = new Disc(radius, double(dimX/2), double(dimY/2), 0, 1);
                        // The center of the Spirograph is now placed at the center of the window
                        listDisc[0] = currentDisc;
                        break;

                    case 1:
                        currentDisc = new Disc(radius,
                                               getDisc(0)->getX()+getDisc(0)->getRadius()+rotation*radius,
                                               getDisc(0)->getY(),
                                               direction*M_PI/2000,
                                               rotation);
                        listDisc[1] = currentDisc;
                        break;

                    default:
                        // The formula to set the coordinates of the center of each circle is
                        //      previousDiscX + previousDiscRadius + actualDiscRadius
                        // The Y stays the same so that at frame 0, each Disc is on the horizontal axis
                        // and the centers form an horizontal line
                        // Finally the formula for the angular speed is
                        //      previousDiscAngSpeed * (previousDiscRadius / actualDiscRadius)
                        currentDisc = new Disc(radius,
                                               getDisc(i-1)->getX()+rotation*radius+getDisc(i-1)->getRadius(),
                                               getDisc(i-1)->getY(),
                                               getDisc(i-1)->getAngSpeed()+direction*abs(getDisc(i-1)->getAngSpeed())*(getDisc(i-1)->getRadius()/radius),
                                               rotation);
                        listDisc[i] = currentDisc;
                }
            }
            if (lineNumber == getNbDiscs()+1) // Number of pencils
            {
                Parser::M_Assert(result[0] == "Number_of_pencils", "Text file corrupted on line " + to_string(lineNumber+1) + ", should start by Number_of_pencils");

                int res = stoi(result[1]);
                Parser::M_Assert(res >= 1, "Number of pencils should be >= 1");
            }
            if (lineNumber >= getNbDiscs()+2)
            {
                Parser::M_Assert(result[0] == "Pencil", "Text file corrupted on line " + to_string(lineNumber+1) + ", should start by Pencil");
                double res = stof(result[1]);
                Parser::M_Assert(res >= 0, "Distance between pencil and disc should be positive");
                double distance = res;

                if (distance > maxPencilDistance)
                    maxPencilDistance = distance;

                sf::Color tabColor[3] = {sf::Color::Red, sf::Color::Green,sf::Color::Blue}; // To improve
                Pencil* newPencil = new Pencil(tabColor[1%3],distance); // TODO ask the color of pencils to the user
                listDisc[getNbDiscs()-1]->addPencil(newPencil);
                Parser::M_Assert(checkLength(maxPencilDistance, dimX), "Your numbers are too big, you're drawing out of the window");
            }
            lineNumber++;
        }
        myFile.close();
    }
    else
        cout << "Reading of file failed ! Probably wrong format or filepath" << endl;
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

float Spirograph::getSpeedFactor()
{
    return speedFactor;
}

void Spirograph::setSpeedFactor(float newSpeedFactor)
{
    speedFactor = newSpeedFactor;
}

void Spirograph::update()
{
    for (int i = 1;i < nbDiscs; i++) // Start at 1 because the first Shape does not move
    {
        if(!checkReset())
        {
            if(getDisc(i)->getRotation()==1)
                getDisc(i)->rollAround(getDisc(i-1),speedFactor);
            else
                getDisc(i)->rollInside(getDisc(i-1),speedFactor);
        }
    }
}

bool Spirograph::checkLength(int maxPencilDistance, int dimX)
{
    int maxDrawableX = dimX/2 + listDisc[0]->getRadius();
    for(int i = 1; i < nbDiscs-1; i++)
    {
        if(listDisc[i]->getRotation()==1)
            maxDrawableX += listDisc[i]->getRadius()*2;
    }
    maxDrawableX += listDisc[nbDiscs-1]->getRadius() + maxPencilDistance;

    return (maxDrawableX <= dimX);
}

void Spirograph::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    for(int i=0;i<nbDiscs;i++){
        target.draw(*listDisc[i],states);
    }
}

bool Spirograph::checkReset()
{
    if (nbDiscs >= 3)
        return true;
    else
    {
        bool reset = true;
        for (int i = 1;i < nbDiscs; i++)
        {
            int n = 0; int m = 1;
            while (m != 0) // Compute the numbers of rotations required to make the full pattern
            {
                n++;
                m = fmod(n*getDisc(i-1)->getRadius(), getDisc(i)->getRadius()); // Modulo between each radius
            }
            if (abs(getDisc(i)->getTheta()) < 2*M_PI*n) // If a certain has not completed his full rotation, we don't reset
            {
                reset = false;
            }

            for(unsigned int j = 0; j < getDisc(i)->getNbPencils(); j++) // Same for Pencil
            {
                if(abs(getDisc(i)->getPencil(j)->getPhi()) < 2*M_PI*n)
                    reset = false;
            }
        }

        if (reset)
        {
            for (int i = 1;i < nbDiscs; i++)
            {
                getDisc(i)->setTheta(0);
                for(unsigned int j = 0; j < getDisc(i)->getNbPencils(); j++)
                    getDisc(i)->getPencil(j)->setPhi(0);
            }
            // No need to specify the other ones, since their position is computed from the 1st moving disc
            getDisc(1)->setPosition(getDisc(0)->getX()+getDisc(0)->getRadius()+getDisc(1)->getRotation()*getDisc(1)->getRadius(),
                                    getDisc(0)->getY());
        }
        return reset;
    }

}
