#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int estTriee( size_t len , int tab[ len ] ) ; 


void fusionTriee( size_t len1 , int tab1[ len1 ] , 
                    int len2 , int tab2[ len2 ] , 
                    int tab_target[ len1 + len2 ] ) ;


