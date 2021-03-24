//
// Created by panrenhua on 3/24/21.
//

#ifndef LEETCODE_LEETCODE_456_H
#define LEETCODE_LEETCODE_456_H
#include "allheaders.h"
/** 456. 132 模式
 *
 * 用一个数组存储 一个数左边最小的值, 用一个单调栈存储依次递减的数
 * 当栈中有比当前元素大的数, 查看是否满足 132原则
 * */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> lm(nums.size());
        int m = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            lm[i] = m;
            m = min(m, nums[i]);
        }
        vector<int> s;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.back()] <= nums[i]) {
                s.pop_back();
            }
            if (!s.empty() && lm[s.back()] < nums[i]) {
                return true;
            }
            s.push_back(i);
        }
        return false;
    }
};
#endif //LEETCODE_LEETCODE_456_H
