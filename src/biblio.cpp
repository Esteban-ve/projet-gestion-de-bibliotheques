#include "biblio.h"
#include <iostream>
#include <string> // pour utiliser le type string
#include <list>

// Constructeurs (Rem.: TOUS les constructeurs d'une classe doivent avoir le même nom que celui de la classe)

biblio :: (string name, stirng ad, int c, list<livre> L) {
    this-> x = a;
    this-> y = b;
    this-> z = c;
}



point :: point(const point& p) {
    this-> x = p.x;
    this-> y = p.y;
    this-> z = p.z;
}


// Getters
int point :: getX() const {
    return x;
}

int point :: getY() const {
    return y;
}

int point :: getZ() const {
    return z;
}

// Setters
void point :: setX(int X) {
    this-> x = X;
}

void point :: setY(int Y) {
    this-> y = Y;
}

void point :: setZ(int Z){
    this-> z = Z;
}