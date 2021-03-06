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


#define LARGEUR 800
#define HAUTEUR 600

typedef struct {
    char mot[100];
    int nombreDeLettre;
}Mot;

typedef struct {
    int vie;
    char nom[50];
}joueur;

typedef struct{
    int x,y,w,h;
    ALLEGRO_COLOR color;
    int vitesse;
}Rect;


int nombreAleatoireEntre(int min, int max);
void choixNombreDeVie(int* vie);
void choixDuJ(int* nombreDejoueur, int* choixJ);
void setup(int* nombreDejoueur, int* choixJ, int* vie);
char** choixDuMot();
void affichage(char* mot, int vie);
int jeu( int NombreDeVie, Mot mot,int vie,int position);
void menu2();
char menu1();

#endif //JEU1_MAIN_H
