//
// Created by Tippy on 2023/10/15.
//
#include <cstdio>

class Solution {
public:
    static void Reverse(int R[], int left, int right){
        int i, temp;
        for (i = 0; i < (right - left + 1) / 2; i++) {
            temp = R[left + i];
            R[left + i] = R[right - i];
            R[right - i] = temp;
        }   // 循环体内在考试时可以使用swap(R[left+i],R[right-i])来代替
    }

    static void Reverse1(int R[], int left, int right) {
        // 与上面一样, 答案版本
        int i = left, j = right, temp;
        while (i < j) {
            temp = R[i];
            R[i] = R[j];
            R[j] = temp;        // 此处3行考试可以直接使用swap(R[i],R[j])或者 交换(R[i],R[j])

            i++;
            j--;
        }
    }

    static void leftShift(int R[], int n, int p) {
        // 最优解
        if (p>0 && p< n) {
            Reverse(R, 0, p - 1);   // 先把前p个倒过来
            Reverse(R, p, n - 1);   // 再把剩下的倒过来
            Reverse(R, 0, n - 1);   // 最后把整个倒过来
        }
    }

    static void leftShift1(int R[], int n, int p) {
        // 最优解(答案给的)
        if (p>0 && p< n) {
            Reverse(R, 0, n - 1);           // 先将整个数组倒过来, 时间复杂度O(n)
            Reverse(R, 0, n - p - 1);       // 再把前n-p-1项倒过来,前n-p-1项是原来数组p项到最后一项
            Reverse(R, n - p, n - 1);       // 把后p项倒过来, 这里对应原来数组的前p项
        }
    }

    static void leftShift2(int R[], int n, int p) {
        // 次优解
        // 把前p个放到temp数组中, 再把后n-p个往前移动, 最后把temp数组放到后面
        int temp[p], i;
        for (i = 0; i < p; ++i)
            temp[i] = R[i];
        for (i = p; i < n; ++i)
            R[i - p] = R[i];
        for (i = 0; i < p; i++)
            R[n - p + i] = temp[i];
    }
};

int TestModule() {
    int R[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution s;
    Solution::leftShift(R, 10, 3);
    for (int i: R) {
        printf("%d,", i);
    }
    return 0;
}