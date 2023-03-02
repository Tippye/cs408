//
// Created by 渠继旺 on 2023/3/2.
//
#include <cstdlib>
#include <cstdio>

#define ElemType int

void Merge(ElemType A[], int low, int mid, int high) {
    int n = high - low + 1;                                             // 通过low和high设置表长
    auto *B = (ElemType *) malloc((n - 1) * sizeof(ElemType));     // 新数组，用来存放A数组，A数组用来存放结果
    int i, j, k;                                                        // 三个指针，分别是左半数组，左半数组和A数组的指针
    for (k = low; k <= high; ++k)                                       // 把A数组放到B数组
        B[k] = A[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {     // i,j分别放到二分的左右数组的左边，k放到A数组的左边
        if (B[i] <= B[j])
            A[k] = B[i++];                                              // 如果左边数组的第i个值不比右边的大，就把左边数组的值放到A中，然后i往右移动一位，k会在for循环中右移
        else
            A[k] = B[j++];                                              // 如果左边数组的第i个值比右边的大，就把右边数组的值放到A中，然后j往右移动一位，k会在for循环中右移
    }

    // 运行到这里时一定是i大于mid或者j大于high，所以两个while只会有一个运行，因为是对半分的左右，所以一般也就循环一两次
    while (i <= mid) A[k++] = B[i++];                                   // j超过了high，所以i还没有到mid，就把左半都放到A中
    while (j <= high) A[k++] = B[j++];                                  // i超过了mid，所以j还没有到high，就把右半都放到A中
}

void MergeSort(ElemType A[], int low, int high) {
    if (low<high){
        int mid = (low+high)/2;                                         // 从中间划分左右两半
        MergeSort(A, low, mid);                                    // 递归划分左半
        MergeSort(A, mid + 1, high);                                // 递归划分右半
        Merge(A, low, mid, high);                                       // 合并两边，合并的时候会排序
    }
}

void TestModule() {
    ElemType list[] = {0, 38, 65, 22, 76, 13, 27, 49};
    MergeSort(list, 1, 7);
    for (int i = 1; i < 7; i++) {
        printf("%d,", list[i]);
    }
}