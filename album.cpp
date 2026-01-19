#include "Album.h"
#include <iostream>
using namespace std;

// Constructeur
Album::Album(int code ,int isbn, string auteur, string titre,
             string editeur, string publique, bool libre, bool prete,
             string bibliotheque_d_origine,
             const string& illustration)
    : livre(code, isbn, auteur, titre, editeur, publique, libre, prete, bibliotheque_d_origine)
{
    this->illustration = illustration;
}


//Méthode
void Album::afficher() const {
    livre::afficher(); // affiche les données liées à la classe mère livre
    std::cout << ", Illustration: " << illustration << std::endl;
}


// Getter
string Album::get_illustration() const {
    return this->illustration;
}

// Setter
void Album::set_illustration(const string& illustration) {
    this->illustration = illustration;
}
