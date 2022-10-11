#include <cstdio>
#include <cstdlib>

/**定义模块**/
#define MaxSize 50

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkStack;

// 初始化一个空栈 S
bool InitStack(LinkStack &S);

// 判断栈 S 是否为空
bool Empty(LinkStack S);

// 向栈 S 中加入元素 e 使其成为新栈顶
bool Push(LinkStack &S, ElemType e);

// 推出栈顶元素并用 e 返回
bool Pop(LinkStack &S, ElemType &e);

// 读取栈顶元素并用 e 返回，只读，不会改变栈
bool GetPop(LinkStack S, ElemType &e);

// 销毁栈并释放内存
bool DestroyStack(LinkStack &S);
/**定义模块**/

/**实现模块**/
bool InitStack(LinkStack &S) {
    // 初始化栈顶指针
    S = (LNode *) malloc(sizeof(LNode));
    if (S == NULL)
        return false;
    S->next = NULL;
    return true;
}

bool Empty(LinkStack S) {
    return (S->next == NULL);
}

bool Push(LinkStack &S, ElemType e) {
    // 入栈不需要检查
    LNode *n = (LNode *) malloc(sizeof(LNode));
    if (n == NULL)
        return false;
    n->data = e;
    n->next = S->next;
    S->next = n;
    return true;
}

bool Pop(LinkStack &S, ElemType &e) {
    if (S->next == NULL)
        return false;
    LNode *n = (LNode *) malloc(sizeof(LNode));
    n = S->next;
    e = n->data;
    S->next = n->next;
    free(n);
    return true;
}

bool GetPop(LinkStack S, ElemType &e) {
    if (S == NULL)
        return false;
    e = S->next->data;
    return true;
}
/**实现模块**/

/**测试模块**/

//打印整个栈
void PrintStack(LinkStack LS) {
    printf("从栈顶元素开始，栈如下：\n");
    int i = 0;
    int x;
    LNode *p = LS->next;
    while (p != NULL) {//注意判空的条件
        printf("S[%d]=%d\n", i, p->data);
        p = p->next;
        i++;
    }
    printf("栈打印完毕\n");
}

void testLinkStack() {
    printf("开始测试\n");
    LinkStack S;
    InitStack(S);
    printf("测试第一个栈\n");
    if (Push(S, 1)) {
        printf("入栈成功啦！\n");
    } else {
        printf("入栈失败了\n");
    }
    if (Push(S, 2)) {
        printf("入栈又成功啦！\n");
    } else {
        printf("入栈又失败了\n");
    }
    PrintStack(S);
    int x;
    if (Pop(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }

    PrintStack(S);
    int x1;
    if (GetPop(S, x1)) {
        printf("读取栈顶元素成功了，栈顶元素为：%d\n", x1);
    } else {
        printf("读取栈顶元素失败，再检查一下吧！\n");
    }

    if (Pop(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }
    if (Pop(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }

    printf("测试完毕了！\n");
}

/**测试模块**/
int main() {
    testLinkStack();
    return 0;
}