//
// Created by Guillaume dse on 05/03/2022.
//

#include "jeu.h"

int nombreAleatoireEntre(int min, int max){
    return rand() %(max- min+1 )+min;
}

void choixNombreDeVie(int* vie){
    do{
        printf("Combien de vie voulez-vous (entre 5 et 10)\n");
        scanf("%d", vie);
    }while(*vie < 5 || *vie > 10);
}

void choixDuJ(int* nombreDejoueur, int* choixJ){
    *choixJ = nombreAleatoireEntre(1, *nombreDejoueur);
    printf("Le joueur %d doit choisir le mot !\n", *choixJ);
}

void setup(int* nombreDejoueur, int* choixJ, int* vie){
    choixDuJ(nombreDejoueur, choixJ);
    choixNombreDeVie(vie);
    char** tab = choixDuMot;
}

char** choixDuMot(){ //97 à 122 pour lettre minuscule
    int nbLettres;
    printf("Combien de lettres possède votre mot\n");
    scanf("%d",&nbLettres);
    int* mot = calloc(nbLettres +1, sizeof(char));
    printf("Quel est votre mot ? (ecrivez le en lettre minuscule) \n");
    scanf("%c", mot);
    for (int i = 0 ; i < nbLettres ; i++){
        if (mot[i] < 'a' || mot[i] > 'z'){
            printf("erreur");
        }
    }
    return mot;
}
