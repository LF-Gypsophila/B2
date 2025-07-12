#include <stdio.h>

typedef struct point{
    int x; // x座標
    int y; // y座標
}POINT;

POINT movePPoint(POINT *p1, int dx, int dy){
    p1->x = p1->x + dx;
    p1->y = p1->y + dy;
    return *p1;  // POINT型を返す
}

int main(void){
    POINT pt1; // 移動後の座標
    POINT pt2; // 移動前の座標
    int dx, dy;

    printf("> (x1, y1) ");
    scanf("%d %d", &pt1.x, &pt1.y); // pt1 を入力

    printf("> (dx, dy) ");
    while (scanf("%d %d", &dx, &dy) != EOF){
        pt2 = pt1;
        movePPoint(&pt1, dx, dy);
        printf("Original:(%d, %d), Shift:(%d, %d), Result:(%d, %d).\n",
               pt2.x, pt2.y, dx, dy, pt1.x, pt1.y);
        // printf("Originalは新しく更新されました");
        printf("> (dx, dy) ");
    }

    return 0;
}
