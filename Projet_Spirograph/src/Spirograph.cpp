#include "../headers/Spirograph.h"
#include <assert.h>
#include <vector>
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

Spirograph::Spirograph(string filepath)
{
    float maxPencilDistance = 0;
    int dimX; int dimY;
    ifstream myFile(filepath);
    string line;
    int lineNumber = 0;
    if (myFile.is_open())
    {
        while(getline(myFile, line))
        {
            vector<string> result = Parser::explode(line, ' ');
            if (lineNumber == 0) // Window size
            {
                Parser::M_Assert(result[0] == "Window_size", "Text file corrupted on line 1, should start by Window_size");

                // Check window length
                int res = stoi(result[1]);
                Parser::M_Assert(res > 0, "Window length should not be null");
                dimX = res;

                // Check window height
                res = stoi(result[2]);
                Parser::M_Assert(res > 0, "Window height should not be null");
                dimY = res;
            }
            if (lineNumber == 1) // Number of discs
            {
                Parser::M_Assert(result[0] == "Number_of_discs", "Text file corrupted on line 2, should start by Number_of_discs");

                int res = stoi(result[1]);
                Parser::M_Assert(res >= 2, "Number of discs should be >= 2");
                nbDiscs = res;
                listDisc = new Disc*[nbDiscs];
            }

            if (lineNumber >= 2 && lineNumber <= nbDiscs+1) // Discs radius
            {
                Parser::M_Assert(result[0] == "Disc", "Text file corrupted on line " + std::to_string(lineNumber+1) + ", should start by Disc");
                float res = stof(result[1]);
                Parser::M_Assert(res > 0, "Radius should be strictly positive");
                float radius = res;
                Parser::M_Assert(result[2][0] == 'e'|| result[2][0] == 'i', "You should write e or i (external or internal rotation)");
                char rotaChar = result[2][0];
                Parser::M_Assert((result[3][0]== 'c'||result[3][0] == 't'), "You should write c or t (clockwise or trigonometric rotation");
                char sensChar = result[3][0];
                Disc* currentDisc;

                int rotation = (rotaChar=='e' ? 1 : -1);

                int direction = (sensChar=='c' ? 1 : -1);

                int i = lineNumber - 2;
                switch(i) // The 1st two discs are initialized differently so we need a switch
                {
                    case 0:
                        currentDisc = new Disc(radius, float(dimX/2), float(dimY/2), 0, 1);
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
                                               direction*abs(getDisc(i-1)->getAngSpeed())*(getDisc(i-1)->getRadius()/radius),
                                               rotation);

                        listDisc[i] = currentDisc;
                }
            }
            if (lineNumber == nbDiscs+2) // Number of pencils
            {
                Parser::M_Assert(result[0] == "Number_of_pencils", "Text file corrupted on line " + to_string(lineNumber+1) + ", should start by Number_of_pencils");

                int res = stoi(result[1]);
                Parser::M_Assert(res >= 1, "Number of pencils should be >= 1");
                int nbPencils = res;
            }
            if (lineNumber >= nbDiscs+3)
            {
                Parser::M_Assert(result[0] == "Pencil", "Text file corrupted on line " + to_string(lineNumber+1) + ", should start by Pencil");
                float res = stof(result[1]);
                Parser::M_Assert(res >= 0, "Distance between pencil and disc should be positive");
                float distance = res;

                if (distance > maxPencilDistance)
                    maxPencilDistance = distance;

                sf::Color tabColor[3] = {sf::Color::Red, sf::Color::Green,sf::Color::Blue}; // To improve
                Pencil* newPencil = new Pencil(tabColor[1%3],distance); // TODO ask the color of pencils to the user
                listDisc[nbDiscs-1]->addPencil(newPencil);
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
        getDisc(i)->setPosition(getDisc(i-1)->getX() + (R1+getDisc(i)->getRotation()*R2) * cos(theta),
                                 getDisc(i-1)->getY() + (R1+getDisc(i)->getRotation()*R2) * sin(theta));

        for(int j = 0; j < getDisc(i)->getNbPencils(); j++)
        {
            Pencil* currentPencil = getDisc(i)->getPencil(j);
            float rho = currentPencil->getRho();
            float phi = currentPencil->getPhi();

            // Formulas explained in the README

            float penAngSpeed = (R1/R2)*getDisc(i)->getAngSpeed();

            phi += penAngSpeed;
            currentPencil->setPhi(phi);

            currentPencil->setPosition(getDisc(i)->getX() + rho * cos(theta + phi),
                                       getDisc(i)->getY() + rho * sin(theta + phi));
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
