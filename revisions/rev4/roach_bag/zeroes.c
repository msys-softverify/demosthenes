/**
  * Demonstration of null pointer dereference tracking capabilities
  */

#include <stdlib.h>

typedef struct point_TAG {
    int x;
    int y;
    int color;
} point_t;

typedef enum { 
    RGB_BLACK = 0x000000, 
    RGB_RED=0xFF0000, 
    RGB_GREEN=0x00FF00, 
    RGB_BLUE=0x0000FF, 
    RGB_TURQUOISE = 0x40E0D0
} color_t; 

void move_up_and_paint_it_black(point_t* p) {
    p->y -= 100;
    if (p) {
        /* previously we unconditionally dereferenced 'p' and only now checked if it
         is not NULL. That is cerainly supspicious - either pointer may be NULL, so 
         we should have inserted check before dereference, or pointer is never NULL, so
         the check is redundant. */
        p->color = RGB_BLACK;
    }
}
/**
  * If all points have the same color, return freshly allocated point with
  * gemetric center coodrinates. Otherwise return NULL
  */
point_t* triangle_center(point_t* p1, point_t* p2, point_t* p3) {
    point_t* c;
    if ((p1->color != p2->color) || (p2->color != p3->color)) {
        return 0;
    }
    c = (point_t*)malloc(sizeof(point_t));
    if (c==0) {
        abort();
    }
    c->x = (p1->x + p2->x + p3->x)/3;
    c->y = (p1->y + p2->y + p3->y)/3;
    c->color = p1->color;

    return c;
}

void random_trials() {
    point_t* center;
    point_t p1 = { 0, 0, RGB_BLACK };
    point_t p2 = { 10, 0, RGB_BLACK };
    point_t p3 = { 0, 10, RGB_BLACK };

    /* with 1/2 probability, mutate one color */
    if (rand()>RAND_MAX/2) {
        p3.color = RGB_GREEN;
    }
    
    center = triangle_center(&p1, &p2, &p3);
    /* Here 'center' may be NULL so we have null pointer derefernce */
    center->color = RGB_TURQUOISE;

    free(center);
}

