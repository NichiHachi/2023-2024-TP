#ifndef _ARBRE
#define _ARBRE

#include "ElementA.h"

struct Noeud {
    ElementA info;
    Noeud * fg;
    Noeud * fd;
};

class Arbre {
public:

    /* Donn�es membres */
    /* =============== */

    Noeud * adRacine;

    /* Fonctions membres */
    /* ================= */

    Arbre ();
    /* Postcondition : l'arbre est initialement vide */

    ~Arbre ();
    /* Postcondition : la m�moire allou�e sur le tas est lib�r�e */

    void vider ();
    /* Postcondition : l'arbre est vide */

    bool estVide () const;
    /* R�sultat : vrai si l'arbre est vide, faux sinon */

    void insererElement (ElementA e);
    /* Postcondition : si e n'existe pas d�j� dans l'arbre, alors un nouveau noeud contenant e est ins�r�,
                       si e existe d�j� dans l'arbre, alors l'arbre est inchang� */

   void afficherParcoursInfixe () const;
    /* Postcondition : affichage infixe de tous les �l�ments de l'arbre (espacement entre les noeuds) */

    void rechercherElement (ElementA e, bool & trouve, int & nb_visites) const;
    /* Postcondition : Si aucun noeud de l'arbre ne contient la valeur e, trouve vaut faux.
                       Si on a trouv� un noeud avec le e demand�, alors trouve vaut vrai.
                       Dans les deux cas, nb_visites contient le nombre de noeuds test�s lors de cette recherche. */

    int hauteurArbre () const;
    /* R�sultat : la hauteur de l'arbre (longueur de sa plus longue branche), ou -1 s'il est vide */

    void affichageParcoursEnLargeur() const;

    void affichageParcoursEnLargeurHorsExercice() const;

    void afficherParcoursPostfixeHorsExercice() const;
};

#endif
