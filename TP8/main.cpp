#include <iostream>
#include "Arbre.h"
#include "ElementA.h"

int main() {
    Arbre arbre;

    srand(time(0)); 
    
    /*
    for(int i=0;i<255;i++){
        arbre.insererElement(ElementA(rand()%100000+1));
    }
    std::cout << "Taille de l'arbre créé : " << arbre.hauteurArbre() << std::endl;
    
    std::cout << "L'arbre affichage infixe : ";
    arbre.afficherParcoursInfixe();
    std::cout << std::endl;

    int nbrMoyenVisite = 0;
    for(int i=0;i<100;i++){
        ElementA elementRecherche = ElementA(rand()%100000+1);
        bool trouve;
        arbre.rechercherElement(elementRecherche,trouve, nbrMoyenVisite);
        std::cout << i+1 << " : L'élément " << elementRecherche;
        if(trouve){
            std::cout <<" est dans l'arbre." << std::endl;
        }
        else{
            std::cout <<" ne se trouve pas dans l'arbre." << std::endl;
        }
    }
    std::cout << "Nombre moyen de visite : " << nbrMoyenVisite/100 << std::endl;
    arbre.vider();
    std::cout << std::endl;
    */

    std::cout << "------ 60 fois le processus complet ------" << std::endl;
    std::cout << "Numero de l'arbre | Taille | Visite moyen" << std::endl;

    for(int indexArbre=0;indexArbre<60;indexArbre++){
        int nbrMoyenVisite = 0;
        for(int i=0;i<255;i++){
            arbre.insererElement(ElementA(rand()%100000+1));
        }
        for(int i=0;i<100;i++){
            ElementA elementRecherche = ElementA(rand()%100000+1);
            bool trouve;
            arbre.rechercherElement(elementRecherche,trouve, nbrMoyenVisite);
        }
        std::cout << indexArbre+1 << " : " << arbre.hauteurArbre() << " --- "<< nbrMoyenVisite/100<< std::endl;
        arbre.vider();
    }

    for(int i=0;i<255;i++){
        arbre.insererElement(ElementA(rand()%100000+1));
    }
    
    std::cout << std::endl;
    //std::cout << "----- Affichage parcours en largeur ----- (Ne fonctionne pas)" << std::endl;
    //arbre.affichageParcoursEnLargeur();
    //std::cout << std::endl;
    //std::cout << std::endl;
    std::cout << "----- Affichage parcours en infixe -----" << std::endl;
    arbre.afficherParcoursInfixe();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----- Affichage parcours en largeur -----" << std::endl;
    arbre.affichageParcoursEnLargeurHorsExercice();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----- Affichage parcours en postfixe -----" << std::endl;
    arbre.afficherParcoursPostfixeHorsExercice();
    std::cout << std::endl;
            
    arbre.vider();
    return 0;
}
