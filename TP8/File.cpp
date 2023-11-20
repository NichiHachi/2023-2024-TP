#include "File.h"
#include "Liste.h"

#include <iostream>

File::File (){
    this->l = Liste();
}

File::~File (){
}

File& File::operator = (const File & f){
    //Je sais pas comment faire pour y faire tenir sur une seule ligne... GL !
    this->l = f.l;
    return *this;
}

unsigned int File::nbElements () const{
    return this->l.nbElements();
}

void File::enfiler (ElementF e){
    this->l.ajouterEnQueue(e);
}

void File::defiler (){
    this->l.supprimerTete();
}

ElementF File::premierDeLaFile () const{
    return this->l.iemeElement(0);
}

bool File::estVide () const{
    return this->l.estVide();
}