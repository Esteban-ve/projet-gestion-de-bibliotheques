#ifndef THEATRE_H
#define THEATRE_H

#include "livre.h"
using namespace std;

class Theatre : public livre {
protected:
    int siecle;

public:
    // Constructeur
    Theatre(const livre& livreBase, int siecle);

    //Méthode
    void afficher() const override;

    // Getter
    int get_siecle() const;

    // Setter
    void set_siecle(int siecle);
};

#endif
