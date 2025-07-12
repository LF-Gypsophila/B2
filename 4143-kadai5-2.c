#include <stdio.h>
#include <math.h>

typedef struct point{
    int x;
    int y;
}POINT;

double distance (POINT p1){
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}

int main(void){
    POINT pt1;
    double d;
    printf("> (x, y) ");
    scanf("%d %d",&pt1.x, &pt1.y);
    d = distance(pt1);
    printf("Distance between (%d, %d) and (0, 0) is %.2f.\n",pt1.x, pt1.y, d);
    return 0;
}