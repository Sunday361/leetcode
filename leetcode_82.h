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
        ListNode* p = nullptr;
        ListNode* cur = head;
        ListNode* rear = p;

        while (cur) {
            ListNode* n = cur->next;
            int flag = 0;
            while (n && n->val == cur->val) {
                n = n->next;
                flag = 1;
            }

            if (flag) {
                cur = n;
            }else {
                if (!rear) {
                    p = rear = cur;
                }else {
                    rear->next = cur;
                    rear = rear->next;
                }
                cur = cur->next;
            }
        }
        return p;
    }
};

#endif //LEETCODE_LEETCODE_82_H
