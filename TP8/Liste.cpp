#include "ElementL.h"
#include "Liste.h"

#include <iostream>
#include <system_error>

Liste::Liste (){
    this->prem = nullptr;
    this->last = nullptr;
}
    /* Postcondition : la liste est initialement vide */

Liste::~Liste (){
    vider();
}
    /* Postcondition : la mémoire allouée sur le tas est libérée */

Liste& Liste::operator = (const Liste& l) {
    if (this != &l) { 
        this->vider();
        Cellule* cell = l.prem; 
        //On ajoute un par un les élément de 'l' dans la nouvelle liste jusqu'à arriver à la fin
        while (cell != nullptr) {
            ajouterEnQueue(cell->info);
            cell = cell->suivant;
        }
    }
    return *this;
}


void Liste::vider() {
    Cellule* cell = this->prem;
    //On libère la mémoire de chaque sous cellule
    while (cell != nullptr) {
        Cellule* next = cell->suivant;
        delete cell; 
        cell = next; 
    }
    prem = nullptr;
    last = nullptr;
} 

bool Liste::estVide () const{
    return(this->prem == nullptr);
}

unsigned int Liste::nbElements () const{
    Cellule* cell = this->prem;
    int index = 0;
    while(cell!=nullptr){
        cell = cell->suivant;
        index++;
    }
    return index;
}

ElementL Liste::iemeElement (unsigned int indice) const{
    if(0>indice || indice>=nbElements() || estVide()){
        throw std::runtime_error("Humm skill issue mate ?");    
    }
    else{
        Cellule* cell = this->prem;
        for(int i=0;i<indice;i++){
            cell = cell->suivant;
        } 
        return cell->info;
    }
}

void Liste::modifierIemeElement (unsigned int indice, ElementL e){
    if(0>indice || indice>=nbElements() || estVide()){
        throw std::runtime_error("Humm skill issue mate ?");    
    }
    else{
        Cellule* cell = this->prem;
        for(int i=0;i<indice;i++){
            cell = cell->suivant;
        }
        cell->info = e;
    }
}

void Liste::afficherGaucheDroite () const{ 
    Cellule* cell = this->prem;
    while(cell->suivant!=nullptr){
        std::cout << cell->info << " -> ";
        cell = cell->suivant;
    }
    std::cout << cell->info << std::endl;
}

void Liste::afficherDroiteGauche () const{
    Cellule* cell = this->last;
    while(cell->precedent!=nullptr){
        std::cout << cell->info << " <- ";
        cell = cell->precedent;
    }
    std::cout << cell->info << std::endl;

}

void Liste::ajouterEnTete (ElementL e){
    Cellule* cell = new Cellule();
    cell->info = e;
    cell->precedent = nullptr;    
    //Si il n'y a aucune élément dans la liste, alors l'élément ajouter est à la fois le premier et le dernier de la liste
    if(prem == nullptr){
        cell->suivant = nullptr;
        prem = cell;
        last = cell;
    }
    else{
        this->prem->precedent = cell;
        cell->suivant = this->prem;
        this->prem = cell;
    }
}

void Liste::ajouterEnQueue (ElementL e){
    Cellule* cell = new Cellule();
    cell->info = e;
    cell->suivant = nullptr;
    //Si il n'y a aucune élément dans la liste, alors l'élément ajouter est à la fois le premier et le dernier de la liste
    if (last == nullptr) {
        cell->precedent = nullptr;
        prem = cell;
        last = cell;
    }
    else{
        this->last->suivant = cell;
        cell->precedent = this->last;
        this->last = cell;
    }
}

void Liste::supprimerTete (){
    if(estVide()){
        throw std::runtime_error("Humm skill issue mate ?");    
    }
    else{
        this->prem = this->prem->suivant;
    }
}

int Liste::rechercherElement (ElementL e) const{
    Cellule* cell = this->prem;
    int index = 0;
    while(cell!=nullptr){
        if(cell->info == e){
            return index;
        }
        cell = cell->suivant;
        index++;
    }
    return -1;
}

void Liste::insererElement (ElementL e, unsigned int indice){
    if(0>indice || indice>nbElements()){
        throw std::runtime_error("Humm skill issue mate ?");    
    }
    else{
        if(indice == 0){
            ajouterEnTete(e);
        }
        else if(indice == nbElements()){
            ajouterEnQueue(e);
        }
        else{
            Cellule* cell = this->prem;
            Cellule* cellInsert = new Cellule;
            cellInsert->info = e;
            
            //On se dirige vers la cellule précédente à celle que l'on veut insérer l'élément
            for(int i=0;i<indice-1;i++){
                cell = cell->suivant;
            }

            //On définit les cellules précédente et suivante à la cellule qu'on veut insérer
            cellInsert->suivant = cell->suivant;
            cellInsert->precedent = cell;
            cell->suivant->precedent = cellInsert;
            cell->suivant = cellInsert;
        }
    }
}

/// Tri par insertion
void Liste::trier (){
    int j;
    for(int i=0; i<nbElements(); i++){
        ElementL cell = iemeElement(i);
        for(j=i;j>0 && iemeElement(j-1)>cell;j--){
            modifierIemeElement(j, iemeElement(j-1));
        }
        modifierIemeElement(j, cell);
    }
}
