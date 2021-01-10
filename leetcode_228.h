//
// Created by panrenhua on 1/10/21.
//

#ifndef LEETCODE_LEETCODE_228_H
#define LEETCODE_LEETCODE_228_H

#include "allheaders.h"
/** 228. 汇总区间
 * */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1]) {
                if (nums[i] == nums[j]) {
                    ans.push_back(to_string(nums[i]));
                }else {
                    ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
                }
                j = i + 1;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_228_H
