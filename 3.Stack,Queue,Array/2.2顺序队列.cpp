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

/**实现模块**/
bool InitQueue(SqQueue &Q) {
    // 初始化时，队头队尾指针都指向0
    Q.rear = Q.front = 0;
    return true;
}

bool DestoryQueue(SqQueue &Q) {

}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool QueueEmpty(SqQueue Q) {
    return (Q.front == Q.rear);
}
/**实现模块**/

/**测试模块**/
void testQueue() {
    SqQueue Q;
    InitQueue(Q);
}