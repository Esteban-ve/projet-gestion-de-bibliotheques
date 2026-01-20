#include "Bibliotheque.h"
#include <iostream>

Bibliotheque::Bibliotheque(string n, string a, int c)
    : nom(n), adresse(a), code(c), nb_livres(0)
{
    for(int i = 0; i < MAX_LIVRES_BIBLIOTHEQUE; i++)
        list_livres[i] = nullptr;
}

// Getters
string Bibliotheque::get_nom() const { return nom; }
string Bibliotheque::get_adresse() const { return adresse; }
int Bibliotheque::get_code() const { return code; }
int Bibliotheque::get_nb_livres() const { return nb_livres; }
livre* Bibliotheque::get_livre(int index) const {
    if(index >= 0 && index < nb_livres)
        return list_livres[index];
    return nullptr;
}

// Setters
void Bibliotheque::set_nom(const string& n) { nom = n; }
void Bibliotheque::set_adresse(const string& a) { adresse = a; }
void Bibliotheque::set_code(int c) { code = c; }

// Méthodes
void Bibliotheque::acheter_livre(livre* l) {
    if(nb_livres < MAX_LIVRES_BIBLIOTHEQUE) {
        list_livres[nb_livres++] = l;
        std::cout << "Livre ajouté : ";
        l->afficher();
    } else {
        std::cout << "Bibliothèque pleine !" << std::endl;
    }
}

void Bibliotheque::ajouter_livre(livre* l, Bibliotheque& autre)
{
    if (nb_livres < MAX_LIVRES_BIBLIOTHEQUE) {
        list_livres[nb_livres++] = l;
        std::cout << "Livre ajouté : ";
        l->afficher();
    } else {
        std::cout << "La bibliothèque " << nom
                  << " est pleine, le livre est renvoyé à "
                  << autre.get_nom() << std::endl;

        // Le livre redevient disponible
        l->set_libre(true);
        l->set_prete(false);

        // Retour
        autre.ajouter_livre(l, *this);
    }
}


void Bibliotheque::detruire_livre(livre* l) {
    for(int i = 0; i < nb_livres; i++) {
        if(list_livres[i] == l) {
            std::cout << "Livre détruit : ";
            l->afficher();
            // Décaler les éléments pour combler le vide
            for(int j = i; j < nb_livres - 1; j++) {
                list_livres[j] = list_livres[j + 1];
            }
            list_livres[nb_livres - 1] = nullptr;
            nb_livres--;
            delete l;
            return;
        }
    }
    std::cout << "Livre non trouvé dans la bibliothèque." << std::endl;
}

void Bibliotheque::afficher_livres() const {
    std::cout << "Livres de la bibliothèque " << nom << " :" << std::endl;
    for(int i = 0; i < nb_livres; i++) {
        if(list_livres[i] != nullptr)
            list_livres[i]->afficher();
    }
}

bool Bibliotheque::emprunter_livre(int code_livre, Bibliotheque& autre)
{
    livre* l = this->get_livre(code_livre);
    if (!l) {
        cout << "Livre introuvable dans cette bibliothèque." << endl;
        return false;
    }

    if (!l->get_libre()) {
        cout << "Livre déjà emprunté." << endl;
        return false;
    }

    // livre disponible : on le marque
    l->set_libre(false);
    l->set_prete(true);

    // on le transfère dans l’autre biblio
    autre.ajouter_livre(l, *this);

    cout << "Livre code " << code_livre << " emprunté puis transféré vers " << autre.get_nom() << endl;
    return true;
}

bool Bibliotheque::emprunter_livre_global(int code_livre, Bibliotheque* biblios[], int nb_biblios)
{
    bool trouve = false; // pour savoir si on a enfin trouvé le livre
    Bibliotheque* source;  // la bibliotheque dans laquelle on a trouvé
    livre* l;               // le fameux livre 

    // On cherche dans toutes les bibliothèques
    for (int i = 0; i < nb_biblios; i++) {
        l = biblios[i]->get_livre(code_livre);
        if (l) {
            source = biblios[i];
            trouve = true;
            break;
        }
    }

    if (!trouve) {
        cout << "Livre non trouvé dans aucune bibliothèque." << endl;
        return false;
    }

    //On vérifie s'il est dispo
    if (!l->get_libre()) {
        cout << "Livre trouvé mais déjà emprunté." << endl;
        return false;
    }

    // on marque le livre comme emprunté
    l->set_libre(false);
    l->set_prete(true);

    // on retire le livre de la bibliothèque source
    int index = -1;
    for (int i = 0; i < source->nb_livres; i++) {
        if (source->list_livres[i] == l) {
            index = i;
            break;
        }
    }

    for (int i = index; i < source->nb_livres - 1; i++)
        source->list_livres[i] = source->list_livres[i + 1];

    source->nb_livres--;

    // on ajoute le livre à celle-ci (this)
    this->ajouter_livre(l, *source);

    cout << "Livre \"" << l->get_titre() << "\" transféré depuis "
         << source->get_nom() << " vers " << this->get_nom() << endl;

    return true;
}

