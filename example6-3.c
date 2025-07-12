#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 19;
    int *p1; //変数のアドレスを格納
    int *p2; //動的にメモリを確保する

    p1 = &x; //p1にxのアドレスを代入
    p2 = malloc(sizeof(int)); //整数1つのメモリを動的に確保.先頭アドレスをp2に代入
    if (p2 == NULL) { //mallocが失敗した場合=メモリを確保できなかったとき
        fprintf(stderr, "Memory Shortage\n"); //メッセージを表示
        exit(1); //プログラムを終了
    }

    *p2 = 77; //p2が指すメモリに77を代入

    printf("HENSU \t VALUE \t INDIRECT\n");
    //HENSU = 変数名 VALUE = アドレス INDIRECT = 中身の値
    printf("p1 \t %10p \t %d\n", p1, *p1);
    printf("p2 \t %10p \t %d\n", p2, *p2);

    free(p2); //mallocで確保したメモリを解放.メモリリークを防ぐ
    return 0; //正常に終了した0を返す
}
