#include <iostream>
#include <cmath>

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

        float module(){
            return sqrt(re*re+im*im);
        }

        void Afficher(){
            std::cout << re << ' ';
            if(im<0){
                std::cout << im;
            }
            else{
                std::cout << '+' << im;
            }
            std::cout << " i" << std::endl;
        }
};

int main(){
    srand (time(NULL));
    int length;
    std::cout << "Longueur du tableau :";
    std::cin >> length;
    NbComplexe*tab = new NbComplexe[length];
    for(int i=0;i<length;i++){
        NbComplexe nbr(rand()%201/10.0-10,rand()%201/10.0-10);
        tab[i] = nbr;
    }
    for(int i=0;i<length;i++){
        std::cout << i << " : ";
        tab[i].Afficher();
    }
    delete[] tab;
    return 1;
}