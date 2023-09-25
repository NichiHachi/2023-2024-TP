#include <iostream>

class NbComplexe{
    private:
        float re;
        float im;
    public:
        void Init(){
            std::cout << "Partie réelle :";
            std::cin >> re;
            std::cout << "Partie imaginaire :";
            std::cin >> im;
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
    NbComplexe nbr;
    nbr.Init();
    nbr.Afficher();
    nbr.Init();
    nbr.Afficher();
    std::cout << "Taille d'un nombre complexe : " << sizeof(nbr) << std::endl;
    return 1;
}