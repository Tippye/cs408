//
// Created by 渠继旺 on 2022/10/11.
//
/**定义模块**/
#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    // 队首指针，队尾指针
    int front, rear;
} SqQueue;

bool InitQueue(SqQueue &Q);

bool DestoryQueue(SqQueue &Q);

// 入队，使元素x成为新的队尾
bool EnQueue(SqQueue &Q, ElemType x);

// 出队，删除队头元素并返回
bool DeQueue(SqQueue &Q, ElemType &x);

// 读取队头元素
bool GetHead(SqQueue Q, ElemType &x);

// 判断是否为空
bool QueueEmpty(SqQueue Q);
/**定义模块**/
