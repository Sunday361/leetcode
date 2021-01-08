//
// Created by panrenhua on 1/8/21.
//

#ifndef LEETCODE_LEETCODE_189_H
#define LEETCODE_LEETCODE_189_H

#include "allheaders.h"
/** 189. 旋转数组
 * */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

#endif //LEETCODE_LEETCODE_189_H
