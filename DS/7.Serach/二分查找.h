//
// Created by 渠继旺 on 2022/12/20.
//
#include "../2.LinearList/2.1顺序表定义.h"

int BinarySearch(SeqList seqList, ElemType key) {
    int low = 0,                                // 左边界
    high = seqList.length - 1,              // 有边界
    mid;                                    // 中间

    while (low <= high) {
        mid = (low + high) >> 1;                // 相当于mid = (low+high)/2 取low与high的中间值
        if (seqList.data[mid] == key)
            return mid;
        if (seqList.data[mid] > key)
            high = mid - 1;                     // 查找左边
        else if (seqList.data[mid] < key)
            low = mid + 1;                      // 查找右边
    }

    return -1;
}