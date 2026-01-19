#ifndef ROMAN_H
#define ROMAN_H

#include "livre.h"
#include <string>
using namespace std;

class Roman : public livre {
private:
    string genre;

public:
    Roman(int code ,int isbn, string auteur, string titre,
          string editeur, string publique, bool libre, bool prete,
          string bibliotheque_d_origine,
          const string& genre);

    void afficher() const override;

    string get_genre() const;
    void set_genre(const string& genre);
};

#endif
