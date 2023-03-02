// Created on iPad.
#include <cstdio>

#define ElemType int

void BInsertSort(ElemType A[], int n){
    int i, j, low, high, mid;
    for (i=2;i<=n;i++){                     // 依次将A[2]~A[n]插入前面的已排序序列
        A[0] = A[i];                        // 将A[i]暂存到A[0]
        low = 1;
        high = i-1;                         // 设置折半查找的范围
        while(low<=high){                   // 折半查找，默认递增有序
            mid = low + (high - low) / 2;   // 取中间点
            if(A[mid]>A[0]){
                high = mid-1;               // 查找左半子表
            } else {
                low = mid+1;                // 查找右半子表
            }
        }
        for(j=i-1;j>=high+1;--j)
            A[j+1]=A[j];                    // 统一后移元素，空出插入位置
        A[high+1] = A[0];                   // 插入
    }
}

void TestModule() {
    ElemType list[] = {0, 38, 65, 97, 76, 13, 27, 49};
    BInsertSort(list,7);
    for (int i = 1; i < 7; i++) {
        printf("%d,", list[i]);
    }
}