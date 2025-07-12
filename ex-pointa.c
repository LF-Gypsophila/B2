#include <stdio.h>

// ポインタとアドレス

// ポインタ : アドレスを保存する場所
// アドレス : その変数がメモリ上のどこに保存されているかの"場所"

void pointa() {
    int a = 10;
    int *p;         // int型のポインタ変数pを宣言
    p = &a;         // 変数aのアドレスをpに代入
    printf("変数aの値: %d\n", a);          // 10
    printf("変数aのアドレス: %p\n", &a);   // aのアドレス（例：0x7ffee7dbe4cc）
    printf("ポインタpの値: %p\n", p);      // aのアドレス（&aと同じ）
    printf("ポインタpが指す値: %d\n", *p); // 10（*pはaの値）
}

// より具体例で考えてみる
// 駅のロッカーに5kgの荷物を入れたとする
// 変数 : ロッカーの中に入っている荷物(データ)
// アドレス : ロッカーの番号
// ポインタ : 「○番のロッカー」と書いてあるメモ

void pointa2(){
    int nimotu = 5; // nimotu = 5kg の荷物
    int *memo = &nimotu; // &nimotu は荷物が入っているロッカー番号(アドレス)
    // memo はロッカー番号を書いたメモ(ポインタ)
    printf( "%d\n" , *memo ); // メモを使ってロッカーに行き荷物の重さを見る
}


// ポインタと配列

void pointa3() {
    int arr[3] = {10, 20, 30};
    int *p = arr;  // 配列名 arr は先頭要素のアドレスを表す
    printf("arr[0] = %d\n", arr[0]);   // 10
    printf("*p = %d\n", *p);           // 10
    printf("*(p + 1) = %d\n", *(p + 1)); // 20
}

int main(){
    printf("======Example======\n");
    pointa();
    printf("======Ex-Nimotu======\n");
    pointa2();
    printf("======Ex-ARR======\n");
    pointa3();
    return 0;
}