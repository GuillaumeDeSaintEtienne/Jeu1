//
// Created by Guillaume dse on 21/02/2022.
//

#ifndef JEU1_MAIN_H
#define JEU1_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <string.h>

typedef struct {
    char mot[100];
    int nombreDeLettre;
}Mot;


int nombreAleatoireEntre(int min, int max);
void choixNombreDeVie(int* vie);
void choixDuJ(int* nombreDejoueur, int* choixJ);
void setup(int* nombreDejoueur, int* choixJ, int* vie);
char** choixDuMot();
void affichage(char* mot, int vie);
void jeu( int NombreDeVie, Mot mot,int vie,int position);


#endif //JEU1_MAIN_H
