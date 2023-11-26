//
// Created by Tippy on 2023/10/21.
//
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int M_Search(int A[], int B[], int L) {
        int s1, d1, m1, s2, d2, m2;
        s1 = 0;
        d1 = L - 1;
        s2 = 1;
        d2 = L - 1;
        while (s1 != d1 || s2 != d2) {
            m1 = (s1 + d1) / 2;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
            m2 = (s2 + d2) / 2;
            if (A[m1] == B[m2]) return A[m1];
            if (A[m1] < B[m2]) {
                s1 = m1 + (s1 + d1) % 2;        // 需要考虑元素个数奇偶,保持两个子数组元素个数相等,(s1+d1)%2为1时,说明元素个数为奇数,此时s1=m1+1,否则就是s1=m1
                d2 = m2;
            } else {
                d1 = m1;
                s2 = m2 + (s2 + d2) % 2;
            }
        }
        return A[s1] < B[s2] ? A[s1] : B[s2];   // 三元表达式, 与下面的if else等价
        // if (A[s1] < B[s2])
        //     return A[s1];
        // else
        //     return B[s2];
    }

    int M_Search1(int A[], int B[], int L) {
        // 次优解,时间复杂度O(L)
        // 使用两个指针(数组角标)分别指向A和B, 每次比较两个指针指向的数, 小的那个指针向后移动一位
        // 直到两个指针共移动了L次, 下一次移动的指针移动后指向的数就两个数组的中位数(因为题目要求是向上取整)
        int p1 = -1, p2 = -1;
        for (int i = 0; i < L; ++i) {
            if (B[p2 + 1] < A[p1 + 1])
                p2++;
            else
                p1++;
        }

        return B[p2 + 1] < A[p1 + 1] ? B[p2 + 1] : A[p1 + 1];
    }
};

int TestModule() {
    int A[] = {1, 3};
    int B[] = {2, 4};
    Solution s = Solution();
    cout << "中位数为：";
    cout << s.M_Search(A, B, 2);
    return 1;
}