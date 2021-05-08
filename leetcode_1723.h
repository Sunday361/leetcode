//
// Created by panrenhua on 5/8/21.
//

#ifndef LEETCODE_LEETCODE_1723_H
#define LEETCODE_LEETCODE_1723_H
#include "allheaders.h"
/** 1723. 完成所有工作的最短时间
 * y = i - (1 << x) 求得是 i 除了 x 这一位外的子集
 * 转移方程
 * dp[i][j] = min(max(dp[i - 1][j - x], sum[x])) x 是属于 j 的子集,
 * dp[i][j] 代表 前 i 个工人, 按照 j 的方式来分配
 * */
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<vector<int>> dp(k, vector<int>(1 << n));
        vector<int> sum(1 << n);

        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            sum[i] = sum[y] + jobs[x];
        }

        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = sum[i];
        }

        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int num = INT32_MAX;
                for (int x = j; x; x = (x - 1) & j) { // 这一步求得是 子集,以及 前序状态
                    num = min(num, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = num;
            }
        }

        return dp[k - 1][(1 << n) - 1];
    }
};
#endif //LEETCODE_LEETCODE_1723_H
