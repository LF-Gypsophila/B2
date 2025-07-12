#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x; //x座標
    int y; //y座標
} POINT;

// moveMPoint関数:p1の座標をdx,dyだけ移動させた新しいPOINTを動的に確保して返す
POINT* moveMPoint(POINT p1, int dx, int dy){
    POINT *newP; //新しい座標を格納するポインタ
    newP = malloc(sizeof(POINT)); //メモリを動的に確保
    if (newP == NULL){ //メモリ確保に失敗した場合
        fprintf(stderr, "Memory Shortage\n"); //エラーメッセージ
        exit(1); //プログラムを終了
    }
    newP->x = p1.x + dx; //新しいx座標
    newP->y = p1.y + dy; //新しいy座標
    return newP; //新たな座標を指すポインタを返す
}

int main(void){
    POINT pt1; //移動前の座標
    POINT *pt2; //移動後の座標(動的確保されたPOINTへのポインタ)
    int dx, dy; //移動量

    printf("> (x1, y1) ");
    scanf("%d %d", &pt1.x, &pt1.y); //初期座標pt1

    printf("> (dx, dy) ");
    while(scanf("%d %d", &dx, &dy) != EOF){ //EOF(Ctrl+D)までループ
        pt2 = moveMPoint(pt1, dx, dy);
        printf("Original:(%d,%d),Shift:(%d,%d),Result:(%d,%d).\n",
               pt1.x, pt1.y, dx, dy, pt2->x, pt2->y);
        pt1 = *pt2; //移動後の座標を次のループの基準にする(構造体をコピー)
        free(pt2); //動的に確保したメモリを解放してメモリリークを防ぐ
        printf("> (dx, dy) ");
    }
    return 0; //正常終了
}
