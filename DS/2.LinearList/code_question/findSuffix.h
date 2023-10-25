//
// Created by Tippy on 2023/10/25.
//
#include "linklist.h"

class Solution {
public:
    int listlen(ListNode *head) {   // 求链表长度
        int len = 0;
        while (head->next != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *findSuffix(ListNode *str1, ListNode *str2) {
        // 408答案
        // 时间复杂度O(m+n),空间复杂度O(1)
        int m, n;
        ListNode *p, *q;
        m = listlen(str1);      // 求str1的长度.O(m)
        n = listlen(str2);      // 求str2的长度.O(n)
        for (p = str1; m > n; m--)      // 使p指向的链表与q指向的链表长度相等.
            p = p->next;
        for (q = str2; m < n; n--)      // 使q指向的链表与p指向的链表长度相等.
            q = q->next;

        while (p->next != NULL && p->next != q->next) {     // 查找共同后缀的起始点
            p = p->next;
            q = q->next;
        }
        return p->next;             // 返回共同后缀的起始点
    }

    ListNode *findSuffix1(ListNode *str1, ListNode *str2){
        // LeetCode上看到的最优解
        // 设A的长度为a+c，B的长度为b+c；其中c为A、B的公共部分长度
        // 拼接AB、BA：A+B=a+c+b+c B+A=b+c+a+c；由于a+c+b=b+c+a，因此二者必定在c的起始点处相遇
        // 时间复杂度O(m+n),空间复杂度O(1)
        ListNode *p1=str1,*p2=str2;

        while (p1!=p2){
            p1=p1==nullptr?str2:p1->next;
            p2=p2==nullptr?str1:p2->next;
        }
        return p1;
    }

    ListNode *reverse(ListNode *l) {    // 反转链表
        ListNode *nl = (ListNode *) malloc(sizeof(ListNode));
        ListNode *p = l;
        while (p->next) {
            ListNode *n = (ListNode *) malloc(sizeof(ListNode));
            n->val = p->next->val;
            n->next = nl->next;
            nl->next = n;
            p = p->next;
        }
        return nl;
    }

    ListNode *findSuffix2(ListNode *str1, ListNode *str2) {
        // 将两个链表反转存放在p1和p2(题目未要求空间复杂度)
        // 从头开始遍历两个链表, 直到遇到下一个结点值不相等的结点, 此时的结点就是两个链表的第一个公共结点,但由于不是原来链表的结点,所以不能直接返回
        // 将p和p1同步后移(因为p1是反转后的链表,所以p1到结尾处时p会到第一个公共结点处)直到p1为空,返回p
        // 时间复杂度O(m+n),空间复杂度O(m+n)
        ListNode *p1 = reverse(str1),
                *p2 = reverse(str2),
                *p = str1;
        while (p1->next && p2->next && p1->next->val == p2->next->val) {
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            p = p->next;
            p1 = p1->next;
        }
        return p;
    }
};


int TestModule() {
    ListNode *str1 = new ListNode(),
            *str2 = new ListNode(),
            *cur1 = str1,
            *cur2 = str2;
    for (auto &i: {4, 1, 8, 4, 5}) {
        cur1->next = new ListNode(i);
        cur1 = cur1->next;
    }
    for (auto &i: {5, 6, 1, 8, 4, 5}) {
        cur2->next = new ListNode(i);
        cur2 = cur2->next;
    }
    Solution s = Solution();
    cout << "输入链表1为：\n";
    cout << str1;
    cout << "输入链表2为：\n";
    cout << str2;
    ListNode *res = s.findSuffix(str1, str2);
    cout << "输出结果为：\n";
    cout << res;
    return 1;
}