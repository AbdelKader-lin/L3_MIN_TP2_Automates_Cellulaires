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
    printf("\n");
    free( nouv_tab );
}


int *next_state(size_t an, int a[an]){
    int *tab = malloc( an * sizeof( int ) ) ;
    if ( !tab ){
        exit(-1) ;
    }

    for ( int i = 0 ; i < an ; i++ ){

        // Triplet Actuel
        triplet MonTriplet ; //= malloc( sizeof ( triplet ) );
        // Voisine gauche
        if ( i == 0 ){
            MonTriplet.voisine_gauche = 0 ;
        } else{
            MonTriplet.voisine_gauche = a[ i - 1 ] ;
        }
        // Cell centrale
        MonTriplet.cell = a[ i ] ;
        // Voisine droite
        if ( i == an - 1 ){
            MonTriplet.voisine_droite = 0 ;
        } else{
            MonTriplet.voisine_droite = a[ i + 1 ] ;
        }

        if( ( MonTriplet.voisine_gauche == 1 && ( MonTriplet.voisine_droite + MonTriplet.cell != 0 ) ) || ( MonTriplet.voisine_droite + MonTriplet.cell + MonTriplet.voisine_gauche == 0 )) {
            tab[ i ] = 0 ;
        } else {
            tab[ i ] = 1 ;
        }

    }
    return tab;
}

void rule30(size_t an, int a[an], int nsteps){
    for ( int i = 1 ; i <= nsteps ; i++ ){
        printf("RULE 30, ITER. N %d\n",i);
        int *t = malloc( an * sizeof( int ) ) ;
        t = next_state( an , a ) ;
        print_state( an ,  t ) ;
        for (int j = 0; j < an; j++) {
            a[j] = t[j];
        }
        free(t);
    }
}

void Entier_En_Binaire( uint8_t x , int* x_binaire ){
    // bit de poids faible à gauche
    int taille = 8 ;
    for( int i = 0 ; i <= taille - 1 ; i++ ){
        *(x_binaire + i  ) = x % ( uint8_t )2 ;
        x = x / ( uint8_t )2;
    }
}

int *next_state_with_rule(size_t an, int a[an] , uint8_t rule ){

    // La règle en binaire
    int* rule_binaire = malloc( 8 * sizeof( int ) ) ;
    if ( !rule_binaire ){
        printf("Erreur dans l'allocation dynamique de rule_binaire !\n");
        exit(-1) ;
    }
    Entier_En_Binaire( rule , rule_binaire ) ;

    int *tab = malloc( an * sizeof( int ) ) ;
    if ( !tab ){
        printf("Erreur dans l'allocation dynamique de tab !\n");
        exit(-1) ;
    }

    for ( int i = 0 ; i < an ; i++ ){

        // Triplet ACtuel
        triplet MonTriplet ; //= malloc( sizeof ( triplet ) );
        // Voisine gauche
        if ( i == 0 ){
            MonTriplet.voisine_gauche = 0 ;
        } else{
            MonTriplet.voisine_gauche = a[ i - 1 ] ;
        }
        // Cell centrale
        MonTriplet.cell = a[ i ] ;
        // Voisine droite
        if ( i == an - 1 ){
            MonTriplet.voisine_droite = 0 ;
        } else{
            MonTriplet.voisine_droite = a[ i + 1 ] ;
        }

        //if( ( MonTriplet.voisine_gauche == 1 && ( MonTriplet.voisine_droite + MonTriplet.cell != 0 ) ) || ( MonTriplet.voisine_droite + MonTriplet.cell + MonTriplet.voisine_gauche == 0 )) {
        tab[ i ] = rule_binaire[ MonTriplet.voisine_gauche*4 + MonTriplet.cell*2 + MonTriplet.voisine_droite ] == 0 ;


    }
    free( rule_binaire ) ;
    return tab;
}


void one_d_ca(uint8_t rule, size_t an, int a[an], int nsteps){
    for ( int i = 1 ; i <= nsteps ; i++ ){
        printf("RULE 30, ITER. N %d\n",i);
        int *t = malloc( an * sizeof( int ) ) ;
        t = next_state_with_rule( an , a , rule ) ;
        print_state( an ,  t ) ;
        for (int j = 0; j < an; j++) {
            a[j] = t[j];
        }
        free(t);
    }
}


void utilisateur_q4(){
    int k ;

    // Taille du tableau initial formé de 1 et de 0
    int dim ;
    do{
        uint8_t rule_utilisateur ;
        printf("Entrez une règle de votre choix :\n");
        scanf("%hhu",&rule_utilisateur);

        printf("Saisissez la taille du tableau : \n");
        scanf("%d", &dim );
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
        
        int nsteps = 100;
        one_d_ca( rule_utilisateur , dim , tab , nsteps );
        } while ( 1 ) ;
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
   
   int nsteps = 100;
   rule30(dim, tab, nsteps);
   
   //free(tab);
   return 1 ;
}