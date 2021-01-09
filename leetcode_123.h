//
// Created by panrenhua on 1/9/21.
//

#ifndef LEETCODE_LEETCODE_123_H
#define LEETCODE_LEETCODE_123_H

#include "allheaders.h"
/** 123. 买卖股票的最佳时机 III
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre = prices[0], n = prices.size(), res = 0, maxpf = 0;
        vector<int> dp(n + 1, 0);
        int maxp = prices.back();
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = maxp - prices[i];
            if (prices[i] > maxp) {
                maxp = prices[i];
            }
        }
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - pre > res) {
                res = prices[i] - pre;
            }
            if (prices[i] < pre)
                pre = prices[i];
            if (res + dp[i + 1] > maxpf) {
                maxpf = res + dp[i + 1];
            }
        }
        return maxpf;
    }
};


#endif //LEETCODE_LEETCODE_123_H
