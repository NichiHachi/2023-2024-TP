#include <iostream>

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

        void multiplier(NbComplexe nbr){
            float saveRe =  re*nbr.re - im*nbr.im;
            im = im*nbr.re + re*nbr.im;
            re = saveRe;
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
    nbr1.multiplier(nbr2);
    nbr1.Afficher();
    return 1;
}