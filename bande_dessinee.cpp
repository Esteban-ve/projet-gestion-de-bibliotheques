#include "Bande_dessinee.h"
#include <iostream>

Bande_dessinee::Bande_dessinee(int code ,int isbn, string auteur, string titre,
                               string editeur, string publique, bool libre, bool prete,
                               string bibliotheque_d_origine,
                               const string& dessinateur)
    : livre(code, isbn, auteur, titre, editeur, publique, libre, prete, bibliotheque_d_origine)
{
    this->dessinateur = dessinateur;
}

//la méthode
void Bande_dessinee::afficher() const {
    livre::afficher(); // affiche les données liées à la classe mère livre
    std::cout << ", dessinateur: " << dessinateur << std::endl;
}

// le getter
string Bande_dessinee::get_dessinateur() const {
    return this->dessinateur;
}

//le setter
void Bande_dessinee::set_dessinateur(const string& dessinateur) {
    this->dessinateur = dessinateur;
}
