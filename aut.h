#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct t {
    int voisine_gauche ;
    int cell ;
    int voisine_droite ;
} triplet, *ptr_triplet ;



void print_state(size_t an, int a[an]);

int *next_state(size_t an, int a[an]);

void rule30(size_t an, int a[an], int nsteps); 

