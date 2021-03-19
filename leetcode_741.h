//
// Created by panrenhua on 3/18/21.
//

#ifndef LEETCODE_LEETCODE_741_H
#define LEETCODE_LEETCODE_741_H
#include "allheaders.h"
/** 741. 摘樱桃
 *  两个人同时出发 (i, j) (k, l) dp[i][j][k] 为 摘的草莓最大值
 *  i,j,k,l 满足 i + j = k + l
 * */
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(m, vector<int>(m, -1)));
        return max(0, dfs(grid, 0, 0, 0, dp));
    }
    // 主要在于 某个点到 右下角的最大值已经被确定后,之后的访问直接取值即可
    int dfs(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int l = i + j - k;

        if (i >= n || j >= n || k >= n || l >= n || l < 0 || grid[i][j] == -1 || grid[k][l] == -1) {
            return INT32_MIN;
        }
        // 已经访问过该点
        if (dp[i][j][k] != -1) return dp[i][j][k];
        // 到达 右下角
        if (i == n - 1 && j == n - 1 && k == n - 1) return dp[i][j][k] = grid[i][j];
        int res = max(max(dfs(grid, i + 1, j, k + 1, dp), dfs(grid, i + 1, j, k, dp)),
                      max(dfs(grid, i, j + 1, k + 1, dp), dfs(grid, i, j + 1, k, dp)));

        res += grid[i][j] + grid[k][l] + (i == k && j == l && grid[i][j] == 1 ? -1 : 0);
        return dp[i][j][k] = res;
    }
};
#endif //LEETCODE_LEETCODE_741_H
