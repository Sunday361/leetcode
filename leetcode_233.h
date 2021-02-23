//
// Created by panrenhua on 2/23/21.
//

#ifndef LEETCODE_LEETCODE_233_H
#define LEETCODE_LEETCODE_233_H

#include "allheaders.h"

/** 233. 数字 1 的个数
 * */
class Solution {
public:
    int countDigitOne(int n) {
        vector<vector<long>> dp(12, vector<long>(10, 0));
        string s = to_string(n);
        for (int i = 1; i <= 9; i++) dp[1][i] = dp[0][i] = 1;
        for (int i = 2; i <= s.size(); i++) {
            for (int j = 1; j <= 9; j++) {
                if (j == 1) {
                    dp[i][j] = dp[i - 1][9] + dp[i - 1][9];
                    dp[i][j] += pow(10, i - 1);
                }else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][9];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue;
            if (s[i] == '1') {
                if (i != s.size() - 1) {
                    ans += (stoi(s.substr(i + 1)) + 1);
                }
                ans += dp[s.size() - i - 1][9];
            }else {
                ans += dp[s.size() - i][s[i] - '1'];
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_233_H
