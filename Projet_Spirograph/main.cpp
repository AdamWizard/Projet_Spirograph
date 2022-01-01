#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "headers/Spirograph.h"

#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

int main()
{
    //============== RENDERING WINDOW INITIALIZATION ==========================

    int winX = 960; int winY = 960;

    //creating a spirograph from a text file
    /*
    string filepath = "resources/init.txt";
    Spirograph spiro(filepath);
    */

    //creating a spirograph from user input

    Spirograph spiro(winX, winY);


    //creating spirograph from central Disc an Disc
    /*
    Spirograph spiro();
    */
    //instantiating window
    sf::RenderWindow window(sf::VideoMode(winX, winY), "Spirograph",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;

    // We create a pseudo 3D array to store the RGB components of each pixel of the window
    // winX*winY pixels with each 4 components : red, green, blue and alpha (opacity)
    // This pixel array will be used to create a textured sprite that will be our canvas for the curves
    sf::Uint8*	pixels = new sf::Uint8[winX*winY*4];

	sf::Texture texture;
	texture.create(winX, winY);
	sf::Sprite sprite(texture);

	//Initialize all pixels to black
	for (int i = 0; i < winX*winY*4; i+=4){
		pixels[i] = 0;
		pixels[i+1] = 0;
		pixels[i+2] = 0;
		pixels[i+3] = 255;
	}

    bool drawDiscs = false; // This boolean is linked with a key event to hide/show the white Discs

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
                    if (ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    if (ev.key.code == sf::Keyboard::Space)
                        drawDiscs = !drawDiscs;
                    if (ev.key.code == sf::Keyboard::Left)
                        spiro.setSpeedFactor(spiro.getSpeedFactor()-0.10);
                        if (spiro.getSpeedFactor()<0)
                            spiro.setSpeedFactor(0);
                    if (ev.key.code == sf::Keyboard::Right)
                        spiro.setSpeedFactor(spiro.getSpeedFactor()+0.10);

                    break;
            }
        }

        // Updating window
        window.clear();

        // Updating Spirograph i.e calculate the next position of the Discs and pencils
        spiro.update();

        // Draw the curve before the white Discs, because the sprite "wipes" the screen
        window.draw(sprite);

        for (int i = 0; i < spiro.getNbDiscs(); i++)
        {
            // Check the boolean and then draw the spirograph structure
            if(drawDiscs)
            {
                /*
                window.draw(*(spiro.getDisc(i)->getCircle()));
                for(int j = 0; j < spiro.getDisc(i)->getNbPencils(); j++)
                {
                    Pencil* currentPencil = spiro.getDisc(i)->getPencil(j);
                    window.draw(*(currentPencil->getCircle()));
                }*/
                window.draw(spiro);
            }
            // =============== DRAW PENCILS/CURVES =======================
            for(int j = 0; j < spiro.getDisc(i)->getNbPencils(); j++)
                {
                Pencil* currentPencil = spiro.getDisc(i)->getPencil(j);

                int tempx = int(currentPencil->getX());
                int tempy = int(currentPencil->getY());
                float diffX = tempx-spiro.getDisc(i)->getX();
                int phi = currentPencil->getPhi();

                if (4*(tempy*winX+tempx) < winX*winY*4)
                {
                    // There are 2 methods to color the curves :
                    // 1st one updates the color from phi (the angle between the pencil, center of its Disc and the x axis) to create a gradient of colors
                    // 2nd one uses the Pencil color to draw the curve, useful when you have to distinguish the curves from several pencils
                    // For each pencil of the Disc, it loops between red, green and blue

                    /*
                    pixels[4*(tempy*winX+tempx)] = 200+2*int(cos(phi)*50);
                    pixels[4*(tempy*winX+tempx)+1] = 100+int(sin(phi)*50);
                    pixels[4*(tempy*winX+tempx)+2] = 50;
                    */

                    if (spiro.getDisc(i)->getNbPencils() == 1)
                    {
                        pixels[4*(tempy*winX+tempx)] = 100+2*int(cos(phi)*50);
                        pixels[4*(tempy*winX+tempx)+1] = 100-2*int(sin(phi)*50);
                        pixels[4*(tempy*winX+tempx)+2] = 100;
                    }
                    else
                    {
                        bool red = currentPencil->getColor() == sf::Color::Red;
                        bool green = currentPencil->getColor() == sf::Color::Green;
                        bool blue = currentPencil->getColor() == sf::Color::Blue;

                        pixels[4*(tempy*winX+tempx)] = int(red)*255;
                        pixels[4*(tempy*winX+tempx)+1] = int(green)*255;
                        pixels[4*(tempy*winX+tempx)+2] = int(blue)*255;
                    }
                }
            }
        }
        // Actualize the texture (thus the sprite/canvas) with the new pixel array
        texture.update(pixels);

		//end drawing
        window.display(); // The window is done drawing, we can now display it
    }

    delete pixels; pixels = nullptr;
    return 0;
}
