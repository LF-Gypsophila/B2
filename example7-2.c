#include <stdio.h>
#include <stdlib.h>

//CELL構造体:リストの1つの要素(箱と住所)を表す
typedef struct cell {
    int data; //データ部分
    struct cell *next; //次のセルへのポインタ
}CELL;

CELL head; //リストの先頭を管理するためのダミーセル

//新しいセルを昇順に挿入する関数
void InsertCell(int x) {
    CELL *p, *new;

    //重複チェック:リスト内にxと同じデータがあれば挿入しない 
    //先頭から順に比較し同じ値があったらreturnで終了 
    for (p = &head; p->next != NULL; p = p->next) {
        if (p->next->data == x) {
            return; //重複しているので挿入しない
        }
    }

    //新しいセル用のメモリを確保
    new = (CELL *)malloc(sizeof(CELL));
    if (new == NULL) {
        //メモリ確保に失敗したらエラーメッセージを表示して終了
        printf("メモリ確保に失敗しました。\n");
        exit(1);
    }
    new->data = x; //データをセット

    //挿入位置を探索:昇順を維持するため
    //新しいセルの値が次のセルの値より小さい位置を探す
    for (p = &head; p->next != NULL; p = p->next) {
        if (new->data < p->next->data) {
            //新セルをリストに挿入
            new->next = p->next;
            p->next = new;
            return; //挿入完了
        }
    }

    //ここまで来たらリストの最後に挿入
    new->next = NULL;
    p->next = new;
}

//リストの内容を表示する関数
void PrintList() {
    CELL *p;
    //ダミーセルの次から順にリストを辿りながらデータを表示
    for (p = head.next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

int main(void) {
    int x;

    //ダミーセルの初期化(nextをNULLにして空リストを作る)
    head.next = NULL;

    while (1) {
        //ユーザに整数入力を促す
        //printf("整数を入力してください(0で終了)");
        scanf("%d", &x);

        //0が入力されたら終了
        if (x == 0) break;

        //入力値をリストに挿入
        InsertCell(x);
    }

    //リストの全要素を表示
    printf("リストの内容: ");
    PrintList();

    return 0;
}
