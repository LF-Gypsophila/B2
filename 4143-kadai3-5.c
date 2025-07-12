#include <stdio.h>
#include <math.h> //fabsとpowを定義する
#include <stdlib.h> //absを定義する

double integral_riron(int a, int b);
int rn(int x);
double integral_simyu(int a, int b, int c);

int main(){
    int a, b, c;
    printf("積分区間の下限値aを入力してください > ");
    scanf("%d",&a);
    printf("積分区間の上限値bを入力してください > ");
    scanf("%d",&b);
    if ( a >= b){
        printf("下限値をa上限値をbとして入力してください\n");
        return 0;
    }
    printf("乱数を発生する回数を入力してください(1000万回以下) > ");
    scanf("%d",&c);
    if( c < 0 || c > 10000000 ){
        printf("1000万以下の自然数を入力してください\n");
        return 0;
    }
    printf("--- 計算結果 ---\n");
    printf("積分値(理論値) = %f\n",integral_riron(a, b));
    printf("積分値(シミュレーション値) = %f\n",integral_simyu(a ,b ,c));
    printf("積分値の誤差 = %f\n", fabs(integral_riron(a, b) - integral_simyu(a, b, c)));
    return 0; // ↑fabsはdoubleの絶対値を求める
}

double integral_riron(int a, int b){
    double rironti;
    rironti = (pow(b,3) - pow(a,3)) / 3.0;
    return rironti;
}

int rn(int r){
    int A = 48109;
    int B = 2531011;
    int M = 32768;
    return (A * r + B) % M;
}

double integral_simyu(int a, int b, int c){
    int x = 1, y = 2, h, result = 0; // xがxの値 yがyの値 hがhight xとyの初期値は違う
    if ( abs(b) > abs(a) ){ //absはintの絶対値を求める
        h = pow(b,2);
    }
    else{
        h = pow(a,2);
    } //高さの高い方をhとしてとる
    for(int i = 0; i < c; i++){ // <=とするとc+1回ループする
        x = rn (x); //乱数の発生
        y = rn (y); //乱数の発生
        double x1 = a + (double)x * (b-a) / 32767.0; //発生した乱数をa-bに収める xをdouble型に変換
        double y1 = (double)y * h / 32767.0; //発生した乱数を0-hに収める yもdouble型に変換
        if (y1 <= pow(x1,2)){
            result ++;
        }
    }
    double simyuti = (double)(b-a) * h * result /c; //(double)とすることで切り捨て除算を防ぐ
    return simyuti;
}