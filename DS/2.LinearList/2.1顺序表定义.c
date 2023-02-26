//
// Created by Tippy on 2022/10/8.
//

// 定义线性表最大长度为20
#define MaxSize 20


// 设线性表的元素类型为ElemType
typedef int ElemType;

// 定义顺序表的结构
typedef struct {
    // 顺序表的当前长度(存了几个元素)
    int length;
    // 顺序表的元素
    ElemType data[MaxSize];
} SqList;


typedef struct {
    // 指向动态分配数组的指针
    ElemType *data;
    // 数组最大容量和当前个数
    int MAXSIZE, length;
} SeqList;

//// 初始化线性表
//void InitList(SqList *L) {
//    for (int i = 0; i < MaxSize; i++)
//        L->data[i] = 0;
//
//    L->length = 0;
//}

int main() {
    SqList L;
//    InitList(&L);

    // 下一行打断点进行调试可以看到线性表的状态
    return 0;
}