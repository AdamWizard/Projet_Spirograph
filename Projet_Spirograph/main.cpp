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
    //FOR WAY LATER
    int nbDiscs = 2;

    //Spirograph *spirograph = new Spirograph();

    double R1,R2;
    cout<<"Radius of the first disc"<<endl;
    cin >> R1;

    cout<<"Radius of the second disc"<<endl;
    cin >> R2;
    //^^^^A mettre dans le builder de spirograph (pour l'instant garder 2 disques en rotation interne/externe on se casse pas la tete)
    MovingPoint *currentPoint = new MovingPoint();
    float radius;

    //travail d'affichage du spirograph

    //mettre en place une fenetre et la possibilité d'intéragir
    int winX = 640; int winY = 640;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "Spirograph",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;

    //game loop
    //TEST initialiser les cercles et la liste de points

    /*int i = 0;
    while(spirograph.)*/

    sf::CircleShape circle(R1);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setOutlineThickness(1);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::White);
    circle.setPosition(winX/2,winY/2);

    sf::CircleShape movingCircle(R2);
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
    movingCircle2.setPosition(winX/2+movingCircle.getRadius()+movingCircle2.getRadius(),winY/2);

    //float[2] *list;
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

    float theta=0;
    float phi=0;
    float R3 = movingCircle2.getRadius();
    float angspeed = M_PI/500;

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
                break;
            }
        }

        //mise a jour de l'environnement

        window.clear(); //effacer l'ancien ecran
        //affichage

        //TEST : dessiner des cercles et les faire bouger

        //updating circles
        theta += angspeed;
        phi=(R1/R2)*theta;
        //movingCircle.move((R1+R2)*cos(theta),(R1+R2)*sin(theta));
        movingCircle.setPosition(circle.getPosition().x+(R1+R2)*cos(theta),circle.getPosition().y+(R1+R2)*sin(theta));
        movingCircle2.setPosition(movingCircle.getPosition().x+(R2)*cos(theta+phi),
                                  movingCircle.getPosition().y+(R2)*sin(theta+phi));
        //FIN TEST

        //TEST : rayon variable pour le disque tournant
        //R2+=sin(theta)/2;
        //movingCircle.setRadius(R2);
        //phi=(R1/R2)*theta;
        //FIN SKETCH

        int tempx = int(movingCircle2.getPosition().x);
        int tempy = int(movingCircle2.getPosition().y);

        if (4*(tempy*winX+tempx) < winX*winY*4){
            pixels[4*(tempy*winX+tempx)] = 100;
            pixels[4*(tempy*winX+tempx)+1] = 200;
            pixels[4*(tempy*winX+tempx)+2] = 100;
        }

        texture.update(pixels);
		window.draw(sprite);

		window.draw(circle);
        window.draw(movingCircle);
        window.draw(movingCircle2);
        //fin affichage
        window.display(); //window is done drawing
    }


    return 0;
}
