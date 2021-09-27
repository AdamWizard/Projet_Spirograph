#include <iostream>
#include <SFML/Graphics.hpp>

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

    //faire le travail d'affichage du spirograph


    return 0;
}
