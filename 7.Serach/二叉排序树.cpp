//
// Created by 渠继旺 on 2023/1/3.
//
#include "../5.Tree/2.2链式树.cpp"

// 在二叉排序树查找值为key的结点
BiNode *BSTSearch(BiTree T, int key) {
    while (T != nullptr && key != T->data.value) {  // 值等于key就会跳过循环内的操作直接返回对应结点
        if (key < T->data.value)                    // 要搜索的值比当前结点的值小，指针变成左子结点
            T = T->lchild;
        else                                        // 要搜索的值比当前结点的值大，指针变成右子结点
            T = T->rchild;
    }

    return T;
}

// 在二叉排序树查找值为key的结点（递归实现）
BiNode *BSTSearch_recursion(BiTree T, int key) {
    if (T == nullptr)                                   // 二叉排序树中没有对应的值最后会变成空指针
        return NULL;
    if (key == T->data.value)                           // 找到对应值为key的结点，返回当前结点
        return T;
    if (key < T->data.value)                            // 要搜索的值比当前结点的值小，搜索左子结点
        return BSTSearch_recursion(T->lchild, key);
    return BSTSearch_recursion(T->rchild, key);     // 要搜索的值比当前结点的值大，搜索右子结点
}

// 向二叉排序树T中插入key
int BSTInsert(BiTree &T, int key) {
    if (T == NULL) {
        T = (BiTree) malloc(sizeof(BiNode));     // 如果结点为空就新建一个结点
        T->data = {key};
        T->lchild = T->rchild = NULL;
        return 1;
    }
    if (key == T->data.value)                          // 如果存在一个一样的结点就跳过
        return 0;
    if (key < T->data.value)                           // 如果要插入的值key比当前结点的值小就插入左子结点
        return BSTInsert(T->lchild, key);
    return BSTInsert(T->rchild, key);               // 如果要插入的值key比当前结点的值大就插入右子结点
}

// 在二叉排序树中删除值为key的结点
BiNode *BSTDelete(BiTree &T, int key) {
    if (T == NULL)                                              // 没有要被删除的结点
        return NULL;
    if (key == T->data.value) {                                 // 找到要被删除的结点
        BiNode *biNode = T;                                         // biNode用来存放要被删除的结点
        if (T->lchild == NULL)                                      // 左子树为空就把当前结点变成右子结点
            T = T->rchild;
        else if (T->rchild == NULL)                                 // 右子树为空就把当前结点变成左子结点
            T = T->lchild;
        else {                                                      // 左右子树都不为空就把右子树的最小结点放到当前结点位置，删除右子树最小结点
            BiNode *low = T;                                            // low用来存放右子树最小结点
            while (low->lchild != NULL)                                 // 右子树左下角为最小结点
                low = low->lchild;
            T = BSTDelete(low, low->data.value);                // 删除右子树最小结点，并将当前位置变为右子树最小结点
            T->lchild = biNode->lchild;                                 // 当前结点的左右子树指针修改为原结点指针
            T->rchild = biNode->rchild;
        }
        return biNode;
    }
    if (key < T->data.value)                                    // 要删除的值比当前结点值小，去左子树找
        return BSTDelete(T->lchild, key);
    return BSTDelete(T->rchild, key);                       // 要删除的值比当前结点值大，去右子树找
}

void CreatBST(BiTree &T, int arr[], int n) {
    T = NULL;
    for (int i = 0; i < n; ++i)
        BSTInsert(T, arr[i]);
}













