//
// Created by panrenhua on 1/20/21.
//

#ifndef LEETCODE_LEETCODE_82_H
#define LEETCODE_LEETCODE_82_H

#include "allheaders.h"
/** 82. 删除排序链表中的重复元素 II
 * */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;
        ListNode* n = head;
        ListNode* prev = head;
        while(n) {
            m[n->val]++;
            n = n->next;
        }
        ListNode* h = new ListNode(0);
        ListNode* p = h;
        n = head;
        while(n) {
            ListNode* t = n;
            n = n->next;
            if (m[t->val] == 1) {
                p->next = t;
                t->next = nullptr;
                p = p->next;
            }
        }

        return h->next;
    }
};

#endif //LEETCODE_LEETCODE_82_H
