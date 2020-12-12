//
// Created by panrenhua on 2020/12/12.
//

#ifndef LEETCODE_LEETCODE_330_H
#define LEETCODE_LEETCODE_330_H


#include "allheaders.h"
/** 330. 按要求补齐数组
 *
 * 对于数组 [1, n) 可以 产生 [1, 2n - 1]
 *
 * 所以当我们遍历区间的时候， 若当前元素 小于我们的期望值 则可以表达的区间就加上当前元素， 如果大于我们的期望值，
 * 则加上我们的期望值 并将元素x2 获得新的期望值。
 * */

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0, i = 0;
        long miss = 1; // use long to avoid integer overflow error
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) // miss is covered
                miss += nums[i++];
            else { // patch miss to the array
                miss += miss;
                patches++; // increase the answer
            }
        }
        return patches;
    }
};

#endif //LEETCODE_LEETCODE_330_H
