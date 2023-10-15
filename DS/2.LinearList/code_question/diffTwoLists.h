//
// Created by Tippy on 2023/8/24.
//
#include "LinkList.h"

class Solution {
public:
    ListNode *diffTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *p1 = list1->next;
        ListNode *p2 = list2->next;
        ListNode *pre = list1;

        while (p1 && p2) {
            if (p1->val == p2->val) {
                pre->next = p1->next;
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->val > p2->val) {
                ListNode *temp = p2;
                p2 = p2->next;
                pre->next = temp;
                temp->next = p1;
                pre = pre->next;
            } else {
                pre = p1;
                p1 = p1->next;
            }
        }
        if (!p1)
            pre->next = p2;

        return list1;
    }
};

int TestModule() {
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    for (auto &i: {1,3,4,5,7}) {
        cur1->next = new ListNode(i);
        cur1 = cur1->next;
    }
    for (auto &i: {3,4,5,6,7,8}) {
        cur2->next = new ListNode(i);
        cur2 = cur2->next;
    }
    cout << "输入链表1为：\n";
    cout << l1;
    cout << "输入链表2为：\n";
    cout << l2;
    Solution s;
    ListNode *res = s.diffTwoLists(l1, l2);
    cout << "输出结果链表为：\n";
    cout << res;
    return 0;
}