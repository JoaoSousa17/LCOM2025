#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int w, h; // width, height
} Plane;

typedef struct {
    int w, h, d;
} Volume;


void print_plane(Plane *p) {
    printf("W %d, H %d\n", p->w, p->h);
}
void print_volume(Volume *v) {
    printf("W %d, H %d, D %d\n", v->base.w, v->base.h, v->d);
}

Plane* create_plane() {
    Plane *plane = malloc(sizeof(Plane));
    plane->w = 4;
    plane->h = 2;
    return plane;
}

Plane *new_plane(int w, int h) {
    Plane *p = malloc(sizeof(Plane));
    p->w = w;
    p->h = h;
    return p;
}
Volume *new_volume(Plane *p, int d) {
    Volume *v = malloc(sizeof(Volume));
    v->base.w = p->w;
    v->base.h = p->h;
    v->d = d;
    return v;
}

void printBoard(){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

int main() {
    Plane p = {5, 2};
    Volume v = {p, 3};
    print_plane(&p);
    print_plane((Plane *) &v);
    print_volume(&v);

    printBoard();
    printf("Challenge 3\n");
    printBoard();

    Plane* plane = create_plane();
    printf("Width is %d\n", plane->w);
    return 0;
}