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

        bool estPlusPetit(NbComplexe nbr){
            return module()<nbr.module();
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
    NbComplexe nbr1(1,1);
    NbComplexe nbr2(2,2);
    if(nbr1.estPlusPetit(nbr2)){
        std::cout << "nrb1 est plus petit que nbr2" << std::endl;
    }
    else{
        std::cout << "nrb1 est plus grand que nbr2" << std::endl;
    }
    return 1;
}