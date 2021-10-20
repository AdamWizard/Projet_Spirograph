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

    //game loop
/*
    sf::CircleShape tabCircle[spiro.getNbPoints()]; // +1 to add the pencil in the circles list
    for(int i = 0; i < spiro.getNbPoints(); i++)
    {
        sf::CircleShape circle(1);
        if(i < spiro.getNbPoints()-1)
            circle.setRadius(spiro.getPoint(i+1)->getRho());

        circle.setOrigin(circle.getRadius(), circle.getRadius());
        circle.setOutlineThickness(1);
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineColor(sf::Color::White);
        int sumX = winX/2;
        for(int j = i; j>0; j--)
        {
            sumX += tabCircle[j-1].getRadius();
        }
        circle.setPosition(sumX, winY/2);

        tabCircle[i] = circle;
    }

    sf::CircleShape movingCircle(spiro.getPoint(2)->getRho());
    movingCircle.setOrigin(movingCircle.getRadius(), movingCircle.getRadius());
    movingCircle.setOutlineThickness(1);
    movingCircle.setFillColor(sf::Color::Transparent);
    movingCircle.setOutlineColor(sf::Color::White);
    movingCircle.setPosition(winX/2+circle.getRadius()+movingCircle.getRadius(),winY/2);


    sf::CircleShape movingCircle2(1);
    movingCircle2.setOrigin(movingCircle2.getRadius(), movingCircle2.getRadius());
    movingCircle2.setOutlineThickness(2);
    movingCircle2.setFillColor(sf::Color::Transparent);
    movingCircle2.setOutlineColor(sf::Color::White);
    movingCircle2.setPosition(winX/2+movingCircle.getRadius()+movingCircle2.getRadius(),winY/2);*/

    //FIN TEST

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

        //updating
        window.clear();
        //updating spiro
        for (int i=0;i<spiro.getNbDiscs();i++)
        {
            cout << "r, x, y : " <<spiro.getDisc(i)->getRadius()<<", "<< spiro.getDisc(i)->getX() << ", " << spiro.getDisc(i)->getY() << endl;
        }
        cout<<"updating spiro"<<endl;
        spiro.update();

        //end updating spiro

        //SKETCH : rayon variable pour le disque tournant
        //R+=sin(theta)/3;
        //movingCircle.setRadius(R);
        //FIN SKETCH


        //drawing
        //debugging
        cout<<"beginning drawing spiro"<<endl;
        for (int i=0;i<spiro.getNbDiscs();i++){
                //drawing discs
                if(drawDiscs)
                {
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

                }

        }

        texture.update(pixels);
		window.draw(sprite);
		//end drawing
        window.display(); //window is done drawing
    }

    delete pixels; pixels = nullptr;
    return 0;
}
