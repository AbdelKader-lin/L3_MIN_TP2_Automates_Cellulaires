#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "aut.h"



void print_state(size_t an, int a[an]){
    int tab[ an ] ;
    char *nouv_tab = malloc( an * sizeof( char ) ) ;
    for ( int i = 0 ; i < an ; i++ ){

        // Triplet ACtuel
        ptr_triplet MonTriplet = malloc( sizeof ( triplet ) );
        // Voisine gauche
        if ( i == 0 ){
            MonTriplet->voisine_gauche = 0 ;
        } else{
            MonTriplet->voisine_gauche = a[ i - 1 ] ;
        }
        // Cell centrale
        MonTriplet->cell = a[ i ] ;
        // Voisine droite
        if ( i == an - 1 ){
            MonTriplet->voisine_droite = 0 ;
        } else{
            MonTriplet->voisine_droite = a[ i + 1 ] ;
        }

        if( ( MonTriplet->voisine_gauche == 1 && ( MonTriplet->voisine_droite + MonTriplet->cell != 0 ) ) || ( MonTriplet->voisine_droite + MonTriplet->cell + MonTriplet->voisine_gauche == 0 )) {
            *( nouv_tab + i ) = ' '  ;
            tab[ i ] = 0 ;
        } else {
            *( nouv_tab + i ) = '*' ;
            tab[ i ] = 1 ;
        }

    }
    for ( int i = 0 ; i < an ; i++ ){
        printf("%c", *(nouv_tab + i ) );
    }
    free( nouv_tab );
}


int *next_state(size_t an, int a[an]){
    char *tab = malloc( an * sizeof( char ) ) ;
    for ( int i = 0 ; i < an ; i++ ){

        // Triplet ACtuel
        ptr_triplet MonTriplet = malloc( sizeof ( triplet ) );
        // Voisine gauche
        if ( i == 0 ){
            MonTriplet->voisine_gauche = 0 ;
        } else{
            MonTriplet->voisine_gauche = a[ i - 1 ] ;
        }
        // Cell centrale
        MonTriplet->cell = a[ i ] ;
        // Voisine droite
        if ( i == an - 1 ){
            MonTriplet->voisine_droite = 0 ;
        } else{
            MonTriplet->voisine_droite = a[ i + 1 ] ;
        }

        if( ( MonTriplet->voisine_gauche == 1 && ( MonTriplet->voisine_droite + MonTriplet->cell != 0 ) ) || ( MonTriplet->voisine_droite + MonTriplet->cell + MonTriplet->voisine_gauche == 0 )) {
            tab[ i ] = 0 ;
        } else {
            tab[ i ] = 1 ;
        }

    }
    return tab;
}

void rule30(size_t an, int a[an], int nsteps){
    int *t ;
    // = malloc( an * sizeof( int ) ) ;
    for ( int i = 1 ; i <= nsteps ; i++ ){
        t = next_state( an , a ) ;
        print_state( an ,  t ) ;
    }
}


int main(){
    int k ;
   int dim ;
   printf("Saisissez la taille du tableau : \n");
   scanf("%d", &dim );
   //int* tab = malloc( sizeof( dim * sizeof( int ) ) ) ;
   int tab[ dim ] ;
   for ( int i = 0 ; i < dim ; i++ ){
        do {
            printf(" Saisissez l'elt d'indice %d : \n", i );
            scanf("%d", &k );
        } while( k != 0 && k != 1 ); 
        tab[ i ] = k ;
   } 
   print_state( dim , tab );
   printf("\n");
   //free( tab );
   return 1 ;
}