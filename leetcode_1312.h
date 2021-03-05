//
// Created by panrenhua on 3/5/21.
//

#ifndef LEETCODE_LEETCODE_1312_H
#define LEETCODE_LEETCODE_1312_H
#include "allheaders.h"
/** 1312. 让字符串成为回文串的最少插入次数
 * */
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j + i <= n; j++) {
                if (i == 1) {dp[j][j] = 0;continue;}
                dp[j][j + i - 1] = min(dp[j + 1][j + i - 1], dp[j][j + i - 2]) + 1;
                if (s[j] == s[j + i - 1]) {
                    dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j + 1][j + i - 2]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
#endif //LEETCODE_LEETCODE_1312_H
