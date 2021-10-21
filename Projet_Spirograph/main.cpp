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

    int winX = 640; int winY = 640;
    Spirograph spiro(winX, winY);
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

    bool drawDiscs = true; // This boolean is linked with a key event to hide/show the white discs

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
                    break;
            }
        }

        // Updating window
        window.clear();

        // Updating Spirograph i.e calculate the next position of the discs and pencils
        spiro.update();

        // Draw the curve before the white discs, because the sprite "wipes" the screen
        window.draw(sprite);

        for (int i = 0; i < spiro.getNbDiscs(); i++)
        {
            // Check the boolean and then draw the discs
            if(drawDiscs)
            {
                window.draw(*(spiro.getDisc(i)->getCircle()));
            }
            // =============== DRAW PENCILS/CURVES =======================
            for(int j = 0; j < spiro.getDisc(i)->getNbPencils(); j++)
                {
                Pencil* currentPencil = spiro.getDisc(i)->getPencil(j);

                int tempx = int(currentPencil->getX());
                int tempy = int(currentPencil->getY());
                float diffX = tempx-spiro.getDisc(i)->getX();
                int phi = acos(diffX/currentPencil->getRho());

                if (4*(tempy*winX+tempx) < winX*winY*4)
                {
                    // There are 2 methods to color the curves :
                    // 1st one update the color from phi (the angle) and gives a gradient of colors
                    // 2nd one use the Pencil color to draw the curve, useful when you have to distinguish the curves from several pencils
                    // For each pencil of the disc, it loops between red, green and blue

                    if (spiro.getDisc(i)->getNbPencils() == 1)
                    {
                        pixels[4*(tempy*winX+tempx)] = 100-2*int(cos(phi)*50);
                        pixels[4*(tempy*winX+tempx)+1] = 100;
                        pixels[4*(tempy*winX+tempx)+2] = 100+2*int(sin(phi)*50);
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
                window.draw(*(currentPencil->getCircle()));
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
