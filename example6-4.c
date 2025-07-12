#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    int i, num;
    double sum = 0.0;
    double *table; //入力された数値を格納する配列(動的確保)

    if(argc < 2){ //引数の個数が足りない場合
        fprintf(stderr, "Arguments are not specified.\n"); //エラーメッセージ
        exit(1); //プログラムを終了
    }

    num = argc - 1; //実際の数値の個数(最初の引数はプログラム名なので除く)
    table = malloc(sizeof(double) * num); //数値を格納するために必要なメモリ確保
    if(table == NULL){ //メモリの確保に失敗した場合
        fprintf(stderr, "Memory Shortage.\n"); //エラーメッセージ
        exit(1); //プログラムを終了
    }

    for(i = 0; i < num; i++){
        *(table + i) = atof(argv[i + 1]); //atof関数で文字列をdoubleに変換
    } //コマンドライン引数をdoubleに変換してtable配列に格納

    for(i = 0; i < num; i++){
        sum += table[i];
    }

    printf("Average of %d doubles is %.2f.\n", num, sum/num); //平均値を表示(小数点以下2桁まで)
    free(table); //動的に確保したメモリを解放
    return 0;
}

// 4143-kadai6-3は整数の平均しか取れないがこのプログラミングは少数も含めて平均を計算できる