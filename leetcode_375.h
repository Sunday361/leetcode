//
// Created by panrenhua on 2021/10/15.
//

#ifndef LEETCODE_LEETCODE_375_H
#define LEETCODE_LEETCODE_375_H
#include "allheaders.h"
/** 375. 猜数字大小 II
 *  转移方程 dp[j][j + i - 1] = min(dp[j][j + i - 1], max(dp[j][k - 1], dp[k + 1][j + i - 1]) + k)
 *
 *  选择 k 时, 极大情况下也可以完成猜迷, 对应到 k 上 在区间 [i, j] 上选择 k 使得总的代价最小
 * */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                dp[j][j + i - 1] = INT32_MAX;
                for (int k = j; k <= j + i - 1; k++) {
                    if (k == j) {
                        dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[k + 1][j + i - 1] + k + 1);
                    }else if (k == j + i - 1) {
                        dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k - 1] + k + 1);
                    }else {
                        dp[j][j + i - 1] = min(dp[j][j + i - 1], max(dp[j][k - 1], dp[k + 1][j + i - 1]) + k + 1);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
#endif //LEETCODE_LEETCODE_375_H
