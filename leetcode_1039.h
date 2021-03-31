//
// Created by panrenhua on 3/31/21.
//

#ifndef LEETCODE_LEETCODE_1039_H
#define LEETCODE_LEETCODE_1039_H
#include "allheaders.h"
/** 1039. 多边形三角剖分的最低得分
 * */
class Solution {
public:
    int dfs(vector<vector<int>>& dp, vector<int>& v, int i, int j) {
        if (dp[i][j] != INT_MAX) return dp[i][j];
        if (j - i < 2) return dp[i][j] = 0;
        if (j - i == 2) {
            return dp[i][j] = v[i] * v[i + 1] * v[i + 2];
        }
        int res;
        for (int k = i + 1; k < j; k++) {
            res = dfs(dp, v, i, k) + v[i] * v[k] * v[j] + dfs(dp, v, k, j);
            dp[i][j] = min(res, dp[i][j]);
        }
        return dp[i][j];
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        return dfs(dp, values, 0, n - 1);
    }

    int dp_MinScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j + i <= n; j++) {
                if (i <= 2) {
                    dp[j][j + i - 1] = 0;
                    continue;
                }
                for (int k = j + 1; k < i + j - 1; k++) {
                    dp[j][j + i - 1] = min(dp[j][j + i - 1],
                                           dp[j][k] + dp[k][j + i - 1] + values[j] * values[k] * values[j + i - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
#endif //LEETCODE_LEETCODE_1039_H
