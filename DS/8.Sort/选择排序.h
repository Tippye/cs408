//
// Created by 渠继旺 on 2023/3/1.
//
#include <cstdio>
#include "utils.h"

#define ElemType int

void SelectSort(ElemType A[], int n) {
    int min;                                        // 用来存放最小元素位置
    for (int i = 0; i < n - 1; ++i) {               // 一共进行n-1趟
        min = i;                                    // 记录最小元素位置
        for (int j = i + 1; j < n; ++j)             // 在A[i...n-1]中选择最小值
            if (A[j] < A[min]) min = j;             // 更新最小值位置
        if (min != i) swap(A[i], A[min]);    // 封装的swap()函数共移动元素3次
    }
}

void TestModule() {
    ElemType list[] = {0, 38, 65, 22, 76, 13, 27, 49};
    SelectSort(list, 7);
    for (int i = 1; i < 7; i++) {
        printf("%d,", list[i]);
    }
}
