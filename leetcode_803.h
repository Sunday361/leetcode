//
// Created by panrenhua on 1/16/21.
//

#ifndef LEETCODE_LEETCODE_803_H
#define LEETCODE_LEETCODE_803_H

#include "allheaders.h"
/** 803. 打砖块
 *
 * 逆序的并查集 设置一个特殊的节点,与此节点相连 代表处于稳定的状态
 * */
class Solution {
public:
    vector<int> dp;
    vector<int> counts;
    int findRoot(int x) {
        return x == dp[x] ? x : (dp[x] = findRoot(dp[x]));
    }
    void Union(int x, int y) {
        int r1 = findRoot(x);
        int r2 = findRoot(y);

        if (r1 != r2) {
            dp[r1] = r2;
            counts[r2] += counts[r1];
        }
    }
    vector<vector<int>> d = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> ans(hits.size(), 0);
        vector<int> bricks(hits.size(), 0);
        int m = grid.size(), n = grid[0].size();
        int N = m * n;
        dp.resize(N + 1, 0);
        counts.resize(N + 1, 1);
        for (int i = 0; i <= N; i++) {
            dp[i] = i;
        }

        for (int i = 0; i < hits.size(); i++) {
            if (grid[hits[i][0]][hits[i][1]] == 1) {
                grid[hits[i][0]][hits[i][1]] = 0;
                bricks[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) Union(i, N);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (grid[i - 1][j] == 1) {
                        Union(n * i + j, n * (i - 1) + j);
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        Union(n * i + j, n * i + j - 1);
                    }
                }
            }
        }

        for (int i = bricks.size() - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];

            if (bricks[i] == 0) continue;

            int prev = counts[findRoot(N)];

            if (r == 0) {
                Union(r * n + c, N);
            }
            for (int j = 0; j < 4; j++) {
                int nr = r + d[j][0], nc = c + d[j][1];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    if (grid[nr][nc] == 1)
                        Union(r * n + c, nr * n + nc);
                }
            }
            grid[r][c] = 1;
            int next = counts[findRoot(N)];
            ans[i] = max(next - prev - 1, 0);
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_803_H
