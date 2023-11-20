#ifndef _ELEMENT_A
#define _ELEMENT_A

typedef int ElementA;

void afficherElementA(ElementA e);
/* Preconditions : aucune
   Postconditions : e est affiché à l'écran sans retour à la ligne
*/

bool estInferieurElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Résultat : vrai si e1 < e2, faux sinon */

bool estSuperieurElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Résultat : vrai si e1 > e2, faux sinon */

bool estSuperieurOuEgalElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Résultat : vrai si e1 >= e2, faux sinon */

bool estEgalElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Résultat : vrai si e1 == e2, faux sinon */

#endif
