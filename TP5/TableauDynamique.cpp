#include <iostream>
#include "ElementTD.h"
#include "TableauDynamique.h"

//Exercice 1
TableauDynamique::TableauDynamique (){
    this-> ad = new ElementTD[1];
    this-> capacite = 1;
    this-> taille_utilisee = 0;
}

TableauDynamique::TableauDynamique (const TableauDynamique& t){
    ElementTD* nouveauTab = new ElementTD[t.capacite];
    for(int i=0;i<t.taille_utilisee;i++){
        nouveauTab[i] = t.ad[i];
    }
    this-> ad = nouveauTab;
    this-> capacite = t.capacite;
    this-> taille_utilisee = t.taille_utilisee;
}

TableauDynamique::~TableauDynamique (){
    delete[] ad;
    this-> capacite = 0;
    this-> taille_utilisee = 0;
}

//Exercice 3
void TableauDynamique::vider (){
    this-> ad = new ElementTD[1];
    this-> capacite = 1;
    this-> taille_utilisee = 0; 
}

void TableauDynamique::ajouterElement (ElementTD e){
    if(taille_utilisee==capacite){
        ElementTD *nouveauTab = new ElementTD[capacite*2];
        for(int i=0;i<taille_utilisee;i++){
            nouveauTab[i] = ad[i];
        }
        delete[] ad;
        this-> ad = nouveauTab;
        this-> capacite*=2;
    }
    this-> ad[taille_utilisee] = e;
    this-> taille_utilisee++;
}

ElementTD TableauDynamique::valeurIemeElement (unsigned int indice) const{
    return ad[indice];
}

void TableauDynamique::modifierValeurIemeElement (ElementTD e, unsigned int indice){
    this-> ad[indice] = e;
}

void TableauDynamique::afficher ()const{
    std::cout << '[';
    for(int i=0;i<taille_utilisee;i++){
        afficheElementTD(ad[i]);
        if(i!=taille_utilisee-1){
            std::cout << '|';
        }
    }
    std::cout << ']' <<std::endl;
}

void TableauDynamique::supprimerElement (unsigned int indice){
    this-> taille_utilisee--;
    for(int i=indice;i<taille_utilisee;i++){
        this-> ad[i] = ad[i+1];
    }
    if(taille_utilisee < capacite/3){
        this-> capacite/=2;
        ElementTD *nouveauTab = new ElementTD[capacite];
        for(int i=0;i<taille_utilisee;i++){
            nouveauTab[i] = ad[i];
        }
        delete[] ad;
        this-> ad = nouveauTab;
    }
}

//Exercice 5
void TableauDynamique::insererElement (ElementTD e, unsigned int indice){
    ElementTD elem = ad[indice];
    this-> ad[indice] = e;
    indice++;
    if(indice==taille_utilisee){
        ajouterElement(elem);
    }
    else{
        insererElement(elem, indice);
    }
}


void TableauDynamique::trier (){
    /*Tri Fusion du tableau*/
    if(taille_utilisee!=1){
        TableauDynamique tab1;
        TableauDynamique tab2;
        for(int i=0;i<taille_utilisee/2;i++){
            tab1.ajouterElement(ad[i]);
        }
        for(int i=taille_utilisee/2;i<taille_utilisee;i++){
            tab2.ajouterElement(ad[i]);
        }
        tab1.trier();
        tab2.trier();
        int index1 = 0;
        int index2 = 0;
        while(index1+index2!=taille_utilisee){
            if(index1 == tab1.taille_utilisee){
                ad[index1+index2] = tab2.ad[index2];
                index2++;
            }
            else if(index2 == tab2.taille_utilisee){
                ad[index1+index2] = tab1.ad[index1];
                index1++;
            }
            else if(tab1.ad[index1]<tab2.ad[index2]){
                ad[index1+index2] = tab1.ad[index1];
                index1++;
            }
            else{
                ad[index1+index2] = tab2.ad[index2];
                index2++;
            }
        }
    }
}

int TableauDynamique::rechercherElement (ElementTD e) const{
    /*Recherche dichotomique*/
    int indexMin = 0;
    int indexMax = taille_utilisee-1;
    int indexRecherche;
    while(indexMin<=indexMax){
        indexRecherche = (indexMin+indexMax)/2;
        if(ad[indexRecherche]==e){
            return indexRecherche;
        }
        else if(ad[indexRecherche]>e){
            indexMax = indexRecherche-1;
        }
        else{
            indexMin = indexRecherche+1;
        }
    }
    return -1;
}



