//
// Created by Guillaume dse on 21/02/2022.
//

#include "main.h"

/*
int main(){
    Mot mot;
    int vie, nombreDeVie, postition;
    jeu(vie, mot, nombreDeVie, postition);
    return 0;
}



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
#define LARGEUR 600
#define HAUTEUR 400

int main(){

    bool end = false;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event;
    // Initialisations
    assert(al_init());
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_primitives_addon());
    // Créations
    display = al_create_display(LARGEUR, HAUTEUR);
    assert(display != NULL);
    timer = al_create_timer(1.0 / 60.0);
    queue = al_create_event_queue();
    assert(queue != NULL);
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    Rect r1;
    r1.x = LARGEUR/2;
    r1.y = HAUTEUR/2;
    r1.color = al_map_rgb(255, 0, 0);
    r1.vitesse = 3;
    r1.h=30;
    r1.w=40;
    al_clear_to_color(al_map_rgb(21, 222, 250));
    al_draw_filled_rectangle(r1.x, r1.y, r1.w, r1.y, r1.color);
    al_flip_display();

    while(!end){
        printf("Debut boucle\n");
        al_wait_for_event(queue, &event);
        printf("Evenement pioche : %d\n", event.type);

        switch (event.type) {
            case ALLEGRO_EVENT_KEY_UP: {
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE: {
                        end = true;
                        break;
                    }

                }
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER: {
                r1.x = r1.x + r1.vitesse;
                if (r1.x + LARGEUR /2 > LARGEUR) {
                    r1.vitesse = -1;
                } else if (r1.x < 0) {
                    r1.vitesse = 1;
                }
                break;
            }
        }
        al_clear_to_color(al_map_rgb(21, 222, 250));
        al_draw_filled_rectangle(r1.x, r1.y, r1.w, r1.y, r1.color);
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);

    return 0;
};