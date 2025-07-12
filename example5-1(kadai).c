#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

int main() {
    point table[5][100]; // table[0] は未使用
    int n = 0;

    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
        table[1][n].x = x;
        table[1][n].y = y;
        n++;
    }

    printf("The points in I quadrant (RUQ):\n");
    for (int i = 0; i < n; i++) {
        x = table[1][i].x;
        y = table[1][i].y;
        if (x > 0 && y > 0) {
            printf("( %2d, %2d)\n", x, y);
        }
    }

    printf("The points in II quadrant (LUQ):\n");
    for (int i = 0; i < n; i++) {
        x = table[1][i].x;
        y = table[1][i].y;
        if (x < 0 && y > 0) {
            printf("( %2d, %2d)\n", x, y);
        }
    }

    printf("The points in III quadrant (LLQ):\n");
    for (int i = 0; i < n; i++) {
        x = table[1][i].x;
        y = table[1][i].y;
        if (x < 0 && y < 0) {
            printf("( %2d, %2d)\n", x, y);
        }
    }

    printf("The points in IV quadrant (RLQ):\n");
    for (int i = 0; i < n; i++) {
        x = table[1][i].x;
        y = table[1][i].y;
        if (x > 0 && y < 0) {
            printf("( %2d, %2d)\n", x, y);
        }
    }

    return 0;
}
