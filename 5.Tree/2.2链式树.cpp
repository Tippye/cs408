//
// Created by 渠继旺 on 2022/10/16.
//

#include <cstdio>
#include <cstdlib>

struct ElemType {
    int value;
};

typedef struct BiNode {
    ElemType data;
    // 二叉链表
    // 指向左孩子和右孩子
    struct BiNode *lchild, *rchild;

    // 三叉链表
    // 如果业务中经常需要查找父结点可以加上这个指针，不需要可以不用添加
    struct BiNode *parent;
} BiNode, *BiTree;

//初始化
void InitTree(BiTree &root) {
    root = (BiTree) malloc(sizeof(BiNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
}

//插入新结点
bool InsertNode(BiTree T, ElemType val) {
    BiNode *p = (BiNode *) malloc(sizeof(BiNode));
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    T->lchild = p;//作为左孩子
    return true;
}

int main() {
    BiTree root;
    InitTree(root);
    return 0;
}