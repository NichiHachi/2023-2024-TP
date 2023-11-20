#ifndef _ELEMENT_L
#define _ELEMENT_L

typedef void * ElementL;

void afficherElementL(ElementL e);
/* Postconditions : l'adresse e est affichée à l'écran sans retour à la ligne */

bool estEgalElementL(ElementL e1, ElementL e2);
/* Résultat : renvoie vrai si e1 est égal à e2, faux sinon */

bool estInferieurElementL(ElementL e1, ElementL e2);
/* Résultat : renvoie vrai si e1 est strictement inférieur à e2, faux sinon */

#endif
