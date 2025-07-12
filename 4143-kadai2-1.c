#include <stdio.h>
#include <math.h>

double zettaiti(double a); //プロト宣言

int main(){
    double a, b, c, s, area;
    scanf("%lf %lf %lf", &a,&b,&c); //doubleは%lfでよむ

    if (zettaiti(b - c)<a && a<b+c ){ //∣b−c∣<a<b+cより三角不等式が成立するなら>0
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c)); //ヘロンの公式

        if ( a==b && b==c ){
            printf("%lf\n",area);
        }
        else{
            main();//始めに戻る
        }

    }
    else{
        printf ("三角形を形成できません");
        main();//始めに戻る
    }

    return 0;

} //main関数はgccが呼び出す zettaiti関数はmainが呼び出す


double zettaiti ( double a ) { //自作の絶対値関数
    if ( a > 0 ) {
        return a;
    }
    else {
        return -a;
    }
}



