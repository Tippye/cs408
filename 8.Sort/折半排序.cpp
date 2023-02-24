// Created on iPad.
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

void BInsertSort(ElemType A[], int n){
    int i, j, low, high, mid;
    for (i=2;i<=n;i++){
        A[0] = A[i];
        low = 1;
        high = i-1;
        while(low<=high){
            mid = low + (high - low) / 2;
            if(A[mid]>A[0]){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        for(j=i-1;j>=high+1;--j)
            A[j+1]=A[j];
        A[high+1] = A[0];
        for (int k=0;k<n;++k)
            printf("%d\t",A[k]);
        printf("\n");
    }
}

int main() {
    ElemType list[] = {49,38,65,97,76,13,27,49};
    BInsertSort(list,8);
    for (int i=0;i<8;i++){
        printf("%d,",list[i]);
    }
    return 0;
}