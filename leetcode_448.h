//
// Created by panrenhua on 2/13/21.
//

#ifndef LEETCODE_LEETCODE_448_H
#define LEETCODE_LEETCODE_448_H

#include "allheaders.h"
/** 448. 找到所有数组中消失的数字
 * */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        nums.push_back(0);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                while (nums[i] != i && nums[i] != nums[nums[i]]) {
                    swap(nums[i], nums[nums[i]]);
                }
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_448_H
