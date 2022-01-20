#include <iostream>
#include "SFML/Graphics.hpp"
#include "headers/Spirograph.h"

int main()
{
    int winX = 960; int winY = 960;
	sf::RenderWindow window(sf::VideoMode(winX, winY), "Welcome to the fabulous world of Spirographs");
    bool drawDiscs = false; // This boolean is linked with a key event to hide/show the white Discs
    float framerate = 0;
    window.setFramerateLimit(framerate);

    string filepath = "resources/init.txt";
    Spirograph* spiro = new Spirograph(filepath);

    sf::Texture texture;
    texture.create(winX, winY);
    sf::Sprite sprite(texture);

    sf::Uint8* pixels = new sf::Uint8[winX*winY*4];
    for (int i = 0; i < winX*winY*4; i+=4){
		pixels[i] = 0;
		pixels[i+1] = 0;
		pixels[i+2] = 0;
		pixels[i+3] = 255;
	}

	while(window.isOpen())
	{
		sf::Event ev;

		while (window.pollEvent(ev))
		{
			switch (ev.type)
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
                    spiro->setSpeedFactor(spiro->getSpeedFactor()-0.10);
                    if (spiro->getSpeedFactor()<0)
                        spiro->setSpeedFactor(0);
                if (ev.key.code == sf::Keyboard::Right)
                    spiro->setSpeedFactor(spiro->getSpeedFactor()+0.10);

                break;
			}
		}

		window.clear();

		// Updating Spirograph i.e calculate the next position of the Discs and pencils
        spiro->update();

        // Draw the curve before the white Discs, because the sprite "wipes" the screen
        window.draw(sprite);

        // Check the boolean and then draw the spirograph structure (discs and pencil heads)
        if(drawDiscs)
        {
            window.draw(*spiro);
        }

        for (int i = 0; i < spiro->getNbDiscs(); i++)
        {
            // =============== DRAW PENCILS/CURVES =======================
            for(int j = 0; j < spiro->getDisc(i)->getNbPencils(); j++)
            {
                Pencil* currentPencil = spiro->getDisc(i)->getPencil(j);

                int tempx = int(currentPencil->getX());
                int tempy = int(currentPencil->getY());
                float diffX = tempx-spiro->getDisc(i)->getX();
                int phi = currentPencil->getPhi();

                if (4*(tempy*winX+tempx) < winX*winY*4)
                {
                    // There are 2 methods to color the curves :
                    // 1st one updates the color from phi (the angle between the pencil, center of its Disc and the x axis) to create a gradient of colors
                    // 2nd one uses the Pencil color to draw the curve, useful when you have to distinguish the curves from several pencils
                    // For each pencil of the Disc, it loops between red, green and blue

                    if (spiro->getDisc(i)->getNbPencils() == 1)
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
        texture.update(pixels);
		window.display();
    }
}
