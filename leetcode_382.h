//
// Created by panrenhua on 3/30/21.
//

#ifndef LEETCODE_LEETCODE_382_H
#define LEETCODE_LEETCODE_382_H
#include "allheaders.h"
/** 382. 链表随机节点
 *
 * 蓄水池算法 : 在一串长度为 N 的数组中随机选取 M 个元素
 * 设置蓄水池为 M , 当池子个数不满时, 放入池子, 当池子已满, 目前元素为 i
 * 选取 d = [1,i] 的随机数, 若 d 在 [1, M] 之间, 将池子的 第d个元素替换为 nums[i],
 * */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */

    ListNode* h;
    Solution(ListNode* head) {
        h = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* p = h;

        int res = p->val;

        p = p->next;
        int index = 1;

        while (p) {
            index++;

            int random = rand() % index;
            if (random == 0) {
                res = p->val;
            }

            p = p->next;
        }

        return res;
    }
};
#endif //LEETCODE_LEETCODE_382_H
