//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_115_H
#define LEETCODE_LEETCODE_115_H

#include "allheaders.h"
/** 115. 不同的子序列
 *  中间结果会超int
 * */
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        vector<vector<long>> dp(m + 1, vector<long>(n + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] != t[j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
#endif //LEETCODE_LEETCODE_115_H
