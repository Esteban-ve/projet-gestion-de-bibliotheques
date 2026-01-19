#ifndef THEATRE_H
#define THEATRE_H

#include "livre.h"
using namespace std;

class Theatre : public livre {
protected:
    int siecle;

public:
    // Constructeur
    Theatre(int code ,int isbn, string auteur, string titre, string editeur, string publique, bool libre, bool prete, string bibliotheque_d_origine, int siecle);

    //Méthode
    void afficher() const override;

    // Getter
    int get_siecle() const;

    // Setter
    void set_siecle(int siecle);
};

#endif
