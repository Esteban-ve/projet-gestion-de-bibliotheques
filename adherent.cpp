#include "Adherent.h"
#include <iostream>

Adherent::Adherent(string n, string p, string a, int num, const string& biblio)
    : nom(n), prenom(p), adresse(a), numero_adherent(num), bibliotheque_d_inscription(biblio), nb_emprunts(0)
{
    for(int i = 0; i < MAX_EMPRUNTS; i++) livres_empruntes[i] = nullptr;
}

string Adherent::get_nom() const { return nom; }
string Adherent::get_prenom() const { return prenom; }
string Adherent::get_adresse() const { return adresse; }
int Adherent::get_numero_adherent() const { return numero_adherent; }
string Adherent::get_bibliotheque() const { return bibliotheque_d_inscription; }
int Adherent::get_nb_emprunts() const { return nb_emprunts; }
livre* Adherent::get_livre_emprunte(int index) const {
    if(index >= 0 && index < nb_emprunts) return livres_empruntes[index];
    return nullptr;
}

void Adherent::set_nom(const string& n) { nom = n; }
void Adherent::set_prenom(const string& p) { prenom = p; }
void Adherent::set_adresse(const string& a) { adresse = a; }
void Adherent::set_bibliotheque(const string& b) { bibliotheque_d_inscription = b; }

void Adherent::emprunter_livre(livre* l) {
    if(nb_emprunts < MAX_EMPRUNTS) {
        livres_empruntes[nb_emprunts++] = l;
        std::cout << nom << " a emprunté : ";
        l->afficher();
        l->set_libre(false);
        l->set_prete(true);
    } else {
        std::cout << nom << " a atteint le nombre maximal de livres empruntés." << std::endl;
    }
}

void Adherent::rendre_livre(livre* l) {
    for(int i = 0; i < nb_emprunts; i++) {
        if(livres_empruntes[i] == l) {
            std::cout << nom << " a rendu : ";
            l->afficher();
            l->set_libre(true);
            l->set_prete(false);
            for(int j = i; j < nb_emprunts - 1; j++) {
                livres_empruntes[j] = livres_empruntes[j+1];
            }
            livres_empruntes[--nb_emprunts] = nullptr;
            return;
        }
    }
}
