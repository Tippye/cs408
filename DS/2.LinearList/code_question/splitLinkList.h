//
// Created by 渠继旺 on 2023/3/18.
//
#include "./LinkList.h"

class Solution {
public:
vector<ListNode*> splitListToParts(ListNode* head) {
    // 用来存放结果的两个链表
    vector<ListNode *> result(2, nullptr);
    // head有头结点所以令pa指向head的next
    ListNode *pa = head->next;
    // B、C链表为结果链表
    ListNode *B = new ListNode();
    ListNode *C = new ListNode();
    // 将B、C链表的头结点放到数组中
    result[0] = B;
    result[1] = C;

    // 循环A链表
    while (pa) {
        if (pa->val < 0){
            // 如果pa是负数，就存放到B链表
            B->next = pa;
            B = B->next;
        }else{
            // 如果pa是正数，就存放到C链表
            C->next = pa;
            C = C->next;
        }
        // 存放后让pa指针后移
        pa = pa->next;
    }
    // 将B、C节点的next指向空（下面的测试例子，如果这里不指向空，C会指向A链表的倒数第二项，导致A链表的最后一项也会在C链表中）
    B->next = nullptr;
    C->next = nullptr;
    return result;
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
    vector<ListNode*> res = s.splitListToParts(head);
    cout << "输出B链表为：\n";
    cout << res[0];
    cout << "输出C链表为：\n";
    cout << res[1];
    delete head;
    return 0;
}
