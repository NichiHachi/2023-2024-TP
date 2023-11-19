#include <iostream>

#include "Liste.h"
#include "ElementL.h"

//MERCI CHAT GPT
int main(void) {
    Liste maListe;

    // Test de la fonction estVide()
    std::cout << "La liste est vide ? " << (maListe.estVide() ? "Oui" : "Non") << std::endl;

    // Ajout de quelques éléments pour tester les autres fonctions
    maListe.ajouterEnQueue(10);
    maListe.ajouterEnQueue(20);
    maListe.ajouterEnQueue(30);
    maListe.ajouterEnQueue(40);
    maListe.ajouterEnQueue(50);

    // Test de la fonction nbElements()
    std::cout << "Nombre d'elements dans la liste : " << maListe.nbElements() << std::endl;

    // Test de la fonction iemeElement()
    std::cout << "Element a l'indice 2 : " << maListe.iemeElement(2) << std::endl;

    // Test de la fonction modifierIemeElement()
    maListe.modifierIemeElement(2, 99);
    std::cout << "Element a l'indice 2 apres modification : " << maListe.iemeElement(2) << std::endl;

    // Test de la fonction afficherGaucheDroite()
    std::cout << "Affichage de la liste de gauche a droite : ";
    maListe.afficherGaucheDroite();

    // Test de la fonction afficherDroiteGauche()
    std::cout << "Affichage de la liste de droite a gauche : ";
    maListe.afficherDroiteGauche();

    // Test de la fonction supprimerTete()
    maListe.supprimerTete();
    std::cout << "Apres suppression de la tete, nombre d'elements dans la liste : " << maListe.nbElements() << std::endl;

    // Test de la fonction rechercherElement()
    int index = maListe.rechercherElement(40);
    if (index != -1) {
        std::cout << "L'element 40 se trouve a l'indice : " << index << std::endl;
    } else {
        std::cout << "L'element 40 n'est pas dans la liste." << std::endl;
    }

    // Test de la fonction insererElement()
    maListe.insererElement(777, 2);
    std::cout << "Apres insertion de 777 a l'indice 2, nouvelle liste : ";
    maListe.afficherGaucheDroite();

    // Test de la fonction trier()
    maListe.trier();
    maListe.afficherGaucheDroite();

    return 0;
}
