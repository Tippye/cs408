//
// Created by 渠继旺 on 2022/10/17.
//
#include <cstdio>
#include <cstdlib>
#include <queue>

/***定义模块*/
struct TElemType {
    int value;
};

typedef struct BiTNode {
    TElemType data;//数据域
    struct BiTNode *lchild, *rchild;//左右孩子指针
} BiTNode, *BiTree;
/**定义模块**/

/**实现模块**/
//初始化
void InitTree(BiTree &root) {
    root = (BiTree) malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
}

//插入新结点
bool InsertNode(BiTree &T, TElemType val) {
    BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    T->lchild = p;//作为左孩子
    return true;
}

//访问函数
void visit(BiTree T) {
    printf("%d", T->data.value);
}

//先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);//访问根节点
        PreOrder(T->lchild);//遍历左子树
        PreOrder(T->rchild);//遍历右子树
    }
}

//中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);//遍历左子树
        visit(T);//访问根节点
        InOrder(T->rchild);//遍历右子树
    }
}

//后序遍历
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);//遍历左子树
        PostOrder(T->rchild);//遍历右子树
        visit(T);//访问根节点
    }
}

//层序遍历
void LevelOrder(BiTree T) {
    // 头文件里引入了C++内置的队列
    std::queue<BiTree> Q;
    BiTree p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
}

/**实现模块**/

int main() {
    BiTree root;
    InitTree(root);

    return 0;
}