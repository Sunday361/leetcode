//
// Created by panrenhua on 4/16/21.
//

#ifndef LEETCODE_LEETCODE_87_H
#define LEETCODE_LEETCODE_87_H
#include "allheaders.h"
/** 87. 扰乱字符串
 *
 * dp[i][j][k] 代表 s1[i] s2[j] 开始的长度为 k 的字符串, 是否可以转换
 * */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        vector<vector<vector<bool>>> dp(33, vector<vector<bool>>(33, vector<bool>(33)));
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j][1] = true;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            for (int u = 0; u <= n - i; u++) {
                for (int v = 0; v <= n - i; v++) {
                    for (int k = 1; k < i; k++) {
                        if (dp[u][v][k] && dp[u + k][v + k][i - k]) {
                            dp[u][v][i] = true;
                            break;
                        }

                        if (dp[u][v + i - k][k] && dp[u + k][v][i - k]) {
                            dp[u][v][i] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};
#endif //LEETCODE_LEETCODE_87_H
