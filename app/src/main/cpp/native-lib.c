#include <allegro5/allegro5.h>

int main(int argc, char **argv) {
    al_init();
    ALLEGRO_DISPLAY *display = al_create_display(0, 0);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1 / 60.0);
    int redraw = 1;
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    while (1) {
        if (redraw) {
            al_clear_to_color(al_map_rgb_f(0, al_get_time() - (int) (al_get_time()), 1));
            al_flip_display();
            redraw = 0;
        }
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = 1;
        }
    }
    return 0;
}