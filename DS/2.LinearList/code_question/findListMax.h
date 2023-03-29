//
// Created by 渠继旺 on 2023/3/18.
//
#include "LinkList.h"

class Solution {
public:
    int findListMax_recursion(ListNode *list) {
        return list ? max(list->val, findListMax_recursion(list->next)) : INT_MIN;
    }

    int findListMax(ListNode *list) {
        if(!list) return NULL;
        ListNode* pa = list->next;
        int max = list->val;
        while (pa){
            max = max<pa->val?pa->val:max;
//            if (max<pa->val) {
//                max = pa->val;
//            }
            pa = pa->next;
        }
        return max;
    }
};


int TestModule() {
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for (auto& i : {2, 3, -5, 6, -19, 68, 1, -3}) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cout << "输入链表为：\n";
    cout << head;
    Solution s;
    int res = s.findListMax(head);
    cout << "链表最大值为：\n";
    cout << res;
    delete head;
    return 0;
}
