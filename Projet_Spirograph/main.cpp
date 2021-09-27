#include <iostream>
#include <SFML/Graphics.hpp>

#include "Spirograph.h"

using namespace std;

int main()
{
    int nbDisques;
    cout << "Combien de disques ce spirographe aura-t-il? ";
    cin >> nbDisques;

    float d;
    cout << "Quelle est la distance entre le centre du dernier disque et le point mobile?";
    cin >> d;

    Spirograph *spirograph = new Spirograph();

    Disque* disqueActuel = new Disque();
    float rayon;
    //coordonnees centrees
    for (int i=0;i<nbDisques;i++){
            cout << "rayon du disque numero " << i+1 << ": ";
            cin >> rayon ;
        //ajouter un disque au spirograph aux coordonnees [somme des rayons des autres disques] en x
    }

    //faire le travail d'affichage du spirograph


    return 0;
}
