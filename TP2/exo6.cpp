#include <iostream>

void procedureAvecPointeur(int * ptr){
    std::cout << "Valeur:" << ptr << " / Adresse mémoire:" << (long int)&ptr << std::endl;
}

void procedureAvecReference(int & rf){
    std::cout << "Valeur:" << rf << " / Adresse mémoire:" << (long int)&rf << std::endl;
}

void procedureAvecInt(int val){
    std::cout << "Valeur:" << val << " / Adresse mémoire:" << (long int)&val << std::endl;
}

int main(){
    int x = 1;
    int & rx = x;
    int * px = &x;

    std::cout << "Valeurs :" << std::endl;
    std::cout << "x:" << x << " / rx:" << rx << " / px:" << px << std::endl;
    std::cout << std::endl;

    std::cout << "Adresses mémoires :" << std::endl;
    std::cout << "x:" << (long int)&x << " / rx:" << (long int)&rx << " / px:" << (long int)&px << std::endl;
    std::cout << std::endl;

    procedureAvecPointeur(px);
    procedureAvecReference(x);
    procedureAvecReference(rx);
    procedureAvecInt(x);
    procedureAvecInt(rx);
}  