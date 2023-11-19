#ifndef _ELEMENT_L
#define _ELEMENT_L

typedef int ElementL;

void afficherElementL(ElementL e);

bool estEgalElementL(ElementL e1, ElementL e2);
/* Preconditions : aucune
   Résultat : renvoie vrai si e1 est égal à e2, faux sinon */

bool estInferieurElementL(ElementL e1, ElementL e2);
/* Preconditions : aucune
   Résultat : renvoie vrai si e1 est strictement inférieur à e2, faux sinon */

#endif
