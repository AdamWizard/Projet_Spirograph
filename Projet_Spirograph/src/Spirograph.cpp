#include "../headers/Spirograph.h"
#include <assert.h>
#include <vector>
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

Spirograph::Spirograph(int dimX, int dimY, Shape* centralShape, Disc disc)
{
    speedFactor = 1.0;
    // ======================== DISCS =============================================
    float maxPencilDistance = 0;
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
                                          getDisc(i-1)->getY(), getDisc(i-1)->getAngSpeed()+rotation*abs(getDisc(i-1)->getAngSpeed())*(getDisc(i-1)->getRadius()/radius));

                    listDisc[i] = discTest;
            }
        }
        // ======================== PENCILS ===================================================
        int nbPencils;
        cout<<"How many pencils do you want to put on the last disc? (enter a positive integer)\n";
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

            if(distance > maxPencilDistance) // getting the furthest pencil from the center to calculate the summ of radiuses
                maxPencilDistance = distance;

            // TODO: implement color choice from user
            sf::Color tabColor[3] = {sf::Color::Red, sf::Color::Green,sf::Color::Blue}; // To improve
            Pencil* newPencil = new Pencil(tabColor[i%3],distance);

            listDisc[nbDiscs-1]->addPencil(newPencil);
        }
        // Checking if any pencil will end up outside the window
        if(!checkLength(maxPencilDistance, dimX))
            cout << "Warning ! You're trying to draw out of the window, please change your data." << endl;
    }
    while(!checkLength(maxPencilDistance, dimX));
}

Spirograph::Spirograph(int dimX, int dimY)
{
    speedFactor = 1.0;
    // ======================== DISCS =============================================
    float maxPencilDistance = 0;
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
                                          getDisc(i-1)->getY(), getDisc(i-1)->getAngSpeed()+rotation*abs(getDisc(i-1)->getAngSpeed())*(getDisc(i-1)->getRadius()/radius));

                    listDisc[i] = discTest;
            }
        }
        // ======================== PENCILS ===================================================
        int nbPencils;
        cout<<"How many pencils do you want to put on the last disc? (enter a positive integer)\n";
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

            if(distance > maxPencilDistance) // getting the furthest pencil from the center to calculate the summ of radiuses
                maxPencilDistance = distance;

            // TODO: implement color choice from user
            sf::Color tabColor[3] = {sf::Color::Red, sf::Color::Green,sf::Color::Blue}; // To improve
            Pencil* newPencil = new Pencil(tabColor[i%3],distance);

            listDisc[nbDiscs-1]->addPencil(newPencil);
        }
        // Checking if any pencil will end up outside the window
        if(!checkLength(maxPencilDistance, dimX))
            cout << "Warning ! You're trying to draw out of the window, please change your data." << endl;
    }
    while(!checkLength(maxPencilDistance, dimX));
}

Spirograph::Spirograph(string filepath)
{
    speedFactor = 1.0;
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
                int res = stoi(result[1]);
                //Parser::M_Assert(res != 0, "Radius should not be null");
                float radius = res;

                Disc* currentDisc;

                int rotation;
                if(radius < 0)
                    rotation = -1;
                else
                    rotation = 1;

                radius = abs(radius); // This way the discs will always be outside of the previous disc

                int i = lineNumber - 2;
                switch(lineNumber) // The 1st two discs are initialized differently so we need a switch
                {
                    case 2:
                        currentDisc = new Disc(radius, int(dimX/2), int(dimY/2), 0);
                        // The center of the Spirograph is now placed at the center of the window
                        listDisc[0] = currentDisc;
                        break;

                    case 3:
                        currentDisc = new Disc(radius, getDisc(0)->getX()+getDisc(0)->getRadius()+radius, getDisc(0)->getY(), rotation*M_PI/2000);
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
                                               getDisc(i-1)->getX()+radius+getDisc(i-1)->getRadius(),
                                               getDisc(i-1)->getY(),
                                               getDisc(i-1)->getAngSpeed()+rotation*abs(getDisc(i-1)->getAngSpeed())*(getDisc(i-1)->getRadius()/radius));

                        listDisc[lineNumber-2] = currentDisc;
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
        getDisc(i)->rollAround(getDisc(i-1),speedFactor);
    }
}

bool Spirograph::checkLength(int maxPencilDistance, int dimX)
{
    int maxDrawableX = dimX/2 + listDisc[0]->getRadius();
    for(int i = 1; i < nbDiscs-1; i++)
    {
        maxDrawableX += listDisc[i]->getRadius()*2;
    }
    maxDrawableX += listDisc[nbDiscs-1]->getRadius() + maxPencilDistance;

    return (maxDrawableX <= dimX);
}
