//
// Created by Guillaume dse on 21/02/2022.
//

#include "main.h"

int main(){
    Mot mot;
    int vie, nombreDeVie, postition;
    jeu(vie, mot, nombreDeVie, postition);
    return 0;
}
/*


int main () {
    assert(al_init());
    ALLEGRO_DISPLAY *display = NULL;
    display = al_create_display(800, 600);
    assert(display != NULL);
    al_set_window_title(display, "Tu es nulle looser !");
    al_clear_to_color(al_map_rgb(0, 0,  255));
    al_flip_display();
    al_draw_filled_rectangle(200, 200, 300, 300, al_map_rgb(255, 0, 0));
    al_flip_display();
    al_rest(5);
    al_destroy_display(display);

    return 0;
}
*/