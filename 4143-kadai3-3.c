#include <stdio.h>

int rn(int x);
int myrn(int y);

int main(){
    int a;
    printf ("乱数を発生する回数を入力してください(1000万回以下) > ");
    scanf ("%d",&a);
    if( a > 10000000 || a < 0){
        printf ("1000万以下の自然数で入力してください\n");
    }
    else {
        myrn(a);
    }
    return 0;
}

int rn(int x){ //A,B,Mの定数は適当
    int A = 48109;
    int B = 2531011;
    int M = 32768;
    return (A * x + B) % M; //線形合同法
}

int myrn(int y){
    int r = 1;
    int list[10] = {0};
    int max = 0;
    for (int i = 1; i <= y; i++){
        r = rn(r);
        int result = r % 10; //listは0-9で指定する
        list[result]++; //その番号のlistの回数をカウントアップする
    }
    for (int i = 0; i < 10; i++) {
        if (list[i] > max) max = list[i]; //max関数の実装
    }
    for (int i = 0; i<10; i++){
        printf ("%5d:",i); //TOTALをprintしたときに幅を合わすため
        int s = list[i] * 20 / max; //正規化する
        for (int j = 1; j <= s; j++){
            printf("*");
        }
        for (int j = 1; j <= 20-s; j++){ //空白を綺麗に合わせる
            printf(" ");
        }
        printf("%8d",list[i]); 
        printf("\n");
    }
    printf("==================================\n");
    printf("TOTAL:                    %8d\n",y);
    return 0;
 }
