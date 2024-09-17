#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "supp_liste.h"


int estTriee( size_t len , int tab[ len ] ){
    for ( int i = 0 ; i < len ; i++ ){
        int elem = tab[ i ] ;
        for ( int j = i + 1 ; j < len ; j++ ){
            if ( tab [ j ] < elem ){
                return 0 ; 
            }
        }
    }
    return 1 ;
}

/*

Partition (T , g , d)

Résultat : L’indice i de pivot correctement placé dans le tableau\

Effet de bord Les éléments de T entre les indices :
    ▶ g et i − 1 sont tous inférieurs à pivot.
    ▶ i + 1 et d sont tous supérieurs à pivot.


i = g
while i < d
    if T [i + 1] ≤ T [g]
        i =i +1
    else
        Échanger T [d] et T [i + 1]
        d =d −1
Échanger T [g ] et T [i]
return i

*/

void quicksort( int A[] , int len ){
    if (len < 2){
         return;
    }
    
    int pivot = A[len / 2];
    
    int i, j;
    for (i = 0, j = len - 1; ; i++, j--) {
        while (A[i] < pivot){
            i++;
        }
        while (A[j] > pivot){
            j--;
        };

    if (i >= j) 
        break;

    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}

void fusionTriee( size_t len1 , int tab1[ len1 ] , int len2 , int tab2[ len2 ] , int tab_target[ len1 + len2 ] ) {
    // On mets tous les elts de tab1 et de tab2 dans tab_target, puis on trie le tout

    // Fusion
    for ( int i = 0 ; i < len1 ; i++ ){
        tab_target[ i ] = tab1[ i ] ;
    }
    int k = len1 ;
    for ( int i = 0 ; i < len2 ; i++ ){
        tab_target[ k ] = tab2[ i ] ;
        k++ ;
    }

    // Trie de la liste


}


int main (){
    int k ;
    int dim ;
    printf("Saisissez la taille du tableau : \n");
    scanf("%d", &dim );
    int* tab = malloc( sizeof( dim * sizeof( int ) ) ) ;
    for ( int i = 0 ; i < dim ; i++ ){
        printf(" Saisissez l'elt d'indice %d : \n", i );
        scanf("%d", &k ); 
        tab[ i ] = k ;
   } 

   for ( int i = 0 ; i < dim ; i++ ){
        printf( "ELT NUMÉRO %d : %d\n", i , *( tab + i ) );
   }
   quicksort( tab , dim ) ;


   printf("APRÈS TRIE :\n");
   for ( int i = 0 ; i < dim ; i++ ){
        printf( "ELT NUMÉRO %d : %d\n", i , *( tab + i ) );
   }

   free( tab ) ;
   return 0 ;
}