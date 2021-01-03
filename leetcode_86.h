//
// Created by panrenhua on 1/3/21.
//

#ifndef LEETCODE_LEETCODE_86_H
#define LEETCODE_LEETCODE_86_H

#include "allheaders.h"

/** 86. 分隔链表
 * */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(-1);
        ListNode* p2 = new ListNode(-1);
        ListNode* n1 = p1;
        ListNode* n2 = p2;
        ListNode* p = head;

        while(p) {
            if (p->val < x) {
                n1->next = p;
                n1 = n1->next;
            }else {
                n2->next = p;
                n2 = n2->next;
            }
            p = p->next;
        }
        n2->next = NULL;
        n1->next = p2->next;
        return p1->next;
    }
};

#endif //LEETCODE_LEETCODE_86_H
