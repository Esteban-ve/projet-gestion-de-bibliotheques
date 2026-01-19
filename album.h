#ifndef ALBUM_H
#define ALBUM_H

#include "livre.h"
#include <string>
using namespace std;

class Album : public livre {
private:
    string illustration;

public:
    // Constructeur
    Album(int code ,int isbn, string auteur, string titre,
          string editeur, string publique, bool libre, bool prete,
          string bibliotheque_d_origine, const string& illustration);

    //Méthode
    void afficher() const override;
    
    // Getter
    string get_illustration() const;

    // Setter
    void set_illustration(const string& illustration);
};

#endif
