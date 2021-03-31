//
// Created by panrenhua on 3/31/21.
//

#ifndef LEETCODE_LEETCODE_1143_H
#define LEETCODE_LEETCODE_1143_H
#include "allheaders.h"
/** 1143. 最长公共子序列
 * */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                }else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                ans = max(dp[i][j], ans);
            }
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_1143_H
