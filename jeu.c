//
// Created by Guillaume dse on 05/03/2022.
//

#include "main.h"

int menu1() {
    char choix = 0;
    bool erreur;
    do {
        erreur = 0;
        printf("\n\n================== Menu ================== \n\n");
        printf("                Pendu \n       realise par Guigui et Emil\n\n\n\n");

        printf("       Appuyez sur J pour JOUER\n");
        printf("Appuyez sur R pour afficher les REGLES DU JEUX\n");
        printf(" Appuyez sur I pour afficher des INFORAMTIONS\n");
        printf("       Appuyez sur Q pour QUITTER\n");
        printf("\n\n\n        ------------------------");
        printf("\n            Projet 2022\n               ECE LYON\n          Tous droits reserves\n");
        printf("        ------------------------\n");
        printf("\n               Lettre ?\n");
        scanf(" %c", &choix);
        printf("\n\n\n\n\n\n");
        if (!(choix == 'J' || choix == 'R' || choix == 'I' || choix == 'Q')) {
            printf("\n\nChoix incorrect: ERREUR\n\n");
            erreur = 1;
        }
    } while (erreur == 1);
    return choix;
}

void menu2() {
    char retour;
    bool lancement = 0;
    do {
        retour = 0;
        switch (menu1()) {
            case 'J':
                printf("Lancement du jeu...\n");
                lancement = 1;
                break;
            case 'R':
                printf("Regle jeu de pendu \n\nLe principe du jeu est de deviner un mot cree par un joueur en lui proposant des lettres\n Si la lettre propose se trouve dans le mot, celle-ci s'affiche sinon vous perdez une vie.\n Si vous n'avez plus de vie alors vous etes pendu.\n\n Bonne Chance ! ");
                break;
            case 'I':
                printf("Cree par:\n Guillaume de Saint-Etienne \n Emilien Godet");
                break;
        }
        if (lancement == 0) {
            do {
                printf("\n\nAppuyer sur M pour retourner au MENU principal\n");
                scanf(" %c", &retour);
                if (retour != 'M') {
                    printf("Erreur:\nRECOMMENCEZ\n");
                }
            } while (retour != 'M');
        }
    } while (retour == 'M');
}


int nombreAleatoireEntre(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void choixNombreDeVie(int *vie) {
    do {
        for(int i=0;i<10;i++){
            printf("\n");
        }
        printf("Combien de vie voulez-vous (entre 5 et 10)\n");
        scanf("%d", vie);
    } while (*vie < 5 || *vie > 10);
}

void choixDuJ(int *nombreDejoueur, int *choixJ) {
    *choixJ = nombreAleatoireEntre(1, *nombreDejoueur);
    printf("Le joueur %d doit choisir le mot !\n", *choixJ);
}

void setup(int *nombreDejoueur, int *choixJ, int *vie) {
    choixDuJ(nombreDejoueur, choixJ);
    choixNombreDeVie(vie);

    Mot mot;
    gets(mot.mot);

}


bool verificationLettre(char *mot, char *affichageMot, char lettre, int *position) {
    for (int i = 0; i <= strlen(mot); i++) {
        if (lettre == mot[i] && affichageMot[i] == '_') {
            *position = i;
            return true;
        }

    }
    return false;
}

void affichage(char *mot, int vie) {
    printf("%s\nIl vous reste %d vie(s) !\n", mot, vie);
}

void affichageAllegro(int *vie){
    assert(al_init());
    ALLEGRO_DISPLAY *display = NULL;
    display = al_create_display(800, 600);
    assert(display != NULL);
    al_set_window_title(display, "Jeu de pendu !");
    al_clear_to_color(al_map_rgb(255, 255,  255));
    al_draw_filled_rectangle(100,550,700,570,al_map_rgb(0, 0, 0));
    al_flip_display();
    al_rest(5);
    al_destroy_display(display);
}

int jeu(int NombreDeVie, Mot mot, int vie, int position) {
    int nombreLettre = 0;
    printf("Choisir le mot :");
    gets(mot.mot);
    nombreLettre = sizeof (mot.mot);
    choixNombreDeVie(&vie);

    char lettre;
    char motAffiche[100] = {0};
    bool reponse = false, reponseTrouve = false;
    bool repjust = false;
    int rep = 0;
    for (int a = 0; a < strlen(mot.mot); a++) {
        motAffiche[a] = '_';
    }

    do {
        printf("Le mot contient %d lettres\n",nombreLettre);
        printf("choisissez une lettre\n");
        fflush(stdin);
        gets(&lettre);
        repjust = false;
        fflush(stdin);

        do {


            reponse = verificationLettre(mot.mot, motAffiche, lettre, &position);


            if (reponse == false && repjust == false) {
                vie -= 1;

                if (vie == 0) {
                    printf("you are a looser!\n");
                    printf("le mot etait %s !!!\n", mot.mot);
                    return 0;
                }
            }

            if (reponse == true) {
                motAffiche[position] = lettre;
                repjust = true;
            }


        } while (reponse == true);


        affichage(motAffiche, vie);
        rep = 0;
        for (int y = 0; y < strlen(mot.mot); y++) {
            if (mot.mot[y] == motAffiche[y]) {
                rep++;
            }
        }

        if (rep == strlen(mot.mot)) {
            reponseTrouve = true;
            printf("bravo vous avez trouve !\n");
            printf("il vous restait %d vie(s).", vie);
            break;
        }

    } while (vie > 0);


    return 0;
};