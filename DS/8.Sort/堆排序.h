//
// Created by 渠继旺 on 2023/3/1.
//
#include <cstdio>
#include "utils.h"

#define ElemType int

/**
 * 将元素k为根的子树进行调整
 *
 * @param A
 * @param k
 * @param len
 */
void HeadAdjust(ElemType A[], int k, int len){
    A[0] = A[k];
    for (int i = 2*k; i < len; i*=2) {      // 沿key较大的子结点向下筛选
        if(i<len&&A[i]<A[i+1])
            i++;                            // 取key较大的子结点的下标
        if(A[0]>=A[i]) break;               // 筛选结束
        else{
            A[k] = A[i];                    // 将A[i]调整到双亲结点上
            k = i;                          // 修改k的值以便继续向下筛选
        }
    }
    A[k] = A[0];                            // 被筛选结点放入最终位置
}

void BuildMaxHeap(ElemType A[], int len){
    for (int i = len/2; i > 0; --i)     // 从i=[n/2]~1，反复调整堆
        HeadAdjust(A, i, len);
}


void HeapSort(ElemType A[], int len){
    BuildMaxHeap(A, len);                   // 构建大顶堆
    for (int i = len; i > 1; --i) {         // n-1趟的交换和建堆过程
        swap(A[i],A[1]);             // 输出堆顶元素（交换堆顶堆底元素）
        HeadAdjust(A, 1, i - 1);    // 调整，把剩余的i-1个元素整理成堆
    }
}

int TestModule() {
    ElemType list[] = {0,38,65,22,76,13,27,49};
    HeapSort(list,7);
    for (int i=1;i<7;i++){
        printf("%d,",list[i]);
    }
    return 0;
}