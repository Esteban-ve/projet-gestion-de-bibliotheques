#include "livre.h"
#include <iostream>
using namespace std;

//  Constructeurs

livre::livre(int code, int isbn, string auteur, string titre, string editeur, string publique, bool libre, bool prete, string bibliotheque_d_origine)
{
    this->code = code;
    this->isbn = isbn;
    this->auteur = auteur;
    this->titre = titre;
    this->editeur = editeur;
    this->publique = publique;
    this->libre = libre;
    this->prete = prete;
    this->bibliotheque_d_origine = bibliotheque_d_origine;
}

// Méthode
void livre::afficher() const {
    std::cout << "Code: " << code
              << ", ISBN: " << isbn
              << ", Titre: " << titre
              << ", Auteur: " << auteur
              << ", Editeur: " << editeur
              << ", Public: " << publique
              << ", Libre: " << libre
              << ", Prêté: " << prete 
              << ", Bibliothèque: " << bibliotheque_d_origine;
}

// Getters
int livre::get_code() const {
    return this->code;
}

int livre::get_isbn() const {
    return this->isbn;
}

string livre::get_auteur() const {
    return this->auteur;
}

string livre::get_titre() const {
    return this->titre;
}

string livre::get_editeur() const {
    return this->editeur;
}

string livre::get_publique() const {
    return this->publique;
}

bool livre::get_libre() const {
    return this->libre;
}

bool livre::get_prete() const {
    return this->prete;
}

string livre::get_bibliotheque_d_origine() const {
    return this->bibliotheque_d_origine;
}


// Setters
void livre::set_code(int code) {
    this->code = code;
}

void livre::set_isbn(int isbn) {
    this->isbn = isbn;
}

void livre::set_auteur(const string& auteur) {
    this->auteur = auteur;
}

void livre::set_titre(const string& titre) {
    this->titre = titre;
}

void livre::set_editeur(const string& editeur) {
    this->editeur = editeur;
}

void livre::set_publique(const string& publique) {
    this->publique = publique;
}

void livre::set_libre(bool libre) {
    this->libre = libre;
}

void livre::set_prete(bool prete) {
    this->prete = prete;
}

void livre::set_bibliotheque_d_origine(const string& bibliotheque) {
    this->bibliotheque_d_origine = bibliotheque;
}


