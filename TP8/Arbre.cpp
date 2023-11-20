#include "Arbre.h"
#include "File.h"
#include "Pile.h"
#include <cstddef>
#include <iostream>

Arbre::Arbre (){
    this->adRacine = nullptr;
}

Arbre::~Arbre (){
    vider();
}

///Part of vider
void viderNoeud(Noeud* noeud){
    if(noeud != nullptr){
        viderNoeud(noeud->fg);
        viderNoeud(noeud->fd);
        delete noeud;
    }
}

void Arbre::vider (){
    viderNoeud(this->adRacine);
    this->adRacine = nullptr;
}

bool Arbre::estVide () const{
    return this->adRacine == nullptr;
}

void insererElementNoeud(Noeud*& noeud, ElementA e){
    if(noeud==nullptr){
        noeud = new Noeud();
        noeud->info = e;
    }
    else if(noeud->info>e){
        insererElementNoeud(noeud->fg, e);
    }
    else{
        insererElementNoeud(noeud->fd, e);
    }
}

void Arbre::insererElement (ElementA e){
    insererElementNoeud(this->adRacine, e);
}

const void afficherParcoursInfixeNoeud(Noeud* noeud){
    if(noeud != nullptr){
        afficherParcoursInfixeNoeud(noeud->fg);
        std::cout << noeud->info << " | ";
        afficherParcoursInfixeNoeud(noeud->fd);
    }
}

void Arbre::afficherParcoursInfixe () const{
    afficherParcoursInfixeNoeud(this->adRacine);
}

void rechercherElementNoeud(Noeud* noeud, ElementA e, bool & trouve, int & nb_visites){
    if(noeud!=nullptr){
        nb_visites++;
        if(noeud->info == e){
            trouve = true;
        }
        else{
            if(noeud->info>e){
                rechercherElementNoeud(noeud->fg, e, trouve, nb_visites);
            }
            else{
                rechercherElementNoeud(noeud->fd, e, trouve, nb_visites);
            }
        }
    }
    else{
        trouve = false;
    }
}

void Arbre::rechercherElement (ElementA e, bool & trouve, int & nb_visites) const{
    rechercherElementNoeud(this->adRacine,e,trouve,nb_visites);
}

int hauteurArbreNoeud(Noeud* noeud){
    if(noeud==nullptr){
        return 0;
    }
    int FG = hauteurArbreNoeud(noeud->fg);
    int FD = hauteurArbreNoeud(noeud->fd);
    return std::max(FG,FD)+1;
}

int Arbre::hauteurArbre () const{
    return hauteurArbreNoeud(this->adRacine);
}

const void affichageParcoursEnLargeurNoeud(Noeud* noeud, File& file){
    if(noeud!=nullptr){
        //Celui qui a fait ce sujet... IF I SPEAK I'M IN BIG TROUBLE
        //J'arrive pas a convertir un ElementA en ElementL... par ce que bien sur ils ont pas fait de fonction pour le faire...
        void* e = static_cast<void*>(static_cast<void*>(&noeud->info));        
        file.enfiler(e);
        affichageParcoursEnLargeurNoeud(noeud->fg, file);
        affichageParcoursEnLargeurNoeud(noeud->fd, file);
    }
    
}

void Arbre::affichageParcoursEnLargeur () const{
    if(estVide()){
        std::cout << "L'arbre est vide !" << std::endl;
    }
    else{
        File file = File();
        affichageParcoursEnLargeurNoeud(this->adRacine, file);
        for(int i=0; i<file.nbElements();i++){
            std::cout << static_cast<int*>(file.premierDeLaFile()) << " | ";
            file.defiler();
        }
        std::cout << std::endl;
    }
}

const void affichageParcoursEnLargeurHorsExerciceNoeud(Noeud* noeud){
    if(noeud != nullptr){
        std::cout << noeud->info << " | ";
        affichageParcoursEnLargeurHorsExerciceNoeud(noeud->fg);
        affichageParcoursEnLargeurHorsExerciceNoeud(noeud->fd);
    }
}

void Arbre::affichageParcoursEnLargeurHorsExercice () const{
    affichageParcoursEnLargeurHorsExerciceNoeud(this->adRacine);
}

const void afficherParcoursPostfixeHorsExerciceNoeud(Noeud* noeud){    
    if(noeud != nullptr){
        afficherParcoursPostfixeHorsExerciceNoeud(noeud->fg);
        afficherParcoursPostfixeHorsExerciceNoeud(noeud->fd);
        std::cout << noeud->info << " | ";    
    }

}

void Arbre::afficherParcoursPostfixeHorsExercice() const{
    afficherParcoursPostfixeHorsExerciceNoeud(this->adRacine);
}
