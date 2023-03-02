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

void TestModule() {
    SqStack S;
    InitStack(S);
}