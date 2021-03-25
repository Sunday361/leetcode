//
// Created by panrenhua on 3/25/21.
//

#ifndef LEETCODE_LEETCODE_1388_H
#define LEETCODE_LEETCODE_1388_H
#include "allheaders.h"

/** 1388. 3n 块披萨
 * 类似于打家劫舍II
 * 分别去掉 头,尾, 计算从 n 个元素中取出 m 个不相邻元素可以获得的最大值
 * dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i]);
 * */
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int m = n / 3;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 2][j - 1] + slices[i - 1], dp[i - 1][j]);
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i >= 2)
                    dp[i][j] = max(dp[i - 2][j - 1] + slices[i - 1], dp[i - 1][j]);
                else
                    dp[i][j] = max(slices[i - 1], dp[i - 1][j]);
            }
        }

        return max(dp[n - 1][m], dp[n][m]);
    }
};
#endif //LEETCODE_LEETCODE_1388_H
