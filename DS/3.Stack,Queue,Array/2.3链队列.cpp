//
// Created by 渠继旺 on 2022/10/11.
//
#include <cstdlib>

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    // 队列的头尾指针（尾指针方便尾部插入操作）
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
    // 两种方法都可以判断为空
//    return (Q.front == Q.rear);
    return Q.front->next == NULL;
}

bool EnQueue(LinkQueue &Q, ElemType x) {
    // 链表一般不会满，所以不需要考虑队列满了的情况
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    // 空队列不能删除
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p = Q.front;
    x = p->data;
    Q.front->next = p->next;
    // 如果删除的结点是最后一个结点，需要把尾指针指向头指针
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}