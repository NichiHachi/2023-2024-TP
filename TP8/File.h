#ifndef _FILE
#define _FILE

#include "Liste.h"

typedef ElementL ElementF;

class File {
public:

    /* Données membres */
    /* =============== */
    Liste l;

    /* Fonctions membres */
    /* ================= */
    File ();
    /* Postcondition : la file est initialement vide */

    ~File ();
    /* Postcondition : la mémoire allouée sur le tas est libérée */

     File& operator = (const File & f);
    /* Postcondition : la file a le même contenu que f */

    unsigned int nbElements () const;
    /* Résultat : retourne le nombre d'éléments présents dans la file */

    void enfiler (ElementF e);
    /* Postcondition : adr est ajouté en fin de file */

    void defiler ();
    /* Postcondition : l'élément de tête de file est supprimé ("first in, first out") */

    ElementF premierDeLaFile () const;
    /* Precondition : la file est non vide
       Résultat : l'element qui se trouve en tête de file */

    bool estVide () const;
    /* Résultat : vrai si la file est vide, faux sinon */

};

#endif
