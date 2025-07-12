#include <stdio.h>

int rn(int x);

int main(){
    int r = 1; //初期値を1とする
    for (int i; i<10;i++){ //とりあえず10を持ってきてる
        r = rn(r); //xの値を上書きしてる
        printf("%d\n",r);
    }
    return 0;
}

int rn(int x){ //A,B,Mの定数は適当
    int A = 48109;
    int B = 2531011;
    int M = 32768;
    return (A * x + B) % M; //線形合同法
}