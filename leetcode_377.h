//
// Created by panrenhua on 4/24/21.
//

#ifndef LEETCODE_LEETCODE_377_H
#define LEETCODE_LEETCODE_377_H
#include "allheaders.h"
/** 377. 组合总和 Ⅳ
 * */
class Solution {
public:
    int dfs(vector<int>& dp, vector<int>& nums, int target) {
        if (dp[target] != -1) return dp[target];
        if (target == 0) return dp[0] = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                ans += dfs(dp, nums, target - nums[i]);
            }
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return dfs(dp, nums, target);
    }
};
#endif //LEETCODE_LEETCODE_377_H
