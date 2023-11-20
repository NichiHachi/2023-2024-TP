#include "Pile.h"
#include "TableauDynamique.h"

Pile::Pile (){
    this->t = TableauDynamique();
}

Pile::~Pile (){
    this->t.vider();
}

Pile::Pile (const Pile & p){
    this->t = TableauDynamique(p.t);
}

void Pile::empiler (ElementP e){
    this->t.insererElement(e, 0);
}

void Pile::depiler (){
    this->t.supprimerElement(0);
}

ElementP Pile::consulterSommet () const{
    return this->t.valeurIemeElement(0);
}

bool Pile::estVide () const{
    return this->t.taille_utilisee == 0;
}

void Pile::afficher () const{
    this->t.afficher();
}