#include "ElementTD.h"
#include "File.h"
#include "Pile.h"
#include <iostream>

//MERCI CHAT GPT
int main() {
    File file;

    // Test de la fonction enfiler
    file.enfiler(ElementF(10));
    file.enfiler(ElementF(20));
    file.enfiler(ElementF(30));

    // Test de la fonction nbElements
    std::cout << "Nombre d'éléments dans la file : " << file.nbElements() << std::endl;

    // Test de la fonction premierDeLaFile
    std::cout << "Premier élément de la file : " ; 
    afficherElementL(file.premierDeLaFile()); 
    std::cout << std::endl;

    // Test de la fonction estVide
    std::cout << "File vide ? " << (file.estVide() ? "Oui" : "Non") << std::endl;

    // Test de la fonction defiler
    file.defiler();
    std::cout << "Après avoir défilé, le premier élément est : "; 
    afficherElementL(file.premierDeLaFile()); 
    std::cout << std::endl;

    std::cout << std::endl;

    Pile pile;

    // Test de la fonction empiler
    pile.empiler(ElementF(10));
    pile.empiler(ElementF(20));
    pile.empiler(ElementF(30));

    // Test de la fonction consulterSommet
    std::cout << "Sommet de la pile : ";
    afficheElementTD(pile.consulterSommet());
    std::cout << std::endl;

    // Test de la fonction estVide
    std::cout << "La pile est vide ? " << (pile.estVide() ? "Oui" : "Non") << std::endl;

    // Test de la fonction afficher
    std::cout << "Contenu de la pile : ";
    pile.afficher();

    // Test de la fonction depiler
    pile.depiler();
    std::cout << "Après avoir dépilé, le sommet de la pile : ";
    afficheElementTD(pile.consulterSommet());
    std::cout << std::endl;


    return 0;
}
