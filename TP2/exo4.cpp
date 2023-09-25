#include <iostream>
using namespace std;

/* Calcul d’un coefficient binomial à l’aide du triangle de Pascal */
int comb_original(int n, int p) {
    //Pré-condition : n et p sont des entiers positifs
    //Post-condition : tmp1 et tmp2 sont des entiers positifs
    //Résultat : Un entier (La somme de tmp1 et tmp2)
    int tmp1, tmp2;
    cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
    if ((p==0) || (n==p))
        return 1;
    tmp1 = comb_original(n-1, p-1); /* premier appel récursif */
    tmp2 = comb_original(n-1, p); /* second appel récursif */
    return tmp1 + tmp2;
}
void comb(int n, int p, int& resultat){
    //Pré-condition : n,p et resultat des entiers positifs
    //Post-condition : tmp1 et tmp2 des entiers positifs
    //Resultat : Aucun
    int tmp1, tmp2;
    cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
    if((p==0) || (n==p)){
        resultat = 1;
    }
    else{
        comb(n-1, p-1, tmp1);
        comb(n-1,p,tmp2);
        resultat = tmp1 + tmp2;
    }

}



int main() {
    int c;
    int resultat;
    comb(4, 3, resultat);
    cout << "c vaut " << resultat << endl;
    return 0;
}