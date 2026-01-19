#ifndef ADHERENT_H
#define ADHERENT_H

#include <string>
#include "livre.h"
using namespace std;

const int MAX_EMPRUNTS = 5;  // nombre maximal de livres empruntés par un adhérent

class Adherent {
private:
    string nom;
    string prenom;
    string adresse;
    int numero_adherent;
    string bibliotheque_d_inscription;
    livre* livres_empruntes[MAX_EMPRUNTS];
    int nb_emprunts;

public:
    Adherent(string nom, string prenom, string adresse, int numero_adherent, const string& biblio);

    // Getters
    string get_nom() const;
    string get_prenom() const;
    string get_adresse() const;
    int get_numero_adherent() const;
    string get_bibliotheque() const;
    int get_nb_emprunts() const;
    livre* get_livre_emprunte(int index) const;

    // Setters
    void set_nom(const string& nom);
    void set_prenom(const string& prenom);
    void set_adresse(const string& adresse);
    void set_bibliotheque(const string& biblio);

    // Méthodes
    void emprunter_livre(livre* l);
    void rendre_livre(livre* l);
};

#endif
