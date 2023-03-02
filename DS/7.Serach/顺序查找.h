//
// Created by 渠继旺 on 2022/12/20.
//
#include "../2.LinearList/2.1顺序表定义.c"

int SeqSearch(SeqList sl, ElemType key) {
    sl.data[0] = key;               // 哨兵

    int i = sl.length;
    while (sl.data[i] != key)       // 从后向前找
        i--;
    return i;                       // 查找成功返回元素下标，如果找不到i会等于"哨兵"的值
}