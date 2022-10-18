//
// Created by 渠继旺 on 2022/10/18.
//
#include <cstdio>

/**定义模块**/
struct ElemType {
    int value;
};

typedef struct ThreadNode {
    ElemType data;//数据域
    struct ThreadNode *lchild, *rchild;//左右孩子指针
    int ltag, rtag;//左右线索标志
} ThreadNode, *ThreadTree;
/**定义模块**/

/**实现模块**/
ThreadNode *pre = NULL;//全局变量用于暂存当前访问结点的前驱

void visit(ThreadNode *q) {
    if (q->lchild == NULL) {//左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {//建立前驱结点的后继线索
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

//中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

//创建中序线索化二叉树T
//这里的 T 不是引用是因为 T 的内容在函数中没有改变，只改变了内容所指向的地址的内容
void CreatInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {//非空二叉树才能线索化
        InThread(T);//中序线索二叉树
        if (pre->rchild == NULL) {
            pre->rtag = 1;//处理遍历的最后最后一个结点
        }
    }
}

////以上为中序线索二叉树的构建

//先序线索化，一边遍历一边线索化
void PreThread(ThreadTree T) {
    if (T != NULL) {
        visit(T);
        if (T->ltag == 0) {//lchild不是前驱线索
            // 这里如果不判断会进入死循环，因为刚刚线索化的左指针肯定不会NULL
            PreThread(T->lchild);
        }
        PreThread(T->rchild);
    }
}

//创建先序线索化二叉树T
void CreatPreThread(ThreadTree T) {
    pre == NULL;
    if (T != NULL) {
        PreThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;//处理遍历的最后一个结点
        }
    }
}

////以上为先序线索二叉树的构建


//后序线索二叉树
void PostThread(ThreadTree T) {
    if (T != NULL) {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}

//创建后序线索二叉树T
void CreatPostThread(ThreadTree T) {
    pre == NULL;
    if (T != NULL) {
        PostThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;//处理遍历的最后一个结点
        }
    }
}

////以上为后序线索二叉树的构建


//中序线索二叉树找中序后继
//找到以P为根的子树中，第一个被中序遍历的结点
ThreadNode *FirstNode(ThreadNode *p) {
    //循环找到最左下结点（不一定是叶结点）
    while (0 == p->ltag) {
        p = p->lchild;
    }
    return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p) {
    //在右子树中最左下结点
    if (0 == p->rtag)return FirstNode(p->rchild);
    else return p->rchild;
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法），空间复杂度为O(1)；
void InOrder(ThreadNode *T) {
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p)) {
        visit(p);
    }
}

//中序线索二叉树找中序前驱
//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *p) {
    //循环找到最右下结点（不一定是叶结点）
    while (0 == p->rtag) p = p->rchild;
    return p;
}

//在中序线索二叉树中找到结点p的前驱结点
ThreadNode *PreNode(ThreadNode *p) {
    //左下子树中最右结点
    if (0 == p->ltag)
        return LastNode(p->lchild);
    else
        return p->lchild;
}

//对中序线索二叉树进行逆向中序遍历
void RevInOrder(ThreadNode *T) {
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p)) {
        visit(p);
    }
}


/**实现模块**/


/**测试模块**/

void testModule() {
    printf("开始测试！\n");

    printf("结束测试！\n");
}

/**测试模块**/
int main() {
    testModule();
    return 0;
}