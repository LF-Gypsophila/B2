#include <stdio.h>

int main(void){
    int x = 77;
    int y = 115;
    int tmp;
    int *p = &tmp;

    printf("%-7s %-13s %-5s\n", "HENSU", "ADDRESS", "VALUE");
    printf("%-7s %-13p %-5d\n", "x", &x, x);
    printf("%-7s %-13p %-5d\n", "y", &y, y);

    *p = x;
    x = y;
    y = *p;

    printf(" exchange x and y\n");
    printf("%-7s %-13p %-5d\n", "x", &x, x);
    printf("%-7s %-13p %-5d\n", "y", &y, y);
    return 0;
}