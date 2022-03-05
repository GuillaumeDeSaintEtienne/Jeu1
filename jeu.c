//
// Created by Guillaume dse on 05/03/2022.
//

#include "main.h"

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
    char** tab = choixDuMot();
    Mot mot;
    gets(mot.mot);

}

// fonction choidMot à voir eventuellement plus tard
char** choixDuMot(){ //97 à 122 pour lettre minuscule
    int nbLettres;
    printf("Combien de lettres possède votre mot\n");
    scanf("%d",&nbLettres);
    int** mot = calloc(nbLettres +1, sizeof(char));
    printf("Quel est votre mot ? (ecrivez le en lettre minuscule) \n");
    scanf("%c", mot);
    for (int i = 0 ; i < nbLettres ; i++){
        if (mot[i] < 'a' || mot[i] > 'z'){
            printf("erreur");
        }
    }
    return mot;
}

bool verificationLettre(char* mot, char lettre, int* position){
    for(int i = 0; i<strlen(mot); i++){
        if (lettre == mot[i]){
            *position = i;
            return TRUE;
        }

    }
    return FALSE;
}

void affichage(char* mot, int vie){
    printf("%s\nIl vous reste %d vie(s) !\n", mot, vie);
}

void jeu( int NombreDeVie, Mot mot,int vie,int position){
    char lettre;
    char motAffiche[strlen(mot.mot)];
    bool reponse, reponseTrouve = false;
    bool vieRecu = false;
    int rep = 0;
    for(int a = 0; a < strlen(mot.mot); a++){
        motAffiche[a] = '_';
    }
    do{
        printf("choisissez une lettre\n");
        scanf("%c",&lettre);
        do{
            reponse = verificationLettre(motAffiche,lettre,&position);

            if (reponse == 1 ){
                motAffiche[position] = lettre;
                if (vieRecu == false){
                    NombreDeVie +=1;
                    vieRecu= true;
                }

            }
            if (reponse == 0){
                NombreDeVie -=1;
                vieRecu=false;
            }
            for (int y = 0; y < strlen(mot.mot); y++){
                rep = 0;
                if (mot.mot[y]==motAffiche[y])
                    rep++;

            }
            if (rep == strlen(mot.mot))
                reponseTrouve = TRUE;

            affichage(motAffiche, vie);
        }while (reponse);

    }while (NombreDeVie != 0 || reponseTrouve);

}