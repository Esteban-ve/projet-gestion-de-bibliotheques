#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
using namespace std;

class livre {
protected:
    int code;
    int isbn;
    string auteur;
    string titre;
    string editeur;
    string publique;
    bool libre;
    bool prete;
    string bibliotheque_d_origine;

    void afficher_infos() const; // la méthode afficher est protected pour être sur que les classes filles doivent en changer

public:

    livre(int code ,int isbn, string auteur, string titre, string editeur, string publique, bool libre, bool prete, string bibliotheque_d_origine);
    
    virtual ~livre() = default; // le destructeur
    virtual void afficher() const; // la version écrasable de l'affichage des livres

    // les getters

    int get_code() const;
    int get_isbn() const;
    string get_auteur() const;
    string get_titre() const;
    string get_editeur() const;
    string get_publique() const;
    bool get_libre() const;
    bool get_prete() const;
    string get_bibliotheque_d_origine() const;


    // les setters

    void set_code(int code);
    void set_isbn(int isbn);
    void set_auteur(const string& auteur);
    void set_titre(const string& titre);
    void set_editeur(const string& editeur);
    void set_publique(const string& publique);
    void set_libre(bool libre);
    void set_prete(bool prete);
    void set_bibliotheque_d_origine(const string& bibliotheque);

};

#endif
