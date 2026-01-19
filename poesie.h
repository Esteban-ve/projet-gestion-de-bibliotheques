#ifndef POESIE_H
#define POESIE_H

#include "livre.h"
#include <string>
using namespace std;

class Poesie : public livre {
private:
    string indicateur;

public:
    Poesie(int code ,int isbn, string auteur, string titre,
           string editeur, string publique, bool libre, bool prete,
           string bibliotheque_d_origine,
           const string& indicateur);

    string get_indicateur() const;
    void afficher() const override;
    void set_indicateur(const string& indicateur);
};

#endif
