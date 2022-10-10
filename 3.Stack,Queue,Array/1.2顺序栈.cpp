/**定义模块**/
#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

// 初始化一个空栈 S
bool InitStack(SqStack &S);
// 判断栈 S 是否为空
bool Empty(SqStack S);
// 向栈 S 中加入元素 e 使其成为新栈顶
bool Push(SqStack &S, ElemType e);
// 推出栈顶元素并用 e 返回
bool Pop(SqStack &S, ElemType e);
// 读取栈顶元素并用 e 返回，只读，不会改变栈
bool GetPop(SqStack S,ElemType e);
// 销毁栈并释放内存
bool DestroyStack(SqStack &S);
/**定义模块**/

/**实现模块**/
bool InitStack(SqStack &S){
    // 初始化栈顶指针
    S.top = -1;
    return true;
}

bool Empty(SqStack S){
    return (S.top == -1);
}

bool Push(SqStack &S, ElemType e) {
    if(S.top==MaxSize-1)
        return false;
    // S.top = S.top + 1;
    // S.data[S.top] = e;
    // 上两行与下一行等价
    S.data[++S.top] = e;
    return true;
}

bool Pop(SqStack &S, ElemType &e) {
    if(S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

bool GetPop(SqStack S, ElemType &e) {
    if (S.top==-1)
        return false;
    e = S.data[S.top];
    return true;
}
/**实现模块**/

/**测试模块**/

//打印整个栈
void PrintStack(SqStack S) {
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top >= 0) {//注意判空的条件
        printf("S[%d]=%d\n", S.top, S.data[S.top]);
        S.top--;
    }
    printf("栈打印完毕\n");
}

void testStack() {
    printf("开始测试\n");
    SqStack S;
    printf("测试第一种初始化方式\n");
    InitStack(S);
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
}
/**测试模块**/
int main() {
    testStack();
    return 0;
}