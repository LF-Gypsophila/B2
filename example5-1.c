#include <stdio.h>
#include <math.h>

struct point {
    int x; // x座標
    int y; // y座標
};

int main(void) {
    struct point p1;
    double d;

    printf("> (x, y) ");
    scanf("%d %d", &p1.x, &p1.y);

    d = sqrt(p1.x * p1.x + p1.y * p1.y);
    printf("Distance between (%d, %d) and (0, 0) is %.2f.\n", p1.x, p1.y, d);

    return 0;
}
