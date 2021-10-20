#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../include/Spirograph.h"

#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

int main()
{
    //initializing rendering window

    int winX = 640; int winY = 640;
    Spirograph spiro(winX, winY);
    sf::RenderWindow window(sf::VideoMode(winX, winY), "Spirograph",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;


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

    //float angspeed = M_PI/200;
    bool drawDiscs = true;

    //game loop
    while(window.isOpen()){
        //on regarde les evenements
        while(window.pollEvent(ev)){
            switch(ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code==sf::Keyboard::Escape){
                    window.close();
                }
                if (ev.key.code==sf::Keyboard::Space){
                    drawDiscs = !drawDiscs;
                }
                break;
            }
        }

        //updating window
        window.clear();

        //updating spiro
        spiro.update();
        //end updating spiro

        //drawing
        window.draw(sprite);

        for (int i=0;i<spiro.getNbDiscs();i++){
                //drawing discs
                if(drawDiscs)
                {
                    //sf::CircleShape currentCircle = );
                    window.draw(*(spiro.getDisc(i)->getCircle()));
                }
                //drawing pencil lines
                for(int j=0;j<spiro.getDisc(i)->getNbPencils();j++){
                    Pencil* currentPencil = spiro.getDisc(i)->getPencil(j);

                    int tempx   = int(currentPencil->getX());
                    int tempy   = int(currentPencil->getY());
                    float diffX = tempx-spiro.getDisc(i)->getX();
                    int phi     = acos(diffX/currentPencil->getRho());

                    if (4*(tempy*winX+tempx) < winX*winY*4){
                        pixels[4*(tempy*winX+tempx)] = 100-2*int(cos(phi)*50);
                        pixels[4*(tempy*winX+tempx)+1] = 100;
                        pixels[4*(tempy*winX+tempx)+2] = 100+2*int(sin(phi)*50);
                    }
                    window.draw(*(currentPencil->getCircle()));

                }

        }

        texture.update(pixels);

		//end drawing
        window.display(); //window is done drawing
    }

    delete pixels; pixels = nullptr;
    return 0;
}
