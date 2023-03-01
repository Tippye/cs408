//
// Created by 渠继旺 on 2023/1/8.
// TODO: 测试未通过，考研此部分不做要求，以后再补
//

#include <cstdlib>
#include <cstdio>
#include <cmath>

#define ElemType int

typedef struct AVLNode {
    // 前半部分和三叉链表一样
    ElemType data;
    struct AVLNode *lchild, *rchild, *parent;

    // 新增平衡因子
    int balance;
} AVLNode, *AVLTree;

void PassBalance(AVLTree &pNode, AVLNode *cNode);

void RotateLeft(AVLNode *p);

void RotateRight(AVLNode *p);

//bool AVLInsert(AVLTree &T, ElemType key) {
//    if (T == NULL) {
//        T = (AVLNode *) malloc(sizeof(AVLNode));
//        T->data = key;
//        T->balance = 0;
//        T->lchild = T->rchild = T->parent = NULL;
//        return true;
//    }
//    AVLNode *cur = T;
//    AVLNode *parent = NULL;
//    while (cur != NULL) {
//        if (key == cur->data)
//            return false;
//        parent = cur;
//        cur = key < cur->data ? cur->lchild : cur->rchild;
//    }
//    cur = (AVLNode *) malloc(sizeof(AVLNode));
//    cur->data = key;
//    cur->parent = parent;
//    cur->lchild = cur->rchild = NULL;
//    cur->balance = 0;
//    if (key < parent->data)
//        parent->lchild = cur;
//    else
//        parent->rchild = cur;
//
//    bool tall = true;
//
//    while (parent != NULL && tall) {
//        if (cur == parent->lchild) {
//            switch (parent->balance) {
//                case 1:
//                    tall = false;
//                case 0:
//                    parent->balance--;
//                    break;
//                case -1:
//                    AVLNode *grandparent = parent->parent;
//                    grandparent->lchild = parent->rchild;
//                    parent->rchild = grandparent;
//                    grandparent->parent->lchild == grandparent
//                    ? grandparent->parent->lchild = parent
//                    : grandparent->parent->rchild = parent;
//
//
//                    tall = false;
//                    break;
//            }
//        } else {
//            switch (parent->balance) {
//                case -1:
//                    tall = false;
//                case 0:
//                    parent->balance--;
//                    break;
//                case 1:
////                    RightBalance(T, parent);
//                    tall = false;
//                    break;
//            }
//        }
//        cur = parent;
//        parent = cur->parent;
//    }
//
//    return true;
//}

bool AVLInsert_recursion(AVLTree &T, ElemType key) {
    if (T == NULL) {
        T = (AVLNode *) malloc(sizeof(AVLNode));
        T->data = key;
        T->lchild = T->rchild = T->parent = NULL;
        T->balance = 0;
        return true;
    }
    if (key == T->data)
        return false;
//    AVLNode *child = key < T->data ? T->lchild : T->rchild;
//    bool res = AVLInsert_recursion(child, key);
//    if (res) {
//        child->parent = T;
//        PassBalance(T, child);
//    }
    bool res;
    if (key < T->data) {
        res = AVLInsert_recursion(T->lchild, key);
        if (res) {
            T->lchild->parent = T;
            PassBalance(T, T->lchild);
        }
    } else {
        res = AVLInsert_recursion(T->rchild, key);
        if (res) {
            T->rchild->parent = T;
            PassBalance(T, T->rchild);
        }
    }
    return res;
}

void PassBalance(AVLTree &pNode, AVLNode *cNode) {
    if (pNode == NULL)
        return;
    AVLNode *gpNode = pNode->parent;
    bool tall = true;
    if (pNode->lchild == cNode)
        // XL
        switch (pNode->balance) {
            case 1:
                // 新插入结点的父结点(pNode)的右子树本来就比左子树高1，现在在左子树新插入一个，左右高度相同，不会造成上层结点平衡因子改变，所以使用tall变量停止递归
                // 这里没有break是因为还需要修改pNode的平衡因子(balance)，需要执行case 0部分的代码
                tall = false;
            case 0:
                // pNode的左右子树原本高度相同，新插入一个后可能造成上层结点的平衡因子超出范围，所以修改pNode结点的平衡因子后还需要递归平衡上层结点
                pNode->balance--;
                break;
            case -1:
                // pNode的左子树原本比右子树高1，再往左子树上添加一个新结点肯定会造成不平衡，所以需要进行旋转修改

                // LL平衡和RL平衡都需要先进行右旋
                //LL
                RotateRight(cNode);

                // LL平衡不需要进行左旋，RL平衡需要进行左旋
                //RL
                if (gpNode != NULL && gpNode->rchild == pNode)
                    RotateLeft(cNode);
                break;
        }
    else
        // XR
        switch (pNode->balance) {
            case -1:
                // tall理由同上
                tall = false;
            case 0:
                pNode->balance++;
                break;
            case 1:
                //RR
                RotateLeft(cNode->rchild);

                //LR
                if (gpNode != NULL && gpNode->lchild == pNode)
                    RotateRight(cNode);
                break;
        }
    if (tall)
        PassBalance(gpNode, pNode);
}


void RotateLeft(AVLNode *p) {
    if (p->parent == NULL) return;
    AVLNode *f = p->parent,
            *gf = f->parent;

    f->lchild = p->rchild;
    p->rchild = f;
    p->parent = gf;
    f->parent = p;
    if (gf != NULL)
        gf->lchild == f ? gf->lchild = p : gf->rchild = p;
}

void RotateRight(AVLNode *p) {
    if (p->parent == NULL) return;
    AVLNode *f = p->parent,
            *gf = f->parent;

    f->rchild = p->lchild;
    p->lchild = f;
    p->parent = gf;
    f->parent = p;
    if (gf != NULL)
        gf->lchild == f ? gf->lchild = p : gf->rchild = p;
}

int GetHeight(AVLTree T) {
    if (T == NULL)
        return 0;
    int lheight, rheight;
    lheight = GetHeight(T->lchild);
    rheight = GetHeight(T->rchild);
    return (lheight < rheight ? rheight : lheight) + 1;
}

void PrintTree(AVLTree T) {
    if (T == NULL)
        return;
    printf("%d\t", T->data);
    PrintTree(T->lchild);
    PrintTree(T->rchild);
}

void TestModule() {
    int nums[] = {15, 3, 7, 10, 9, 8};
    int len = sizeof(nums) / sizeof(nums[0]);
    AVLTree root = NULL;
    for (int i = 0; i < len; ++i) {
        AVLInsert_recursion(root, nums[i]);
    }
    int h = GetHeight(root);
    printf("AVL树的高度为：%d\n", h);
    PrintTree(root);
    printf("\n");
}