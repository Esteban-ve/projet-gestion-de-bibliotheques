#include "Roman.h"
#include <iostream>

Roman::Roman(int code ,int isbn, string auteur, string titre,
             string editeur, string publique, bool libre, bool prete,
             string bibliotheque_d_origine,
             const string& genre)
    : livre(code, isbn, auteur, titre, editeur, publique, libre, prete, bibliotheque_d_origine)
{
    this->genre = genre;
}

void Roman::afficher() const {
    livre::afficher(); // affiche les données liées à la classe mère livre
    cout << "Roman : " << this->titre
         << " (Genre : " << this->genre << ")" << endl;
}

string Roman::get_genre() const {
    return this->genre;
}

void Roman::set_genre(const string& genre) {
    this->genre = genre;
}
