#include <stdio.h>
#include <stdlib.h>

//makeArray関数の定義:引数を整数に変換して配列を作成し返す
int* makeArray(int argc, char* argv[]){
    int num = argc - 1; //実際の数値の個数(最初の引数はプログラム名なので除く)
    int *array = malloc(sizeof(int) * num); //num個分のメモリを動的確保
    if(array == NULL){ //メモリ確保に失敗した場合
        fprintf(stderr, "Memory Shortage.\n");
        exit(1); //エラーのためプログラムを終了
    }
    for(int i = 0; i < num; i++){ //引数を1つずつ整数に変換して配列に格納
        array[i] = atoi(argv[i + 1]); //argv[0]はプログラム名なのでスキップ
    }
    return array; //作成した配列を返す(ポインタ)
}

int main(int argc, char* argv[]) {
    if(argc < 2){ //argc==1の場合何も数値を入力していないので<2で調べる
        fprintf(stderr, "Arguments are not specified.\n");
        exit(1);
    }
    int num = argc - 1;
    int* table = makeArray(argc, argv);  //makeArray関数を使って引数から配列を生成
    double sum = 0.0; //平均計算のためdoubleで合計値を計算する
    for(int i = 0; i < num; i++){ //合計値を計算
        sum += table[i];
    }
    printf("Average of %d integers is %.2f.\n", num, sum / num);  //小数点2桁で表示
    free(table); //動的に確保したメモリを解放
    return 0;
}
