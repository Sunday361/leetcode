//
// Created by panrenhua on 3/11/21.
//

#ifndef LEETCODE_LEETCODE_300_H
#define LEETCODE_LEETCODE_300_H
#include "allheaders.h"
/** 300. 最长递增子序列
 * */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }else if (nums[i] == nums[j]){
                    dp[i] = max(dp[i], dp[j]);
                }
            }
        }
        int res = 1;
        for (auto& d: dp) {
            res = max(res, d);
        }
        return res;
    }
};
#endif //LEETCODE_LEETCODE_300_H
