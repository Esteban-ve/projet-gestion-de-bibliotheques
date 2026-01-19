#include "Poesie.h"
#include <iostream>

Poesie::Poesie(int code ,int isbn, string auteur, string titre,
               string editeur, string publique, bool libre, bool prete,
               string bibliotheque_d_origine,
               const string& indicateur)
    : livre(code, isbn, auteur, titre, editeur, publique, libre, prete, bibliotheque_d_origine)
{
    this->indicateur = indicateur;
}

void Poesie::afficher() const {
    livre::afficher(); // affiche les données liées à la classe mère livre
    std::cout << ", indicateur: " << indicateur << std::endl;
}


string Poesie::get_indicateur() const {
    return this->indicateur;
}

void Poesie::set_indicateur(const string& indicateur) {
    this->indicateur = indicateur;
}
