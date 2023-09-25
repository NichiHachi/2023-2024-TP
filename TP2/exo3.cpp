#include <iostream>

int main(){
    int length;
    std::cout << "Taille du tableau :";
    std::cin >> length;
    float*tab = new float[length];
    for(int i=0;i<length;i++){
        std::cout << "Valeur numéro " << i+1 << " du tableau :";
        std::cin >> tab[i];
    }
    for(int i=0;i<length;i++){
        std::cout << tab[i];
        if(i!=length-1){
            std::cout << "|";
        }
    }
    std::cout << std::endl;
    delete[] tab;
}