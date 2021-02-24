//
// Created by panrenhua on 2/24/21.
//

#ifndef LEETCODE_LEETCODE_10_H
#define LEETCODE_LEETCODE_10_H

#include "allheaders.h"
/** 10. 正则表达式匹配
 * */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 0) {
                    if (p[j - 1] == '*') {
                        dp[i][j] = dp[i][j - 2];
                    }
                }else {
                    if (p[j - 1] == '*') {
                        if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                            dp[i][j] = dp[i][j] | dp[i - 1][j];
                        }
                        dp[i][j] = dp[i][j] | dp[i][j - 2] | dp[i][j - 1];
                    }else if (p[j - 1] == s[i - 1] || p[j - 1] == '.'){
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
#endif //LEETCODE_LEETCODE_10_H
