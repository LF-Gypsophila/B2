#include <stdio.h>

typedef struct point{
    double x; //x座標 後に2で割るので少数となるようdouble
    double y; //y座標 同上
}POINT;

POINT getmiddlepoint(POINT p1, POINT p2){
    POINT p3;
    p3.x = (p1.x + p2.x)/2.0; //少数を明示するために2ではなく2.0
    p3.y = (p1.y + p2.y)/2.0; //同上
    return p3;
} //入力された2点の中点を求めるプログラム

int main(void){
    POINT pt1, pt2, mid; //pt1.2は入力する2つの座標
    printf("1つ目の座標(x1, y1) > ");
    scanf("%lf %lf", &pt1.x, &pt1.y); //doubleなので%lf
    printf("2つ目の座標(x2, y2) > ");
    scanf("%lf %lf", &pt2.x, &pt2.y); //同上

    mid = getmiddlepoint(pt1, pt2);
    printf("Midpoint between (%.2lf,%.2lf) and (%.2lf,%.2lf) is (%.2lf,%.2lf).\n" 
        ,pt1.x, pt1.y, pt2.x, pt2.y, mid.x, mid.y); //.000が続くのは冗長なので小数点2桁に丸めた
}