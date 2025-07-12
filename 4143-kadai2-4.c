#include <stdio.h>

int Euclid(int m,int n); //プロト宣言

int main(){
    int m,n;
    while(1){ //1は常に真なので無限ループ(continueとbreakで制御)
        printf("2つの非負整数を入力してください > ");
        scanf("%d %d",&m,&n);
        if(n<0||m<0){ //orは||で表現する
            printf("負でない整数を入力してください\n");
            continue; //continueで再入力
        }
        else{
            printf("GCD = %d\n",Euclid(m,n));
            break; //ループを終了させる
        }
    }
    return 0;
}

int Euclid(int m,int n){
    // int temp;
    // if(m > n){ // 数値の大小を比較して効率を上げる
    //     temp = n;
    //     n = m;
    //     m = temp;
    // }
    if (n == 0){
        return m;
    }
    else {
        return Euclid(n,m%n);
    }
}