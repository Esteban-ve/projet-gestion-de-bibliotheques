#include "Theatre.h"
#include <iostream>    
using namespace std;    

// Constructeur
Theatre::Theatre(const livre& livreoriginale, int siecle)
    : livre(livreoriginale) // le constructeur de livre original (par copie)
{
    this->siecle = siecle;
}

//Méthode
void Theatre::afficher() const{
    livre::afficher(); // affiche les données liées à la classe mère livre
    std::cout << ",Siècle : " << siecle << std::endl;
}

// Getter
int Theatre::get_siecle() const {
    return this->siecle;
}

// Setter
void Theatre::set_siecle(int siecle) {
    this->siecle = siecle;
}
