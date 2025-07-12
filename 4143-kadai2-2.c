#include <stdio.h>

int f(int a); //プロト宣言

int main(){
    int a;
    printf("自然数aを入力してください > ");
    scanf("%d",&a);

    if (1 <= a && a <= 10){
        printf("%d! = %d\n",a,f(a));
        main(); //始めに戻る
    }
    else{
        printf("10以下の自然数を入力してください\n");
    }
    return 0;
}

int f(int a){ //階乗の関数
    if (a == 0){
        return 1;
    }
    else{
        return a * f(a-1);
    }
}
