//
// Created by 渠继旺 on 2022/10/9.
//
#include <cstdlib>

/**定义模块**/
typedef int ElemType;

typedef struct RNode {
    ElemType data;
    struct RNode *next;
} RNode, *RLinklist;

bool InitList(RLinklist &L);

bool Empty(RLinklist L);

//判断是否为尾结点
bool isTail(RLinklist L, RNode *p);
/**定义模块**/

/**实现模块**/
bool InitList(RLinklist &L) {
    L = (RNode *) malloc(sizeof(RNode));
    if (L == NULL)
        return false;
    // 循环链表的尾结点指向头结点
    // 初始化时空链表的头结点也是尾结点
    L->next = L;
    return true;
}

bool Empty(RLinklist L) {
    return (L->next == L);
}

bool isTail(RLinklist L, RNode *p) {
    return (p->next == L);
}
/**实现模块**/
