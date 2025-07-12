#include <stdio.h>

int gcd(int m,int n);

int main(){
    int m, n;
    scanf("%d %d",&m,&n); //intは%dでよむ
    printf("%d\n",gcd(m,n)); //gcd関数を使って最大公約数をよみ出す
    return 0;
}

int gcd(int m,int n){
    int temp,i,result;
    if(n >= m){
        temp=n;
        n=m;
        m=temp;
    }
    i = 1; //resultは1で定義する必要はない
    while(i <= n){
        if(n%i == 0 && m%i == 0){
            result = i;
        }
        i = i + 1;
    }
    return result;
}