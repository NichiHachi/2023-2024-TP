#include <bits/types/clock_t.h>
#include <ctime>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>

class NbComplexe{
    private:
        float re;
        float im;
    public:
        //Sans parametre
        NbComplexe() : re(0), im(0) {}
        //Deux parametres
        NbComplexe(float re, float im) : re(re), im(im) {}
        //Constructeur par copie
        NbComplexe(const NbComplexe&nbr) : re(nbr.re), im(nbr.im) {}

        //Destructeur
        ~NbComplexe() {
        }

        void operator>>(std::ostream& os){
            std::cout << "Partie réelle :";
            std::cin >> re;
            std::cout << "Partie imaginaire :";
            std::cin >> im;
        }

        void operator *(NbComplexe nbr){
            float saveRe =  re*nbr.re - im*nbr.im;
            im = im*nbr.re + re*nbr.im;
            re = saveRe;
        }

        bool operator <(NbComplexe nbr){
            return module()<nbr.module();
        }

        friend std::ostream& operator<<(std::ostream& os, const NbComplexe& nbr){
            os << nbr.re << ' ';
            if(nbr.im<0){
                os << nbr.im;
            }
            else{
                os << '+' << nbr.im;
            }
            os << " i";
            return os;
        }

        float module(){
            return sqrt(re*re+im*im);
        }
};

void trierParSelection(NbComplexe *tab, int length){
    for(int i=0;i<length;i++){
        int indexMin=i;
        for(int t=i+1;t<length;t++){
            if(!(tab[indexMin]<(tab[t]))){
                indexMin = t;
            }
        }
        if(indexMin != i){
            NbComplexe save = tab[i];
            tab[i] = tab[indexMin];
            tab[indexMin] = save;
        }
    }
}

void trierParInsertion(NbComplexe *tab, int length){
    for(int i=0;i<length;i++){
        NbComplexe nbr = tab[i];
        int t = i;
        while(t>0 && nbr<tab[t-1]){
            tab[t] = tab[t-1];
            t--;
        }
        tab[t] = nbr;
    }
}

//Exercice2
void lireTabNbComplexeDepuisFichier(NbComplexe *&tab, int& length, std::string nom_fichier){
    std::ifstream fichier(nom_fichier+".txt");

    if(!fichier.is_open()){
        std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
        return;
    }

    std::string lignes;
    std::getline(fichier,lignes);
    length = std::stoi(lignes);
    tab = new NbComplexe[length];

    int index = 0;
    float re,im;
    std::stringstream lignesStream;
    std::string value;
    while(std::getline(fichier,lignes)){
        lignesStream.clear();
        lignesStream.str(lignes);
        for(int i=0;i<2;i++){
            std::getline(lignesStream,value,' ');
            if(!i){
                re = std::stof(value);
            }
            else{
                if(value[0]=='+'){
                    value.erase(0,1);
                }
                im=std::stof(value);
                NbComplexe nbr(re,im);
                tab[index] = nbr;
            }
        }
        index++;
    }
    fichier.close();
}

//Exercice3
void ecrireTabNbComplexeDansFichier(NbComplexe *tab, int length, std::string nom_fichier){
    std::ofstream fichier(nom_fichier+".txt");

    if(fichier.is_open()){
        fichier << length << std::endl;
        for(int i=0;i<length;i++){
            fichier << tab[i] << std::endl;
        }
        fichier.close();
    }
}


int main(){
    NbComplexe *tab;
    int length;
    lireTabNbComplexeDepuisFichier(tab, length, "random");
    trierParInsertion(tab,length);
    ecrireTabNbComplexeDansFichier(tab, length, "liste_triee");
    //Exercice 4
    std::string liste_fichier[3] = {"random","sorted","reverse"};
    std::cout << "Fichier à trier   Tri par selection   Tri par insertion" << std::endl;
    clock_t tempsExecution;
    for(std::string &nom_fichier : liste_fichier){
        std::cout << nom_fichier << "            ";
        //Trie par Selection
        lireTabNbComplexeDepuisFichier(tab, length, nom_fichier);
        tempsExecution = clock();
        trierParSelection(tab, length);
        tempsExecution = clock() - tempsExecution;
        std::cout << ((float)tempsExecution)/CLOCKS_PER_SEC << "             ";
        //Trie par Insertion
        lireTabNbComplexeDepuisFichier(tab, length, nom_fichier);
        tempsExecution = clock();
        trierParInsertion(tab, length);
        tempsExecution = clock() - tempsExecution;
        std::cout << ((float)tempsExecution)/CLOCKS_PER_SEC << std::endl;
    }
}