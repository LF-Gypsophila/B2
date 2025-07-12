#include <stdio.h>

void pinc(int *x, int d){
    printf("仮引数 x : %p, *x(加算前) : %d\n", x, *x);
    *x = (*x) + d;
    printf("*x(加算後) x + d = : %d\n", *x);
}

int main(void){
    int x, d;
    printf("xを入力してください > ");
    scanf("%d", &x);
    printf("dを入力してください > ");
    scanf("%d", &d);
    printf("実引数 x : %p, x : %d\n", &x, x);
    pinc(&x, d);
    return 0;
}
