#include <stdio.h>

int Euclid(int m,int n); //プロト宣言

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    if(n<0||m<0){ // orは||で表現する
        printf("負でない整数を入力してください\n");
        return main();
    }
    else{
        printf("%d\n",Euclid(m,n));
    }
    return 0;
}

int Euclid(int m,int n){
    int temp,i,result;
    if(n > m){ // 数値の大小を比較して効率を上げる
        temp = m;
        m = n;
        n = temp;
    }
    while(n != 0){
        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}