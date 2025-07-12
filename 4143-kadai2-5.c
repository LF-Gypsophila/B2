#include <stdio.h>

void stars(int m);

int main(){
    int m;
    while(1){
        printf("記号を出力する数を入力してください > ");
        scanf("%d",&m);
        if(m < 0){
            printf("終了します\n");
            break;
        }
        else{
            printf("%d\n",stars(m));
            continue; //このcontinueはあってもなくても良い
        }
    }
    return 0;
}

void stars(int m){ //intにすると返り値が必要になり*の後ろに数字がついてしまう
    int i; 
    for (i = 0; i < m; i++){
        printf("*");
    }
}


//stars関数の呼び出しは単に出力処理.printfの中で呼ばない.下に修正.


#include <stdio.h>

void stars(int m);

int main(){
    int m;
    while(1){
        printf("記号を出力する数を入力してください > ");
        scanf("%d", &m);
        if (m < 0){
            printf("終了します\n");
            break;
        }
        else {
            stars(m);         // 修正：返り値はないのでprintfで囲まない
            printf("\n");     // 改行の追加（見やすさのため）
        }
    }
    return 0;
}

void stars(int m){
    for (int i = 0; i < m; i++){
        printf("*");
    }
}
