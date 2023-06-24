//
// Created by 渠继旺 on 2022/11/9.
//
#include <cstdio>

/**定义模块**/
#define SIZE 100
#define ElemType int

//集合元素数组（双亲指针数组）
ElemType UFSets[SIZE];

void Initial(ElemType S[]);

void Union(ElemType S[], ElemType Root1, ElemType Root2);

int Find(ElemType S[], ElemType x);
/**定义模块**/

/**实现模块**/
void Initial(ElemType S[]) {
    for (int i = 0; i < SIZE; ++i) {
        S[i] = -1;
    }
}

void Union(ElemType S[], ElemType Root1, ElemType Root2) {
    //要求Root1和Root2是不同的，而且表示子集合的名字
    if (Root1 == Root2) return;
    // 将根Root2连接到另一个根Root1下面
    S[Root2] = Root1;
}

void BetterUnion(ElemType S[], ElemType Root1, ElemType Root2) {
    // 优化合并算法

    //要求Root1和Root2是不同的，而且表示子集合的名字
    if (Root1 == Root2) return;

    // Root2的结点数更少，这里用根结点值的绝对值表示集合内结点数量，如-6表示集合内有6个结点
    if (S[Root2] > S[Root1]) {
        S[Root1] += S[Root2];   // 把结点数加一块
        S[Root2] = Root1;       // 小树合并到大树
    } else {
        S[Root2] += S[Root1];   // 把结点加一块
        S[Root1] = Root2;       // 小树合并到大树
    }
}

int Find(ElemType S[], ElemType x) {
    // 根的值小于0
    while (S[x] >= 0)
        x = S[x];
    return x;
}
/**实现模块**/