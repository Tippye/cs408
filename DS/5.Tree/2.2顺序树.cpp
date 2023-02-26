//
// Created by 渠继旺 on 2022/10/16.
//
#include <cstdio>

/**定义模块**/
#define MaxSize 100

typedef struct {
    int value;//结点中的数据元素
    bool isEmpty;
} TreeNode;

typedef struct {
    TreeNode treeNode[MaxSize];
    int n;
} SqTree;

void InitTree(SqTree &t) {
    for (int i = 0; i < MaxSize; i++) {
        t.treeNode[i].isEmpty = true;
    }
}

int main() {
    SqTree sqTree;
    InitTree(sqTree);
    return 0;
}