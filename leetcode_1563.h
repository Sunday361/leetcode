//
// Created by panrenhua on 3/27/21.
//

#ifndef LEETCODE_LEETCODE_1563_H
#define LEETCODE_LEETCODE_1563_H
#include "allheaders.h"
/** 1563. 石子游戏 V
 * */
class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<int>& p) {
        if (i == j) return dp[i][j] = 0;
        if (dp[i][j] != -1) return dp[i][j];
        int v = 0;
        for (int k = i; k < j; k++) {
            if (p[j + 1] - p[k + 1] > p[k + 1] - p[i]) {
                v = dfs(i, k, p) + p[k + 1] - p[i];
            }else if (p[j + 1] - p[k + 1] < p[k + 1] - p[i]){
                v = dfs(k + 1, j, p) + p[j + 1] - p[k + 1];
            }else {
                v = max(dfs(k + 1, j, p) + p[j + 1] - p[k + 1],
                        dfs(i, k, p) + p[k + 1] - p[i]);
            }
            dp[i][j] = max(dp[i][j], v);
        }

        return dp[i][j];
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preSum(n + 1);

        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + stoneValue[i];
        }
        dp.resize(n, vector<int>(n, -1));
        return dfs(0, n - 1, preSum);
    }
};
#endif //LEETCODE_LEETCODE_1563_H
