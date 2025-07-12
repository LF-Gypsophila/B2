#include <stdio.h>
#include <stdlib.h>

struct cell{ //ノード(セル)の定義:生数値と次のノードへのポインタを持つ
    int value; //データ部分(整数値)(箱の中に入れる数字)
    struct cell *next; //次のノードへのポインタ(次の箱への住所)
};

void free_memory(struct cell *head){ //リストのメモリをすべて解放する
    struct cell *p, *q; //CLE上ではqをnewとして定義している
    for(p = head; p != NULL;){ //末尾(NULL)になるまで繰り返す
        q = p->next; //次のノードを保持
        free(p); //現在のノードを解放
        p = q; //次のノードに進む
    }
}

int main(void) {
    struct cell head = {0, NULL}; 
    //ダミーセル(空の先頭セル)の初期化:最初の挿入処理を特別扱いしない
    struct cell *p, *q; //ポインタ p:新しいノード用 q:末尾のノード追跡用
    int i;

    q = &head; //初期はダミーセルが末尾

    while (1) {
        //printf("整数を入力(0で終了):");
        scanf("%d", &i); //整数を入力
        if(i == 0)
            break; //0が入力されたら終了
        
        //新しいノードの動的確保
        p = (struct cell *)malloc(sizeof(struct cell));
        if (p == NULL) {
            fprintf(stderr, "メモリ不足です。\n");
            free_memory(head.next); //これまでに確保したメモリを解放
            //メモリが足りなくなったら今まで作った箱は全部片付けて終了
            exit(1); //異常時に終了する
        }

        p->value = i; //入力値をノードに保存(入力した値を箱に入れる)
        p->next = NULL; //次のノードはまだないのでNULL
        q->next = p; //これまでの末尾ノードのnextを新ノードに接続
        q = p; //新しいノードを末尾として記録(新しい箱が最後の箱になったのでqを更新)
    }

    //リストの出力ループ(ダミーセルの次から)
    for (p = head.next; p != NULL; p = p->next)
        printf("%d ", p->value); //各ノード値の表示
    printf("\n");
    free_memory(head.next); //確保したメモリをすべて解放
    return 0; //正常に終了
}

/*
[特徴]
ダミーセル(先頭に値を持たないノード)を用いている
リストの先頭は構造体の変数として直接持ち動的に確保していない
新規ノードは動的に確保し常にリストの末尾に追加
末尾のノードを追跡するためにポインタqを使う
メモリ解放は専用関数free_memoryによって行う

[利点]
ダミーセルのおかげで挿入処理がシンプルに:リストが空かどうかの分岐処理が不要
どの挿入もq->next=pで済むためコードが見やすい
メモリ不足時の処理で既に確保済みのメモリを一括解放してから終了しているため安全
free_memory関数を切り出し再利用やテストがしやすい

[短所]
先頭のダミーセル分メモリ使用(ただしほぼ微量)
リストの先頭が変数head固定なので別のリストを複数管理しにくい
構造体の中のvalueとnextの命名に一貫性がなく後のコードの可読性が若干落ちるかも(例:value vs data)
ダミーセルが初心者にはややわかりづらい場合がある
*/