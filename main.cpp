#include "Livre.h"
#include "Livre.cpp"
#include "Album.h"
#include "Album.cpp"
#include "Bibliotheque.h"
#include "Bibliotheque.cpp"
#include "Roman.h"
#include "Roman.cpp"
#include "Poesie.h"
#include "Poesie.cpp"
#include "Bande_dessinee.h"
#include "Bande_dessinee.cpp"
#include "Theatre.h"
#include "Theatre.cpp"
#include "Adherent.h"
#include "Adherent.cpp"

#include <iostream>     // importe la bibliothèque 'iostream' qui permet d'utiliser les fonctions pour input/output (ex: 'cin' et 'cout', et donc de pouvoir print des choses dans la console)
using namespace std;    // permet de ne pas ajouter à chaque fois 'std' lorsqu'on veut print un message

int main() {

    // Création de bibliothèques (c'est bien comme début)
    Bibliotheque bibliotheque_de_centrale("Bibliothèque de Centrale", "1 Rue Julio Curry Centrale", 1);
    Bibliotheque bibliotheque_cannebiere("Bibliothèque de Cannebiere", "50 Bd Cannebiere", 2);

    // Création des livres
    Album* album1 = new Album(1, 26271, "Antoine de Saint-Exupéry", "Le Petit Prince", "Gallimard", "Tout public", true, false, "Bibliothèque de Centrale", "des illustrations");
    Theatre* theatre1 = new Theatre(2, 368222, "Molière", "Le Malade imaginaire", "Flammarion", "Tout public", true, false, "Bibliothèque de Centrale", 17);
    Roman* roman1 = new Roman(3, 9354, "J.K. Rowling", "Harry Potter est un sorcier", "Gallimard Jeunesse", "Jeunesse", true, false, "Bibliothèque de Centrale", "Fantastique");
    Poesie* poesie1 = new Poesie(4, 9789183, "Victor Hugo", "Les Misérables", "Gallimard", "Tout public", true, false, "Bibliothèque de Centrale", "Romantique");
    Bande_dessinee* bd1 = new Bande_dessinee(5, 97451, "René Goscinny / Albert Uderzo", "Astérix et Obelix les vendeurs de minir", "Uderzo and co", "Tout public", true, false, "Bibliothèque de Centrale", "Uderzo");

    // Création d'un adhérent
    Adherent adherent1("Pat", "Patrouille", "12 Rue du chien", 1, "Bibliothèque de Centrale");
    Adherent adherent2("Paul", "Denis", "12 Rue du Coq", 2, "Bibliothèque de Cannebiere");

    // Ajouter les livres à la bibliothèque
    bibliotheque_de_centrale.acheter_livre(album1);
    bibliotheque_de_centrale.acheter_livre(theatre1);
    bibliotheque_de_centrale.acheter_livre(roman1);
    bibliotheque_de_centrale.acheter_livre(poesie1);
    bibliotheque_de_centrale.acheter_livre(bd1);

    // Afficher tous les livres de la bibliothèque
    bibliotheque_de_centrale.afficher_livres();

    // l'adhérent1 emprunte des livres
    adherent1.emprunter_livre(album1);
    adherent1.emprunter_livre(roman1);
    // on vérifie que les livres ne sont plus dans la bibliothèque 
    bibliotheque_de_centrale.afficher_livres();

    // L'adhérent rend un livre
    adherent1.rendre_livre(album1);

    // On réaffiche les livres dans la bibliothèque
    bibliotheque_de_centrale.afficher_livres();

    // Suppression: on supprime le livre qui n'a pas été rendu + le theatre qu'on aime plus
    bibliotheque_de_centrale.detruire_livre(theatre1); // on l'aime plus
    bibliotheque_de_centrale.detruire_livre(roman1); // on le considère perdu

    return 0;
}
