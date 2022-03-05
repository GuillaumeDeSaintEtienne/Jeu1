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

    Mot mot;
    gets(mot.mot);

}


bool verificationLettre(char* mot, char* affichageMot, char lettre, int* position) {
    for (int i = 0; i<=strlen(mot); i++){
        if (lettre == mot[i] && affichageMot[i] == '_') {
            *position = i;
            return true;
        }

    }
    return false;
}

void affichage(char* mot, int vie){
    printf("%s\nIl vous reste %d vie(s) !\n", mot, vie);
}

int jeu( int NombreDeVie, Mot mot,int vie,int position){
    printf("Choisir le mot :\n");
    gets(mot.mot);
    choixNombreDeVie(&vie);

    char lettre;
    char motAffiche[100] = {0};
    bool reponse = false, reponseTrouve = false;
    bool vieRecu = false;
    int rep = 0;
    for(int a = 0; a < strlen(mot.mot); a++){
        motAffiche[a] = '_';
    }
    do{
        do{
            printf("choisissez une lettre\n");
            fflush(stdin);
            gets(&lettre);
            fflush(stdin);
            reponse = verificationLettre(mot.mot, motAffiche,lettre, &position);

            if (reponse == 1){
                motAffiche[position] = lettre;
                if (vieRecu == false){
                    vie +=1;
                    vieRecu= true;
                }
            }
            if (reponse == 0){
                vie -=1;
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
        }while (reponse == false && vie > 0);

    }while (vie != 0 || reponseTrouve);

    ALLEGRO_DISPLAY* display = NULL;
    assert(al_init());


    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_window_title(display, "Tu es mort looser !");


    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_line(20,700,800,700,al_map_rgb(255, 255, 255),10);
    al_flip_display();


    al_rest(10.0);


    al_destroy_display(display);

}
