//
// Created by panrenhua on 1/21/21.
//

#ifndef LEETCODE_LEETCODE_80_H
#define LEETCODE_LEETCODE_80_H

#include "allheaders.h"
/** 80. 删除排序数组中的重复项 II
 * */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[pre] && count == 1) {
                nums[pre + 1] = nums[i];
                pre = pre + 1;
                count = 2;
            }else if (nums[i] != nums[pre]){
                nums[pre + 1] = nums[i];
                pre = pre + 1;
                count = 1;
            }
        }

        nums.erase(nums.begin() + pre + 1, nums.end());
        return nums.size();
    }
};
#endif //LEETCODE_LEETCODE_80_H
