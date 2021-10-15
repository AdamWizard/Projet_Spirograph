#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Spirograph.h"

using namespace std;

int main()
{
    //travail d'affichage du spirograph

    //mettre en place une fenetre et la possibilité d'intéragir
    sf::RenderWindow window(sf::VideoMode(640,640), "Spirograph",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(120);
    sf::Event ev;

    //game loop
    //TEST initialiser les cercles et la liste de points
    sf::CircleShape circle(100);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setOutlineThickness(2);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::White);
    circle.setPosition(window.getSize().x/2,window.getSize().y/2);

    sf::CircleShape movingCircle(50);
    movingCircle.setOrigin(movingCircle.getRadius(), movingCircle.getRadius());
    movingCircle.setOutlineThickness(2);
    movingCircle.setFillColor(sf::Color::Transparent);
    movingCircle.setOutlineColor(sf::Color::White);
    movingCircle.setPosition(window.getSize().x/2+circle.getRadius()+movingCircle.getRadius(),window.getSize().y/2);


    sf::CircleShape movingCircle2(10);
    movingCircle2.setOrigin(movingCircle2.getRadius(), movingCircle2.getRadius());
    movingCircle2.setOutlineThickness(2);
    movingCircle2.setFillColor(sf::Color::Transparent);
    movingCircle2.setOutlineColor(sf::Color::White);
    movingCircle2.setPosition(window.getSize().x/2+movingCircle.getRadius()+movingCircle2.getRadius(),window.getSize().y/2);

    //float[2]* list;
    //FIN TEST

    float vx=0;
    float vy=0;
    float theta=0;
    float phi=0;
    float R1 = circle.getRadius();
    float R2 = movingCircle.getRadius();
    float R3 = movingCircle2.getRadius();

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

        window.draw(circle);
        window.draw(movingCircle);
        window.draw(movingCircle2);
        //updating circles
        //i need to get a better definition of pi ...
        theta+=2*3.1415/120;
        phi=(R1/R2)*theta;
        //movingCircle.move((R1+R2)*cos(theta),(R1+R2)*sin(theta));
        movingCircle.setPosition(circle.getPosition().x+(R1+R2)*cos(theta),circle.getPosition().y+(R1+R2)*sin(theta));
        movingCircle2.setPosition(movingCircle.getPosition().x+(R2-R3)*cos(theta+phi),
                                  movingCircle.getPosition().y+(R2-R3)*sin(theta+phi));
        //FIN TEST

        //fin affichage
        window.display(); //dire que la fenetre a fini d'etre dessinee
    }


    return 0;
}
