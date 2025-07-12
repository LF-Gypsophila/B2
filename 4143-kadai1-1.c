#include <stdio.h>
int main(){
    int i , x , y ;
    for ( i = 5 ; i >= 1 ; i-- ){
        x = 2 * i - 1 ;
        for( y = 1 ; y <= x ; y += 2 ){
        printf( "%d + %d = %d\n" , x , y , x+y );
    }
        printf("---------------------\n");
    }
    return 0;
}