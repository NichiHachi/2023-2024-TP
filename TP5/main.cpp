#include <ctime>
#include <iostream>
#include "ElementTD.h"
#include "TableauDynamique.h"
#include <time.h>
//Il ne faut pas faire attention aux avertissements de compilation, normalement ils ne posent aucun problème 
//puisque la variable taille_utilisee contient une valeur lorsqu'un élément de TableauDynamique est initialisé.

int main(void){
    //Exercice 1
    TableauDynamique tab;

    //Exercice 3
    for(int i=0;i<10;i++){
        ElementTD e = i;
        tab.ajouterElement(e);
    }
    tab.afficher();
    std::cout << std::endl;

    std::cout << "Modifier l'element d'indice 5 :" << std::endl; 
    ElementTD modif = 10;
    tab.modifierValeurIemeElement(modif,5);
    tab.afficher();
    std::cout << std::endl;

    std::cout << "Supprimer l'element d'indice 2 :" << std::endl; 
    tab.supprimerElement(2);
    tab.afficher();
    std::cout << std::endl;


    //Exercice 5
    std::cout << "Ajout d'un element à l'indice 3 :" << std::endl; 
    TableauDynamique tabAlt(tab);
    ElementTD e = -1;
    tabAlt.insererElement(e,3);
    tabAlt.afficher();
    std::cout << std::endl;

    std::cout << "Tableau trié :" << std::endl;
    tabAlt.trier();
    tabAlt.afficher();
    std::cout << std::endl;

    ElementTD elementChercher = 1;
    int indexRecherche = tabAlt.rechercherElement(elementChercher);
    if(indexRecherche!=-1){
        std::cout << elementChercher << " est dans le tableau à l'indice " << indexRecherche << std::endl;
    }
    else{
        std::cout << elementChercher << " n'est pas dans le tableau" << std::endl;
    }
    elementChercher = 2;
    indexRecherche = tabAlt.rechercherElement(elementChercher);
    if(indexRecherche!=-1){
        std::cout << elementChercher << " est dans le tableau à l'indice " << indexRecherche << std::endl;
    }
    else{
        std::cout << elementChercher << " n'est pas dans le tableau" << std::endl;
    }
    std::cout << std::endl;

    //Exercice 4
    //Je peux pas tester car ça fait soit un crash soit un core dumped (Un peu abusé ce qu'il demande...)
    clock_t T0,T1;
    TableauDynamique tab1;
    std::cout << "Nombre d'elements | T0 | T1" << std::endl;
    for(int n=100000;n<=20000000;n+=100000){
        std::cout << n;

        ElementTD tab0[n];
        T0 = clock();
        for(int i=0;i<n;i++){
            ElementTD e = i;
            tab0[i] = e;
        }
        T0 = clock()-T0;
        std::cout << " | " << ((float)T0)/CLOCKS_PER_SEC;

        tab1.vider();
        T1 = clock();
        for(int i=0;i<n;i++){
            ElementTD e = i;
            tab1.ajouterElement(e);
        }
        T1 = clock()-T1;
        std::cout << " | " << ((float)T1)/CLOCKS_PER_SEC;

        std::cout << std::endl;
    }
}