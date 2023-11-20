#ifndef _PILE
#define _PILE

#include "TableauDynamique.h"

typedef ElementTD ElementP;

class Pile {
public:
    /* Données membres */
    /* =============== */
    TableauDynamique t;

    /* Fonctions membres */
    /* ================= */
    Pile ();
    /* Postcondition : la pile est initialement vide */

    ~Pile ();
    /* Postcondition : la mémoire allouée sur le tas est libérée */

    Pile (const Pile & p);
    /* Precondition : la pile p est initialisée */
    /* Postcondition : les deux piles ont le même contenu */

    void empiler (ElementP e);
    /* Postcondition : le sommet de la pile est une copie de e */

    void depiler ();
    /* Precondition : la pile n'est pas vide
       Postcondition : le sommet de la pile est dépilé ("last in, first out") */

    ElementP consulterSommet () const;
    /* Precondition : la pile n'est pas vide
       Résultat : l'élément qui se trouve au sommet de la pile */

    bool estVide () const;
    /* Résultat : vrai si la pile est vide, faux sinon */

    void afficher () const;
    /* Postcondition : les elements contenues dans la pile sont affichées a l'écran,
     c-à-d les adresses en hexadécimal, en commençant par la base de la pile (le sommet est affiché en dernier) */

};

#endif
