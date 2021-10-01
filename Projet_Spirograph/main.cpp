#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Spirograph.h"

using namespace std;

int main()
{
    int nbDiscs;
    cout << "How many discs will this spirograph have? ";
    cin >> nbDiscs;

    float d;
    cout << "What will be the distance between the last discs center and the pencil?";
    cin >> d;

    Spirograph *spirograph = new Spirograph();

    Disc* currentDisc = new Disc();
    float radius;
    //coordonnees centrees
    for (int i=0;i<nbDiscs;i++){
            cout << "radius of disc number " << i+1 << ": ";
            cin >> radius ;
        //ajouter un disque au spirograph aux coordonnees [somme des rayons des autres disques] en x
    }

    //travail d'affichage du spirograph

    //mettre en place une fenetre et la possibilité d'intéragir
    sf::RenderWindow window(sf::VideoMode(640,640), "Spirograph",sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

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
                break;
            }
        }

        //mise a jour de l'environnement

        window.clear(); //effacer l'ancien ecran
        //affichage

        //fin affichage
        window.display(); //dire que la fenetre a fini d'etre dessinee
    }


    return 0;
}
