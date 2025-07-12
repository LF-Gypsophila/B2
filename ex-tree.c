#include <stdio.h>

typedef char BITREE_TYPE; //格納データの型

struct node{
    BITREE_TYPE value; //ノードの値
    struct node *left; //左ノードのアドレス
    struct node *right; //右ノードのアドレス
};
typedef struct node BITREE_TYPE;


/* ノードBの 左ノードをC 右ノードをD */
BITREE_NODE b = {'B', NULL, NULL};
BITREE_NODE c = {'C', NULL, NULL};
BITREE_NODE d = {'D', NULL, NULL};
b.left = &c;
b.right = &d; 

