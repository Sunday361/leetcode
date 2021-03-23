//
// Created by panrenhua on 3/22/21.
//

#ifndef LEETCODE_LEETCODE_312_H
#define LEETCODE_LEETCODE_312_H
#include "allheaders.h"
/** 312. 戳气球
 * dp[i][j] 是将 i -> j 范围内气球戳破得到的最大钱币数
 * 转移方程是 dp[i][j] = max(dp[i][k - 1] + dp[k + 1][j] + v[i - 1] * v[j + 1] * v[k]) i<=k<=j
 * */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 1));
        vector<int> v(n + 2, 1);
        for (int i = 0; i < nums.size(); i++) {
            v[i + 1] = nums[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j + i <= n + 1; j++) {
                for (int k = j; k <= j + i - 1; k++) {
                    dp[j][j + i - 1] = max(dp[j][k - 1] + dp[k + 1][j + i - 1] + v[j - 1] * v[k] * v[j + i], dp[j][j + i - 1]);
                }
            }
        }

        return dp[1][n];
    }
};
#endif //LEETCODE_LEETCODE_312_H
