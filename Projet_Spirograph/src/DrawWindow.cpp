#include <iostream>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../headers/Spirograph.h"
#include "../headers/Parser.h"
#include "../headers/DrawWindow.h"

using namespace std;

DrawWindow::DrawWindow()
{
    winX = 1440; winY = 960;

    // We create a pseudo 3D array to store the RGB components of each pixel of the window
    // winX*winY pixels with each 4 components : red, green, blue and alpha (opacity)
    // This pixel array will be used to create a textured sprite that will be our canvas for the curves
    pixels = new sf::Uint8[winX*winY*4];

    pixelsToColor(0);
    string filepath = "resources/init.txt";
    spiro = new Spirograph(filepath);
}

DrawWindow::~DrawWindow()
{
    delete pixels;
    pixels = nullptr;

    delete spiro;
    spiro = nullptr;
}

void DrawWindow::mainWindow()
{
    //============== RENDERING WINDOW INITIALIZATION ==========================
    sf::RenderWindow window(sf::VideoMode(winX, winY), "Spirograph",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;

    sf::View view3b;
    view3b.reset(sf::FloatRect(0.f, 0.f, 960.f, 960.f));

    /*cout << "List of commands  : " << endl;
    cout << "   - ESC : Close the window" << endl,
    cout << "   - Space : Turn on/off the circles" << endl;
    cout << "   - P : Take a screenshot" << endl;
    cout << "   - S : Save the Spirograph presets" << endl;*/

	sf::Texture texture;
	texture.create(winX, winY);
	sf::Sprite sprite(texture);

    bool drawDiscs = false; // This boolean is linked with a key event to hide/show the white discs

    float framerate = 0;
    window.setFramerateLimit(framerate);
    //window.setVerticalSyncEnabled(true);
    // ============================== MAIN LOOP =================================
    while(window.isOpen()){
        // Check the key events
        while(window.pollEvent(ev)){
            switch(ev.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::D) // Double view
                    {
                        sf::View view3bSave=view3b; // i save a copy of the main view)
                        //   player 1 (left side of the screen)
                        view3b.setViewport(sf::FloatRect(0.f, 0.f, 0.22f, 1.f));
                        window.setView(view3b);
                        // player 2 (right side of the screen)
                        view3bSave.setViewport(sf::FloatRect(0.22f, 0.f, 0.78f, 1.f));
                        window.setView(view3bSave);
                    }
                    if (ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    if (ev.key.code == sf::Keyboard::Space)
                        drawDiscs = !drawDiscs;
                    if (ev.key.code == sf::Keyboard::P)
                    {
                        string screenshotName = getScreenFilename();
                        sf::Texture screenTexture;
                        screenTexture.create(winX, winY);
                        screenTexture.update(window);
                        if (screenTexture.copyToImage().saveToFile(screenshotName))
                        {
                            cout << "Screenshot saved to " << screenshotName << endl;
                        }
                    }
                    break;
            }
        }

        // Updating window
        window.clear();

        // Updating Spirograph i.e calculate the next position of the discs and pencils
        spiro->update();

        // Draw the curve before the white discs, because the sprite "wipes" the screen
        window.draw(sprite);

        for (int i = 0; i < spiro->getNbDiscs(); i++)
        {
            // Check the boolean and then draw the discs
            if(drawDiscs)
            {
                window.draw(*(spiro->getDisc(i)->getCircle()));
            }
            // =============== DRAW PENCILS/CURVES =======================
            for(int j = 0; j < spiro->getDisc(i)->getNbPencils(); j++)
            {
                Pencil* currentPencil = spiro->getDisc(i)->getPencil(j);

                int tempx = int(currentPencil->getX());
                int tempy = int(currentPencil->getY());
                int phi = currentPencil->getPhi();
                Parser::M_Assert(4*(tempy*winX+tempx) < winX*winY*4, "Drawing out of range");
                if (tempy*winX+tempx < winX*winY)
                {
                    updatePixels(i, tempx, tempy, phi);
                }
                window.draw(*(currentPencil->getCircle()));
            }
        }
        // Actualize the texture (thus the sprite/canvas) with the new pixel array
        texture.update(pixels);

		//end drawing
        window.display(); // The window is done drawing, we can now display it
    }
}

void DrawWindow::updatePixels(int i, int tempx, int tempy, int phi)
{
    // There are 2 methods to color the curves :
    // 1st one update the color from phi (the angle) and gives a gradient of colors
    // 2nd one use the Pencil color to draw the curve, useful when you have to distinguish the curves from several pencils
    // For each pencil of the disc, it loops between red, green and blue

    if (spiro->getDisc(i)->getNbPencils() == 1)
    {
        pixels[4*(tempy*winX+tempx)] = 100+2*int(cos(phi)*50);
        pixels[4*(tempy*winX+tempx)+1] = 100-2*int(sin(phi)*50);
        pixels[4*(tempy*winX+tempx)+2] = 100;
    }
    else
    {
        /*bool red = currentPencil->getColor() == sf::Color::Red;
        bool green = currentPencil->getColor() == sf::Color::Green;
        bool blue = currentPencil->getColor() == sf::Color::Blue;

        pixels[4*(tempy*winX+tempx)] = int(red)*255;
        pixels[4*(tempy*winX+tempx)+1] = int(green)*255;
        pixels[4*(tempy*winX+tempx)+2] = int(blue)*255;*/
    }
}

void DrawWindow::pixelsToColor(int color)
{
    Parser::M_Assert(color >= 0 && color < 256, "Error, color should be between 0 and 255");
    //Initialize all pixels to color
	for (int i = 0; i < winX*winY*4; i+=4){
		pixels[i] = color;
		pixels[i+1] = color;
		pixels[i+2] = color;
		pixels[i+3] = 255;
	}
}

string DrawWindow::getScreenFilename()
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    string day = to_string(local_time->tm_mday);
    string mon = to_string(1+local_time->tm_mon);
    string year = to_string(1900+local_time->tm_year);
    string hour = to_string(local_time->tm_hour);
    string minute = to_string(1+local_time->tm_min);
    string sec = to_string(1+local_time->tm_sec);

    string screenshotName = "screenshots/" + day + "-" + mon + "-" + year + "_" +
                                hour + "-" + minute + "-" + sec + ".jpg";

    return screenshotName;
}
