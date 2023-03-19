//
// Created by 渠继旺 on 2023/3/18.
//
#include "LinkList.h"

class Solution {
public:
    ListNode *mixTwoLists(ListNode *A, ListNode *B) {
        ListNode *pa = A->next; // A链表指针
        ListNode *pb = B->next; // B链表指针
        ListNode *pc = A;       // A链表父结点指针

        // 其中一个到结尾时循环停止
        while (pa && pb) {
            if (pa->val == pb->val) {
                // 两个节点相同时，保留A链表中的节点
                pc->next = pa;
                // 保留A链表中的节点后pc指针向后移动
                pc = pa;

                // 因为AB链表两项相同，所以都向后移动一位
                pa = pa->next;
                pb = pb->next;
            } else if (pa->val < pb->val) {
                // 如果A链表的节点比B链表的节点小，就删除A链表中的节点，因为两个链表是按顺序排的，pa后边可能有与pb相同的节点，所以只删除pa
                // 删除方法就是pc的next指向pa的next，这样就会跳过pa
                // pa向后移动一位，pc位置不变，因为pa被删除所以pa向后移动一位后依然是pc的下一位
                pa = pa->next;
                pc->next = pa;
            } else {
                // 如果A链表的节点比B链表的节点大，就删除B链表中的节点，因为两个链表是按顺序排的，pb后边可能有与pa相同的节点，所以只删除pb
                // 删除方法就是pc的next指向pb的next，这样就会跳过pb
                // pb向后移动一位，pc位置不变，因为pb被删除所以pb向后移动一位后依然是pc的下一位
                pb = pb->next;
                pc->next = pb;
            }
        }
        // 循环结束，到这里可能是因为B链表到了结尾，但A链表还没到结尾，所以要把pc后面的节点都删掉，直接让pc的next指向空
        pc->next = nullptr;
        // 被删除的节点和B链表系统会进行回收
        return A;
    }
};


int TestModule() {
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    for (auto &i: {1, 2, 3, 4, 5, 6, 7}) {
        cur1->next = new ListNode(i);
        cur1 = cur1->next;
    }
    for (auto &i: {2, 3, 5, 7}) {
        cur2->next = new ListNode(i);
        cur2 = cur2->next;
    }
    cout << "输入链表1为：\n";
    cout << l1;
    cout << "输入链表2为：\n";
    cout << l2;
    Solution s;
    s.mixTwoLists(l1, l2);
    cout << "输出结果链表为：\n";
    cout << l1;
    return 0;
}