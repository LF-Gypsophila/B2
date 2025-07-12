#include <stdio.h>
#include <math.h> 

typedef struct point{
    int x;
    int y;
}POINT;

void rotatePoint(POINT *p1, int dt){ 
    double rad = dt * M_PI / 180.0; //度で入力するのでラジアンに変換.doubleで計算するため180.0
    double cos_theta = cos(rad); 
    double sin_theta = sin(rad);

    int x = p1->x; //元のx座標を保持
    int y = p1->y; //元のy座標を保持

    //roundは小数点を四捨五入して整数に変換する

    p1->x = round(x * cos_theta - y * sin_theta); //関数内でp1->xやp1->yを更新した場合計算する処理と干渉する
    p1->y = round(x * sin_theta + y * cos_theta); //そのため上の2行で元の座標を保持するよう指示している
    //p1->x = round(p1->x * cos_theta - p1->y * sin_theta); ここでp1->xが更新される
    //p1->y = round(p1->x * sin_theta + p1->y * cos_theta); 更新されたp1->xを使用することになる
}

int main(){
    POINT pt1; //移動後の座標
    // POINT pt2; //移動前の座標
    int dt;

    printf("> (x1, y1) ");
    scanf("%d %d", &pt1.x, &pt1.y);

    printf("> (dt) ");
    while(scanf("%d",&dt) != EOF){
        // pt2 = pt1;
        rotatePoint(&pt1, dt);
        printf("(%d, %d)\n",pt1.x, pt1.y);
        printf("> (dt) ");
    }
    return 0;   
}
