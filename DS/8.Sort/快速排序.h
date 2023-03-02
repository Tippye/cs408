//
// Created by 渠继旺 on 2023/3/1.
//
#include <cstdio>

#define ElemType int

/**
 * 一趟划分
 *
 * @param A 被划分的数组
 * @param low 开始角标
 * @param high 结束角标
 * @return 存放枢轴的最终位置
 */
int Partition(ElemType A[], int low, int high) {
    ElemType pivot = A[low];                            // 把第一个元素设为枢轴(pivot)
    while (low < high) {
        while (low < high && A[high] >= pivot) --high;  // 移动右指针找比枢轴小的
        A[low] = A[high];                               // 找到的比枢轴小的元素移动到左端
        while (low < high && A[low] <= pivot) ++low;    // 移动左指针找比枢轴大的
        A[high] = A[low];                               // 找到的比枢轴大的元素移动到右端
    }
    A[low] = pivot;                                     // 枢轴放到最终位置
    return low;                                         // 返回枢轴的最终位置
}

void QuickSort(ElemType A[], int low, int high) {
    if (low < high) {                                   // 递归跳出的条件
        int pivotpos = Partition(A, low, high);         // 枢轴的位置
        QuickSort(A, low, pivotpos - 1);           // 对枢轴左边进行快排
        QuickSort(A, pivotpos + 1, high);           // 对枢轴右边进行快排
    }
}

void TestModule() {
    ElemType list[] = {0, 38, 65, 22, 76, 13, 27, 49};
    QuickSort(list, 1, 7);
    for (int i = 1; i < 7; i++) {
        printf("%d,", list[i]);
    }
}

