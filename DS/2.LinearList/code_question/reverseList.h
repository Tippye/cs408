//
// Created by 渠继旺 on 2023/3/18.
//
#include "LinkList.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};


int TestModule() {
    ListNode *head = new ListNode();
    ListNode *cur = head;
    for (auto &i: {2, 3, -5, 6, -19, 68, 1, -3}) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cout << "输入链表为：\n";
    cout << head;
    Solution s;
    ListNode *res = s.reverseList(head);
    cout << "链表最大值为：\n";
    cout << res;
    delete head;
    return 0;
}
