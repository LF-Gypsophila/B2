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
    int r = 1, result = 1;
    int list[10] = {0};
    for (int i = 1; i <= y; i++){
        r = rn(r);
        result = r % 10; //mod10して+1したくなるけどlistは0-9で指定する
        list[result]++; //その番号のlistの回数をカウントアップする
    }
    for (int i = 1; i <= 10; i++){ //for文をi=0で書くか下のリストで揃える
        printf ("%2dが出た割合:%5.2f%%です\n",i,list[i-1]*100.0/y); //i-1してる理由
    } //%2dで2桁分確保して%5.2fで5桁のうち2桁を少数用に確保している
    return 0;
}