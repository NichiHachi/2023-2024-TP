#include <cmath>
#include <iostream>

struct Vecteur3D{
    float x;
    float y;
    float z;
};

void Vecteur3DRemplirTabVecteurs(Vecteur3D *tabVecteurPile, Vecteur3D *tabVecteurTas, int length){ 
    srand (time(NULL));
    for(int i=0;i<length;i++){
        Vecteur3D vecteur;
        vecteur.x = rand()%201/10.0-10;
        vecteur.y = rand()%201/10.0-10;
        vecteur.z = rand()%201/10.0-10;
        tabVecteurPile[i]=vecteur;
        tabVecteurTas[i]=vecteur;
    }
}

int main(){
    Vecteur3D tabVecteurPile[3];
    Vecteur3D*tabVecteurTas = new Vecteur3D[3];
    Vecteur3DRemplirTabVecteurs(tabVecteurPile, tabVecteurTas, 3);
    std::cout << "Taille du tableau Pile : " << sizeof(tabVecteurPile) << std::endl;
    std::cout << "Taille du tableau Tas : " << sizeof(tabVecteurTas) << std::endl;
    std::cout << std::endl;

    std::cout << "Adresse du premier élément du tableau Pile : " << (long int) &tabVecteurPile[0] << std::endl;
    std::cout << "Adresse du premier élément du tableau Tas : " << (long int) &tabVecteurTas[0] << std::endl;
    std::cout << std::endl;

    std::cout << "Adresse des champs du deuxième élément du tableau Pile :" << std::endl;
    std::cout << "x:" << (long int) &tabVecteurPile[1].x << " / y:" << (long int) &tabVecteurPile[1].y << " / z:" << (long int) &tabVecteurPile[1].z << std::endl;
    std::cout << "Adresse des champs du deuxième élément du tableau Tas :" << std::endl;
    std::cout << "x:" << (long int) &tabVecteurTas[1].x << " / y:" << (long int) &tabVecteurTas[1].y << " / z:" << (long int) &tabVecteurTas[1].z << std::endl;
    std::cout << std::endl;

    std::cout << "Contenu de *(tabVecteurPile+2) :" << std::endl;
    std::cout << "x:" << (*(tabVecteurPile + 2)).x << " / y:" << (*(tabVecteurPile + 2)).y << " / z:" << (*(tabVecteurPile + 2)).z << std::endl;
    std::cout << "Contenu de *(tabVecteurTas+2) :" << std::endl;
    std::cout << "x:" << (*(tabVecteurTas + 2)).x << " / y:" << (*(tabVecteurTas + 2)).y << " / z:" << (*(tabVecteurTas + 2)).z << std::endl;
    std::cout << std::endl;

    tabVecteurPile[0].x = (long int)&tabVecteurTas[1].y - (long int)&tabVecteurTas[2].z;
    std::cout << "Version avec long int : " << tabVecteurPile[0].x << std::endl;
    tabVecteurPile[0].x = &tabVecteurTas[1].y - &tabVecteurTas[2].z;
    std::cout << "Version sans long int : " << tabVecteurPile[0].x << std::endl;
}