//
// Created by panrenhua on 12/28/20.
//

#ifndef LEETCODE_LEETCODE_188_H
#define LEETCODE_LEETCODE_188_H

#include "allheaders.h"
/** 188. 买卖股票的最佳时机 IV
 *
 *  dp[i][j][k] 第i天 完成了第j次交易 k(k = 0 无股票 k = 1 有股票) 获得的最大利润
 *  dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i])
 *  dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i])
 * */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        int ans = 0;
        vector<vector<vector<int>>> dp(days, vector<vector<int>>(k + 1, vector<int>(2, INT32_MIN)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        for (int i = 1; i < days; i++) {
            for (int j = 0; j <= k && j <= (i + 1) / 2; j++) {
                if (j == 0) {
                    dp[i][j][0] = dp[i - 1][j][0];
                }else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                }
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
                ans = max(ans, dp[i][j][0]);
            }
        }

        return ans;
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit(2, prices);
    }
};


#endif //LEETCODE_LEETCODE_188_H
