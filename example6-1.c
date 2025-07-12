#include <stdio.h>

typedef struct point{
    int x; //x座標
    int y; //y座標
}POINT;

POINT movepoint(POINT p1, int dx, int dy){
    POINT p2;
    p2.x = p1.x + dx;
    p2.y = p1.y + dy;
    return p2;
} //入力された点を移動させるプログラム

int main(void){
    POINT pt1; //移動前の座標
    POINT pt2; //移動後の座標
    int dx, dy;

    printf("移動前の座標(x1, y1) > ");
    scanf("%d %d", &pt1.x, &pt1.y);

    printf("移動量(dx, dy) > ");
    while(scanf("%d %d", &dx, &dy) != EOF){
        pt2 = movepoint(pt1, dx, dy);
        printf("Original:(%d,%d), Shift:(%d,%d), Result:(%d,%d)\n",pt1.x, pt1.y, dx, dy, pt2.x, pt2.y);
        pt1 = pt2;
        printf("移動前の座標が更新されました:(%d,%d)\n",pt1.x,pt1.y);
        printf("移動量(dx, dy) > ");
    }
    return 0;
}