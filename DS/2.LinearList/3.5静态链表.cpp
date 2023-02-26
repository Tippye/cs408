//
// Created by 渠继旺 on 2022/10/9.
//
/**定义模块**/
#include <stdlib.h>
#include <stdlib.h>
#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data;
    int next;
} SLinkList[MaxSize];

//函数声明
bool InitList(SLinkList &L);

bool Empty(SLinkList L);

/**定义模块**/