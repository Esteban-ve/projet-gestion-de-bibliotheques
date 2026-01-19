#ifndef BIBLIO_H   // corrigé
#define BIBLIO_H

#include <string>
#include "livre.h"
using namespace std;

const int MAX_LIVRES = 5;

class Bibliotheque {
private:
    string nom;
    string adresse;
    int code;
    livre* list_livres[MAX_LIVRES];
    int nb_livres;

public:
    Bibliotheque(string nom, string adresse, int code);

    // Getters
    string get_nom() const;
    string get_adresse() const;
    int get_code() const;
    int get_nb_livres() const;
    livre* get_livre(int index) const;

    // Setters
    void set_nom(const string& nom);
    void set_adresse(const string& adresse);
    void set_code(int code);

    // Méthodes
    void acheter_livre(livre* l);
    void detruire_livre(livre* l);
    void afficher_livres() const;
};

#endif
