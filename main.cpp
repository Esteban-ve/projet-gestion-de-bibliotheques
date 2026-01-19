#include <iostream>     // importe la bibliothèque 'iostream' qui permet d'utiliser les fonctions pour input/output (ex: 'cin' et 'cout', et donc de pouvoir print des choses dans la console)
#include "Livre.h"
#include "Livre.cpp"
#include "Album.h"
#include "Album.cpp"
#include "Biblio.h"
#include "Biblio.cpp"
#include "Roman.h"
#include "Roman.cpp"
#include "Poesie.h"
#include "Poesie.cpp"
#include "Bande_dessinee.h"
#include "Bande_dessinee.cpp"



using namespace std;    // permet de ne pas ajouter à chaque fois 'std' lorsqu'on veut print un message

int main() {
    point p1 = point(2,4,6);
    point p2 = point(p1);   
    cout << "les coordonnees de p2 sont :" 
                "("<< p2.getX() << ","
                << p2.getY() << ","
                << p2.getZ() << ")" << endl;
    return 0;

}
