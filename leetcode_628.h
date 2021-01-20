//
// Created by panrenhua on 1/20/21.
//

#ifndef LEETCODE_LEETCODE_628_H
#define LEETCODE_LEETCODE_628_H

#include "allheaders.h"
/** 628. 三个数的最大乘积
 * */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[0] * nums[1]);
    }
};

#endif //LEETCODE_LEETCODE_628_H
