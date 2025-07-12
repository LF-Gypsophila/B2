
 //argument:引数

#include <stdio.h>

int add(int a,int b); //プロト宣言

int main(){
    int x, y;
    printf("xを入力してください > ");
    scanf("%d",&x);
    printf("yを入力してください > ");
    scanf("%d",&y);
    printf("x + y = %d\n",add(x,y));
    return 0;
}

int add(int a, int b){
    return a + b;
}

 //仮引数がa,b
 //実引数がx,y