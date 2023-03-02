//
// Created by 渠继旺 on 2023/1/27.
//
#include <cstdio>
#include <cstdlib>

// M阶B树
#define M 5

struct ElemType {
    int value;
};


typedef struct BNode {
    int key_num;                // 当前结点内关键字的个数
    ElemType data[M];           // 存放关键字，最多M个
    struct BNode *child[M + 1];   // 存放子树，最多M+1个
    struct BNode *parent;       // 存放父结点
} BNode, *BTree;

//初始化
void InitBTree(BTree &root) {
    root = (BNode *) malloc(sizeof(BNode));

    for (int i = 0; i < M; ++i) {
        root->data[i] = *(ElemType *) malloc(sizeof(ElemType));
        root->child[i] = NULL;
    }
    // 子树指针要比关键字多一个
    root->child[M] = NULL;
    root->parent = NULL;
}

// B树查找结果
typedef struct {
    bool type;      // 查找成功/失败
    BTree node;     // 查找到所在的结点
    int i;          // 目标元素在结点中的位置
} Result;

// 在p结点内查找key的位置
int search(BTree p, int key) {
    int i = 1;
    while (i <= p->key_num && key > p->data[i].value)
        i++;
    return i;
}

// 在B树中查找目标关键字的位置
Result *SearchBTree(BTree tree, int key) {
    auto *result = (Result *) malloc(sizeof(Result));
    result->type = false;
    int i = 0;
    BTree p = tree;
    BTree q = NULL;
    while (p != NULL && !result->type) {
        i = search(p, key);
        if (i <= p->key_num && p->data[i].value == key) {
            result->node = p;
            result->type = true;
            result->i = i;
            return result;
        } else {
            q = p;
            p = p->child[i - 1];
        }
    }

    // 到这里就表示查找失败
    result->node = q;
    result->i = i;
    return result;
}

void NewRoot(BTree &tree, BNode *p, int key, BNode *ap) {
    InitBTree(tree);
    tree->key_num++;
    tree->child[0] = p;
    tree->child[1] = ap;
    tree->data[0] = {key};
    if (p != NULL) p->parent = tree;
    if (ap != NULL) ap->parent = tree;
}

void insert(BNode *node, int i, int key) {
    for (int j = node->key_num; j > i; --j) {
        node->data[j] = node->data[j - 1];
        node->child[j + 1] = node->child[j];
    }
    node->data[i] = {key};
    node->child[i] = NULL;
    node->key_num++;
}

bool InsertBTree(BTree *tree, int key) {
    Result *res = SearchBTree(*tree, key);
    if (res->type) return false;
    BNode *node = res->node;
    if (node == NULL) {
        NewRoot(node, NULL, key, NULL);
    } else {
        insert(node, res->i, key);
    }
}