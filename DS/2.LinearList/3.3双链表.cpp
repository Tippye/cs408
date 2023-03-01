//
// Created by 渠继旺 on 2022/10/9.
//

#include <cstdlib>
#include <cstdio>

/**定义模块**/
typedef int ElemType;

typedef struct DNode {
    // 数据域
    ElemType data;

    // 与单链表的差别就是新增了一个前驱结点
    // 前驱结点地址 后继结点地址
    struct DNode *prior, *next;
} DNode, *DLinklist;

// 函数声明
bool InitList(DLinklist &L);

bool Empty(DNode L);

// 指定结点的后插操作
bool InsertNextElem(DNode *p, DNode *s);

// 删除指定的结点
bool DeleteNode(DNode *q);
/**定义模块**/

/**实现模块**/
bool InitList(DLinklist &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

bool Empty(DNode L) {
    return (L.next == NULL);
}

bool InsertNextElem(DNode *p, DNode *s) {
    /**
     * p          q
     *      s
     */
    if (p == NULL || s == NULL)
        return false;
    // s的后继结点指向q，也就是p的后继结点
    s->next = p->next;
    // s的前驱结点指向p
    s->prior = p;
    // 把原来的p的后继结点和q的前驱结点指向s
    p->next = s;
    // 如果p是最后一个结点，这里的s->next也会是NULL
    // 因为上一步p的后继结点变成了s，s的后继结点变成了q，所以这里用s->next访问q
    // 也可以在上一行前面修改，需要写成 p->next->prior = s;
    if (s->next != NULL)
        s->next->prior = s;
    return true;
}

bool DeleteNode(DNode *q) {
    if (q == NULL) return false;
    /**
     * p   q    r
     */
    // q->prior就是p，把p的后继结点变成r，也就是q的后继结点
    q->prior->next = q->next;
    // q->next就是r，把r的前驱结点变成p，也就是q的前驱结点
    if (q->next != NULL)
        q->next->prior = q->prior;
    ElemType elemType = q->data;
    // 释放q的内存
    free(q);
    return true;
}
/**实现模块**/

/**测试模块**/
//Test
void TestPrint(bool test, char about[]) {
    if (test)
        printf("%s成功\n", about);
    else
        printf("%s失败\n", about);
}

void TestModule() {
    DLinklist L;
    TestPrint(InitList(L), "初始化");
    DNode temp1 = *(DNode *) malloc(sizeof(DNode));
    temp1.data = 12;
    TestPrint(InsertNextElem(L, &temp1), "插入一个结点");
    TestPrint(DeleteNode(&temp1),"删除一个结点");
}
