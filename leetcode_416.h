//
// Created by panrenhua on 3/13/21.
//

#ifndef LEETCODE_LEETCODE_416_H
#define LEETCODE_LEETCODE_416_H
#include "allheaders.h"
/** 416. 分割等和子集
 * */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        /// dp[i][j] 代表 前 i 个数中 和是否可以为 j
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                if (j - nums[i] >= 0)
                    dp[i][j] = (dp[i - 1][j - nums[i]] | dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n - 1][target];
    }

    vector<int> partition(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        int target = sum / 2;
        /// dp[i][j] 代表 前 i 个数中 和是否可以为 j
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                if (j - nums[i] >= 0)
                    dp[i][j] = (dp[i - 1][j - nums[i]] | dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        vector<int> path(n);
        /// 根据 dp 数组 从 dp[n - 1][target] 向前回溯, 剪枝
    }
};
#endif //LEETCODE_LEETCODE_416_H
