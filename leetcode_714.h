//
// Created by panrenhua on 2020/12/17.
//

#ifndef LEETCODE_LEETCODE_714_H
#define LEETCODE_LEETCODE_714_H

#include "allheaders.h"
/** 714. 买卖股票的最佳时机含手续费
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0]; // 有股票
        dp[0][1] = 0;           // 没股票
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};

#endif //LEETCODE_LEETCODE_714_H
