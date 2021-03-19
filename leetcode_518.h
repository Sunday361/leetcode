//
// Created by panrenhua on 3/19/21.
//

#ifndef LEETCODE_LEETCODE_518_H
#define LEETCODE_LEETCODE_518_H

#include "allheaders.h"
/** 518. 零钱兑换 II
 * */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][amount];
    }
};
#endif //LEETCODE_LEETCODE_518_H
