#include <stdio.h>
#include <stdlib.h>

//ノードの定義(連結リスト1の要素)
typedef struct Node{
    int data; //ノードが保持するデータ
    struct Node* next; //次のノードへのポインタ
}Node;

//ノードを末尾に追加する関数(入力された順=正順で追加)
void append(Node** head, Node** tail, int value){ //新しいノードを動的に作成(メモリ確保)
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("メモリ確保に失敗しました。\n");
        exit(1); //プログラムを異常終了
    }
    newNode->data = value; //ノードにデータを格納する
    newNode->next = NULL; //末尾に追加する:次はNULLにする

    if(*head == NULL){ //最初のノードの場合headもtailもこのノードに設定
        *head = newNode;
        *tail = newNode;
    }else{ //すでにリストが存在する場合現在の末尾(tail)のnextに新ノードを接続
        (*tail)->next = newNode;
        *tail = newNode; //tailを新しい末尾ノードに更新
    }
}

//リストの内を先頭から末尾まで表示する
void display(Node* head) {
    Node* current = head; //現在のノードをheadから始める
    while (current != NULL) {
        printf("%d ", current->data); //各ノードのデータを出力
        current = current->next; //次のノードに進む
    }
    printf("\n");
}

int main(){
    Node* head = NULL; //リストの先頭を指すポインタ(初期はNULL)
    Node* tail = NULL; //リストの末尾を指すポインタ(初期はNULL)
    int input; //入力値を格納するための変数

    printf("整数を入力してください(0で終了)\n");
    while(1){ //while(1){ は常に真=無限ループの処理:必ず0がいつかは入力される前提
        scanf("%d", &input);
        if(input == 0){
            break;
        } //入力が0なら終了
        append(&head, &tail, input); //連結リストに追加(正順)
    }

    printf("連結リストの内容(正順)\n");
    display(head); //リストの表示

    //使用したメモリをすべて解放(メモリリーク防止)
    Node* current = head;
    while (current != NULL) {
        Node* temp = current; //現在のノードを一時保存
        current = current->next; //次のノードに進む
        free(temp); //一時保存していたノードを解放
    }
    return 0; //正常終了
}

/*
[特徴]
ダミーセルを使わず空リストはhead==NULLで表現
headとtailの両方をポインタとして管理し末尾への追加を高速化
追加処理はappend関数に分けている
メモリ解放はmain内のループで行う
typedefを使って構造体の型名を簡潔にしている

[利点]
ダミーセルがなくてシンプル:リストが空かどうかはhead==NULLで判定できるので直感的
headとtailを両方管理しているのでリストの末尾への追加が高速で簡潔
append関数を使いコードのモジュール化が進んでいるため可読性が高い
typedefを使うことでコードが簡潔で読みやすい
新しいリストを作る場合はheadとtailを独立して管理できるため複数リストの管理に向く

[短所]
追加の際headとtailの両方のポインタを二重ポインタ(Node**)で渡す必要がありポインタの扱いがやや複雑
メモリ解放の処理がmainに直書きされており処理の分離・再利用が難しい
メモリ不足時は即座にexit(1)しており途中までのメモリ解放処理がない(実用上は許容されることも多い)
*/
