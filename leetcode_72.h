//
// Created by panrenhua on 3/16/21.
//

#ifndef LEETCODE_LEETCODE_72_H
#define LEETCODE_LEETCODE_72_H
#include "allheaders.h"
/** 72. 编辑距离
 * */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT32_MAX / 2));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word2[j - 1] == word1[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }else {
                    // 如果是只替换 dp[i - 1][j - 1]
                    // dp[i - 1][j] 表示删除
                    // dp[i][j - 1] 表示插入
                    // dp[i - 1][j - 1] 表示替换
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
#endif //LEETCODE_LEETCODE_72_H
