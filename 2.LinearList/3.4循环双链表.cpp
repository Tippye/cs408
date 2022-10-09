//
// Created by 渠继旺 on 2022/10/9.
//
#include <cstdlib>

/**定义模块**/
typedef int ElemType;

typedef struct RDNode {
    ElemType data;
    struct RDNode *prior, *next;
} RDNode, *RDLinklist;

bool InitList(RDLinklist &L);

bool Empty(RDLinklist L);

//判断是否为尾结点
bool isTail(RDLinklist L, RDNode *p);

bool InsertNextNode(RDNode *p, RDNode *s);
/**定义模块**/

/**实现模块**/
bool InitList(RDLinklist &L) {
    L = (RDNode *) malloc(sizeof(RDNode));
    if (L == NULL)
        return false;
    // 循环链表的尾结点指向头结点
    // 初始化时空链表的头结点也是尾结点
    L->prior = L;
    L->next = L;
    return true;
}

bool Empty(RDLinklist L) {
    return (L->next == L);
}

bool isTail(RDLinklist L, RDNode *p) {
    return (p->next == L);
}

bool InsertNextNode(RDNode *p, RDNode *s) {
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    s->prior = p;
}
/**实现模块**/
