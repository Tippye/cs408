//
// Created by 渠继旺 on 2023/3/18.
//
#include "LinkList.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == NULL) return list1;
        if (list2 == NULL) return list2;
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else if (list1->val > list2->val) {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        } else {
            list1->next = mergeTwoLists(list1->next, list2->next);
            return list1;
        }
    }
};

int TestModule() {
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    for (auto &i: {1, 2, 4}) {
        cur1->next = new ListNode(i);
        cur1 = cur1->next;
    }
    for (auto &i: {1, 3, 4}) {
        cur2->next = new ListNode(i);
        cur2 = cur2->next;
    }
    cout << "输入链表1为：\n";
    cout << l1;
    cout << "输入链表2为：\n";
    cout << l2;
    Solution s;
    ListNode *res = s.mergeTwoLists(l1, l2);
    cout << "输出结果链表为：\n";
    cout << res;
    return 0;
}