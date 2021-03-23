//
// Created by panrenhua on 3/22/21.
//

#ifndef LEETCODE_LEETCODE_879_H
#define LEETCODE_LEETCODE_879_H
#include "allheaders.h"
/** 879. 盈利计划
 *
 * dp[i][j][k] 人数为i, 最少利润为j, 前k组 可以有多少方案
 * dp[i][j][k] = dp[i][j][k - 1] + dp[i - group[k - 1]][j - profit[k - 1]][k - 1]
 * 有两个地方需要判断,
 * 1. i > group[k - 1]
 *      不成立,说明第 k 个不可以加入
 * 2. j > profit[k - 1]
 *      不成立,说明第 k 个已经可以满足
 *      此时加上 dp[i - group[k - 1]][0][k - 1]
 * */
class Solution {
    int c = 1e9+7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(minProfit+1, vector<int>(group.size()+1, 0)));

        for (int i = 1; i < n+1; i++) {
            for (int j = 0; j < minProfit+1; j++) {
                for (int k = 1; k < group.size()+1; k++) {
                    int tmp = 0;
                    if (i-group[k-1] >= 0) {
                        if (j-profit[k-1] > 0) {
                            tmp = dp[i-group[k-1]][j-profit[k-1]][k-1];
                        } else {
                            tmp = dp[i-group[k-1]][0][k-1]+1;
                        }
                    }
                    dp[i][j][k] = (dp[i][j][k-1] + tmp)%c;
                }
            }
        }
        return !minProfit?dp[n][minProfit][group.size()]+1:dp[n][minProfit][group.size()];
    }
};

#endif //LEETCODE_LEETCODE_879_H
