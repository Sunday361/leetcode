//
// Created by panrenhua on 3/7/21.
//

#ifndef LEETCODE_LEETCODE_132_H
#define LEETCODE_LEETCODE_132_H
#include "allheaders.h"
/** 132. 分割回文串 II
 * */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j + i <= n; j++) {
                if (i == 1) {
                    dp[j][j] = 1;
                }else if (i == 2){
                    dp[j][j + i - 1] = (dp[j] == dp[j + i - 1]);
                }
                dp[j][j + i - 1] = (dp[j] == dp[j + i - 1] && dp[j + 1][j + i - 2]);
            }
        }

        vector<int> dp2(n, INT_MAX);
        dp2[0] = 0;
        for (int i = 1; i < n; i++) {
            if (dp[0][i] == 1) {
                dp2[i] = 0;
            }else {
                for (int k = 1; k <= i; k++) {
                    if (dp[k][i] == 1) {
                        dp2[i] = min(dp2[i], dp2[k - 1] + 1);
                    }
                }
            }
        }
        return dp2[n - 1];
    }
};
#endif //LEETCODE_LEETCODE_132_H
