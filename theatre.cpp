#include "Theatre.h"
#include <iostream>    
using namespace std;    

// Constructeur
Theatre::Theatre(int code ,int isbn, string auteur, string titre, string editeur, string publique, bool libre, bool prete, string bibliotheque_d_origine, int siecle)
    : livre(code, isbn, auteur, titre, editeur, publique, libre, prete, bibliotheque_d_origine)
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
