//
// Created by 渠继旺 on 2023/3/1.
//
#include <cstdio>
#include "utils.h"

#define ElemType int

void BubbleSort(ElemType A[], int n) {
    bool flag;                                  // 用来记录这一趟有没有更改元素位置
    for (int i = 0; i < n - 1; ++i) {
        flag = false;
        for (int j = n - 1; j > i; j--) {       // 一趟冒泡过程
            if (A[j - 1] > A[j]) {              // 如果是逆序
                swap(A[j - 1], A[j]);    // 交换两个数的位置
                flag = true;
            }
        }
//        for (int j = 0; j < n; ++j) {           // 可以解开注释看到每一趟后的结果
//            printf("%d, ",A[j]);
//        }
//        printf("\n");
        if (!flag) return;                      // 如果没有发生交换就说明排序完成
    }
}

void TestModule() {
    ElemType list[] = {0,38,65,22,76,13,27,49};
    BubbleSort(list,7);
    for (int i=1;i<7;i++){
        printf("%d,",list[i]);
    }
}