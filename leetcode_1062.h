//
// Created by panrenhua on 3/31/21.
//

#ifndef LEETCODE_LEETCODE_1062_H
#define LEETCODE_LEETCODE_1062_H
#include "allheaders.h"
/** 1062. 最长重复子串
 * */
class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int n = S.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                if (S[i - 1] == S[j - 1]) {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
                ans = max(dp[i][j], ans);
            }
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_1062_H
