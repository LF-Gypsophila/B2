#include <stdio.h>
#include <stdlib.h>

typedef struct cell{ //CELL構造体:リストの1つの要素(箱と住所)を表す
    int data; //データ部分
    struct cell *next; //次のセルへのポインタ
}CELL;

CELL head; //リストの先頭を管理するためのダミーセル

void free_memory(struct cell *head){ //リストのメモリをすべて解放する
    struct cell *p, *q; //CLE上ではqをnewとして定義している
    for(p = head; p != NULL;){ //末尾(NULL)になるまで繰り返す
        q = p->next; //次のノードを保持
        free(p); //現在のノードを解放
        p = q; //次のノードに進む
    }
}

void InsertCell(int x){ //新しいセルを昇順に挿入する関数
    CELL *p, *new;
    for(p = &head; p->next != NULL; p = p->next){ //先頭から順に比較し同じ値があったらreturnで終了 
        if(p->next->data == x){ //重複チェック:リスト内にxと同じデータがあれば挿入しない 
            return; //重複しているので挿入しない
        }
    }
    new = (CELL *)malloc(sizeof(CELL)); //新しいセル用のメモリを確保
    if(new == NULL){
        fprintf(stderr, "メモリ確保に失敗しました。\n");
        free_memory(head.next); //確保したメモリを解放して終了
        exit(1); //終了
    }
    new->data = x; //データをセット
    for(p = &head; p->next != NULL; p = p->next){
        if(new->data < p->next->data){ //新しいセルの値が次のセルの値より小さい位置を探す
            new->next = p->next; //新セルをリストに挿入
            p->next = new;
            return; //挿入完了
        }
    }
    new->next = NULL; //ここまで来たらリストの最後に挿入
    p->next = new;
}

void PrintList(){ //リストの内容を表示する関数
    CELL *p;
    for(p = head.next; p != NULL; p = p->next){ //ダミーセルの次から順にリストを辿りながらデータを表示
        printf("%d ", p->data); //スペースで数字同士を区切る
    }
    printf("\n");
}

void DeleteCell(int x){ //1.入力された整数データを順序リストから削除する関数
    CELL *p, *del;
    for(p = &head; p->next != NULL; p = p->next){
        if(p->next->data == x){
            del = p->next;
            p->next = del->next;
            free(del);
            /* printf("%dを削除しました\n",x); */
            return;
        }
    }
    fprintf(stderr, "そのような数字はありません\n");
}

void DeletePositiveCell(){ //2.正のデータを削除する関数
    CELL *p = &head, *del;
    /* int found = 0; */
    while(p->next != NULL){
        if(p->next->data > 0){
            del = p->next;
            p->next = del->next;
            free(del);
            /* found = 1; */
        }else{
            p = p->next; //削除しないとき次に進める
        }
    }
    /* if(found){
        printf("正のデータを削除しました\n");
    }else{
        fprintf(stderr, "正のデータはリストにありませんでした\n");
    } */
}

void DeleteNegativeCell(){ // 3.負のデータを削除する関数
    CELL *p = &head, *del;
    /* int found = 0; */
    while(p->next != NULL){
        if(p->next->data < 0){
            del = p->next;
            p->next = del->next;
            free(del);
            /* found = 1; */
        }else{
            p = p->next; //削除しないとき次に進める
        }
    }
    /* if(found){
        printf("負のデータを削除しました\n");
    }else{
        fprintf(stderr, "負のデータはリストにありませんでした\n");
    } */
}

void DeleteEvenCell(){ // 4.偶数(0を除く)のデータを削除する関数
    CELL *p = &head, *del;
    /* int found = 0; */
    while(p->next != NULL){
        if(p->next->data %2 == 0 && p->next->data != 0){
            del = p->next;
            p->next = del->next;
            free(del);
            /* found = 1; */
        }else{
            p = p->next; //削除しないとき次に進める
        }
    }
    /* if(found){
        printf("偶数(0を除く)のデータを削除しました\n");
    }else{
        fprintf(stderr, "偶数(0を除く)のデータはリストにありませんでした\n");
    } */
}

int main(void){
    char cmd;
    int x;
    head.next = NULL;
    while(1){
        printf("コマンドを入力してください(i,d,p,n,e,s,x):");
        scanf(" %c", &cmd); //Enterの改行がcmdに入るのを防ぐためスペース
        if(cmd == 'i'){ //文字列なら""を使用するがcmdは1文字なので''を使用する
            printf("整数を入力してください:");
            scanf("%d", &x);
            InsertCell(x);
        }
        else if(cmd == 'd'){ //同文
            printf("整数を入力してください:");
            scanf("%d", &x);
            DeleteCell(x);
        }
        else if(cmd == 'p'){
            DeletePositiveCell();
        }
        else if(cmd == 'n'){
            DeleteNegativeCell();
        }
        else if(cmd == 'e'){
            DeleteEvenCell();
        }
        else if(cmd == 's'){
            PrintList();
        }
        else if(cmd == 'x'){
            printf("終了します\n");
            break; //whileループを終了
        }
        else{
            printf("コマンドが正しくありません\n");
        }
    }
    free_memory(head.next); //確保したメモリをすべて解放:例題7-1を参考
    return 0;
}

// /**/の箇所はUIを考慮した際に実装したかったがCLE上の課題の実行例に従いコメントアウトした部分である