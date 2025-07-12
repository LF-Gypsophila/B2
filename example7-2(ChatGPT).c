#include <stdio.h>
#include <stdlib.h>


//単方向リストのノード構造体の定義
//Cell構造体はリストの1つの要素(ノード)を表す
//dataに整数データを保持しnextに次のノードへのポインタを持つ
typedef struct Cell {
    int data;
    struct Cell* next;
} Cell;

//リストの先頭を指すグローバルポインタ初期はNULL
Cell* head = NULL;


//InsertCell関数:昇順の順序リストに整数xを挿入する。
//既に同じ値が存在する場合は挿入しない(重複排除)
void InsertCell(int x) {
    //リストが空またはxが先頭ノードのデータより小さい場合は先頭に挿入検討
    if (head == NULL || x < head->data){
        if (head != NULL && head->data == x) return; //重複のチェック(先頭の値と同じなら挿入しない)
        //新ノードを作成し先頭に挿入
        Cell* newNode = (Cell*)malloc(sizeof(Cell));
        newNode->data = x;
        newNode->next = head;
        head = newNode;
        return;
    }

    //先頭以外の場所に挿入する場合
    Cell* cur = head;
    Cell* prev = NULL;

    //挿入位置を探す(cur->dataがx以上になる直前まで移動)
    while (cur != NULL && cur->data < x) {
        prev = cur;
        cur = cur->next;
    }

    //重複チェック:curがNULLでなくcur->data==xなら挿入しない
    if (cur != NULL && cur->data == x) return;

    //新ノードを作成してprevとcurの間に挿入
    Cell* newNode = (Cell*)malloc(sizeof(Cell));
    newNode->data = x;
    newNode->next = cur;
    prev->next = newNode;
}

//PrintList関数:リストの先頭から順にデータを表示する。
void PrintList() {
    Cell* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//メイン関数:キーボードから整数を繰り返し入力
//0が入力されたら入力終了としリストの内容を表示
int main(){
    int x;

    while (1) {
        //printf("整数を入力(0で終了):");
        scanf("%d", &x);
        if (x == 0) break; //0で入力終了
        InsertCell(x); //昇順で重複なく挿入
    }

    printf("リストの内容:");
    PrintList(); //リストの全データを表示

    // メモリ解放(確保したノードを順にfree)
    Cell* cur = head;
    while (cur != NULL) {
        Cell* tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    return 0;
}
