// Created on iPad.
#include <stdio.h>

#define ElemType int

void InsertSort(ElemType A[], int n){
    int num=0;
    int i, j;
    ElemType temp;
    for(i=1;i<=n;i++){                      // 循环无序列表
        if(A[i]<A[i-1]){                    // 如果这一个关键字比前边的小，就把它插入到前边
            temp = A[i];                    // 先把待插入的元素存放到0号位置
            for (j=i-1;temp<A[j];--j)       // 从i-1号位置往前找插入位置
                num++;
                printf("第%d次 ，比较%d和%d\n", num, temp, A[j]);
                A[j+1] = A[j];              // i-1号位置到插入位置之间的元素都往后移动一位
            A[j+1]=temp;                    // 把待插入元素插入到相应位置
        }
        num++;
        printf("第%d次，比较%d和%d\n", num, A[i], A[i - 1]);
    }
}

void TestModule() {
//    ElemType list[] = {0,38,65,22,76,13,27,49};
//    InsertSort(list,7);
//    for (int i=1;i<7;i++){
//        printf("%d,",list[i]);
//    }
    ElemType list[] = {0, 1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    InsertSort(list, 10);
    for (int i = 1; i < 10; i++) {
        printf("%d,", list[i]);
    }
}