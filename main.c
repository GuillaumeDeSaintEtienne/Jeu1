//
// Created by Guillaume dse on 21/02/2022.
//

#include "main.h"
/*
int main(){
    menu2();
    Mot mot;
    int vie, nombreDeVie, postition;
    jeu(vie, mot, nombreDeVie, postition);
    return 0;
}

*/


#include <stdio.h>

int main () {

    ALLEGRO_DISPLAY *display = NULL;
    assert(al_init());
    display = al_create_display(800, 600);
    assert(display != NULL);
    al_set_window_title(display, "JEU DE PENDU");
    al_init_primitives_addon();
    al_clear_to_color(al_map_rgb(255, 0,  0));
    al_draw_line(100, 550, 700, 550, al_map_rgb(0, 0, 0),5);
    al_draw_line(150, 550, 150, 50, al_map_rgb(0, 0, 0),5);
    al_draw_line(100, 50, 500, 50, al_map_rgb(0, 0, 0),5);
    al_draw_line(400, 50, 400, 70, al_map_rgb(0, 0, 0),5);
    al_draw_circle(400,100,30,al_map_rgb(0, 0, 0),5);
    al_draw_line(400, 130, 400, 350, al_map_rgb(0, 0, 0),5);
    al_draw_line(400, 350, 450, 450, al_map_rgb(0, 0, 0),5);
    al_draw_line(400, 350, 350, 450, al_map_rgb(0, 0, 0),5);
    al_draw_line(400, 180, 350, 150, al_map_rgb(0, 0, 0),5);
    al_draw_line(400, 180, 450, 150, al_map_rgb(0, 0, 0),5);
    al_flip_display();
    al_rest(5);
    al_destroy_display(display);
    return 0;
}