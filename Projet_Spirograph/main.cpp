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
    /*Spirograph spiro;

    //travail d'affichage du spirograph

    //mettre en place une fenetre et la possibilité d'intéragir
    int winX = 640; int winY = 640;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "Spirograph",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;

    //game loop
    //TEST initialiser les cercles et la liste de points

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

    /*sf::CircleShape movingCircle(spiro.getPoint(2)->getRho());
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

    /*sf::Uint8*	pixels = new sf::Uint8[winX*winY*4];
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

    bool drawCircles = true;

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
                    drawCircles = !drawCircles;
                }
                break;
            }
        }

        //mise a jour de l'environnement

        window.clear(); //effacer l'ancien ecran
        //affichage

        //TEST : dessiner des cercles et les faire bouger

        //updating circles

        for(int i = 1; i < spiro.getNbPoints(); i++)
        {
            float angSpeed = spiro.getPoint(i)->getAngSpeed();
            float theta = spiro.getPoint(i)->getTheta() + angSpeed;
            float rho = tabCircle[i].getRadius();
            /*float phi = (tabCircle[i-1].getRadius()/tabCircle[i-2].getRadius())*theta;
            if(i == spiro.getNbPoints()-1)
                theta += phi;*/

            /*spiro.getPoint(i)->setTheta(theta);

            float x = tabCircle[i].getPosition().x;
            float y = tabCircle[i].getPosition().y;

            tabCircle[i].setPosition(int(x+(rho+spiro.getPoint(i)->getRho())*cos(theta)),
                                     int(y+(rho+spiro.getPoint(i)->getRho())*sin(theta)));

            if(i==2)
                cout << "x : " << int(x) << "\n";
        }*/
/*
        theta += angspeed;
        phi=(spiro.getPoint(1)->getRho()/spiro.getPoint(2)->getRho())*theta;


        //TEST : rayon variable pour le disque tournant
        //R2+=sin(theta)/3;
        //movingCircle.setRadius(R2);
        //FIN SKETCH

        movingCircle.setPosition(circle.getPosition().x+(spiro.getPoint(1)->getRho()+spiro.getPoint(2)->getRho())*cos(theta),
                                 circle.getPosition().y+(spiro.getPoint(1)->getRho()+spiro.getPoint(2)->getRho())*sin(theta));

        movingCircle2.setPosition(movingCircle.getPosition().x+(spiro.getPoint(2)->getRho())*cos(theta+phi),
                                  movingCircle.getPosition().y+(spiro.getPoint(2)->getRho())*sin(theta+phi));
        //FIN TEST

*/
        /*int tempx = int(tabCircle[spiro.getNbPoints()-1].getPosition().x);
        int tempy = int(tabCircle[spiro.getNbPoints()-1].getPosition().y);
        int phi = spiro.getPoint(spiro.getNbPoints()-1)->getTheta();

        if (4*(tempy*winX+tempx) < winX*winY*4){
            pixels[4*(tempy*winX+tempx)] = 100-2*int(cos(phi)*50);
            pixels[4*(tempy*winX+tempx)+1] = 100;
            pixels[4*(tempy*winX+tempx)+2] = 100+2*int(sin(phi)*50);
        }

        texture.update(pixels);
		window.draw(sprite);

        if(drawCircles)
        {
            for(int i = 0; i < spiro.getNbPoints(); i++)
            {
                window.draw(tabCircle[i]);
            }
        }

        //fin affichage
        window.display(); //window is done drawing
    }

    delete pixels; pixels = nullptr;*/
    return 0;
}
