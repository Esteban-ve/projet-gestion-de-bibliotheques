#ifndef BANDE_DESSINEE_H
#define BANDE_DESSINEE_H

#include "livre.h"
#include <string>
using namespace std;

class Bande_dessinee : public livre {
private:
    string dessinateur;

public:
    Bande_dessinee(int code ,int isbn, string auteur, string titre,
                   string editeur, string publique, bool libre, bool prete,
                   string bibliotheque_d_origine,
                   const string& dessinateur);
    
    void afficher() const override;
    string get_dessinateur() const;
    void set_dessinateur(const string& dessinateur);
};

#endif
