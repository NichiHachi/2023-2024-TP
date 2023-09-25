#include <cmath>
#include <iostream>

struct Vecteur3D{
    float x;
    float y;
    float z;
};

float Vecteur3DGetNorme(Vecteur3D vecteur){
    return sqrt(vecteur.x*vecteur.x+vecteur.y+vecteur.y+vecteur.z*vecteur.z);
}

void Vecteur3DNormaliser(Vecteur3D vecteur){
    float norme = Vecteur3DGetNorme(vecteur);
    vecteur.x/=norme;
    vecteur.y/=norme;
    vecteur.z/=norme;
}

bool Vecteur3DEstNormalise(Vecteur3D vecteur){
    return Vecteur3DGetNorme(vecteur)==1;
}

Vecteur3D Vecteur3DAdd(Vecteur3D vecteur1, Vecteur3D vecteur2){
    Vecteur3D vecteur3;
    vecteur3.x = vecteur1.x + vecteur2.x;
    vecteur3.y = vecteur1.y + vecteur2.y;
    vecteur3.z = vecteur1.z + vecteur2.z;
    return vecteur3;
}

void Vecteur3DAfficher(Vecteur3D vecteur){
    std::cout << "X:" << vecteur.x << ", Y:" << vecteur.y << ", Z:" << vecteur.z << std::endl;
}


void Vecteur3DRemplirTabVecteurs(Vecteur3D *tab, int length){ 
    srand (time(NULL));
    for(int i=0;i<length;i++){
        Vecteur3D vecteur;
        vecteur.x = rand()%21-10;
        vecteur.y = rand()%21-10;
        vecteur.z = rand()%21-10;
        tab[i]=vecteur;
    }
}

void Vecteur3DAfficherTabVecteurs(Vecteur3D *tab, int length){
    for(int i=0;i<length;i++){
        std::cout <<"Vecteur numéro " << i+1 << " : " ;
        Vecteur3DAfficher(tab[i]);
    }
}

int Vecteur3DMaxTabVecteurs(Vecteur3D *tab, int length){
    float normeMax = -1;
    int indexMax = -1;
    for(int i=0;i<length;i++){
        float norme = Vecteur3DGetNorme(tab[i]);
        if(normeMax < norme){
            normeMax = norme;
            indexMax = i;
        }
    }
    return indexMax;
}

void Vecteur3DConcatenationTabVecteurs(Vecteur3D *tab1, Vecteur3D *tab2, Vecteur3D *tab3, int length1, int length2){
    for(int i=0;i<length1;i++){
        tab3[i]=tab1[i];
    }
    for(int i=0;i<length2;i++){
        tab3[length1+i] = tab2[i];
    }
}

void Vecteur3DInverseTabVecteurs(Vecteur3D *tab, int length){
    for(int i=0;i<length/2;i++){
        Vecteur3D save = tab[i];
        tab[i] = tab[length-i-1];
        tab[length-i-1] = save;
    }
}

int main () {
    Vecteur3D vecteur1 = {5,2,1};
    Vecteur3D vecteur2 = {0,3,2};
    std::cout << "vecteur1 non normalise: ";
    Vecteur3DAfficher(vecteur1);
    std::cout << std::endl;
    std::cout << "vecteur2 non normalise: ";
    Vecteur3DAfficher(vecteur2);
    std::cout << std::endl;
    std::cout << "somme: ";
    Vecteur3DAfficher(Vecteur3DAdd(vecteur1,vecteur2));
    std::cout << std::endl;
    Vecteur3DNormaliser(vecteur1);
    Vecteur3DNormaliser(vecteur2);
    std::cout << "vecteur1 normalise: ";
    Vecteur3DAfficher(vecteur1);
    std::cout << std::endl;
    std::cout << "vecteur2 normalise: ";
    Vecteur3DAfficher(vecteur2);
    std::cout << std::endl;
    std::cout << "somme: ";
    Vecteur3D somme = Vecteur3DAdd(vecteur1,vecteur2);
    Vecteur3DAfficher(somme);
    if (Vecteur3DEstNormalise(somme)) std::cout << " est normalise" << std::endl;
    else std::cout << " n'est pas normalise" << std::endl;

    Vecteur3D tab[10];
    Vecteur3DRemplirTabVecteurs(tab, 10);
    Vecteur3DAfficherTabVecteurs(tab, 10);
    std::cout << "Index du vecteur le plus long : " << Vecteur3DMaxTabVecteurs(tab, 10) << std::endl;
    
    Vecteur3D tab2[5];
    Vecteur3DRemplirTabVecteurs(tab2, 5);

    Vecteur3D tab3[15];
    Vecteur3DConcatenationTabVecteurs(tab, tab2, tab3, 10, 5);
    Vecteur3DInverseTabVecteurs(tab3, 15);
    Vecteur3DAfficherTabVecteurs(tab3, 15);
    
    return 0;
}