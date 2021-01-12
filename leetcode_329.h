//
// Created by panrenhua on 1/12/21.
//

#ifndef LEETCODE_LEETCODE_329_H
#define LEETCODE_LEETCODE_329_H

#include "allheaders.h"
/** 329. 矩阵中的最长递增路径
 * dfs 做个记忆化存储
 * */
class Solution {
public:
    int u, v;
    int dfs(int x, int y, vector<vector<int>>& m, vector<vector<int>>& depth) {
        if (depth[x][y] != 0) {
            return depth[x][y];
        }else {
            depth[x][y] = 1;
            if (x + 1 < u && m[x][y] > m[x + 1][y]) {
                depth[x][y] = max(dfs(x + 1, y, m, depth) + 1, depth[x][y]);
            }
            if (y + 1 < v && m[x][y] > m[x][y + 1]) {
                depth[x][y] = max(dfs(x, y + 1, m, depth) + 1, depth[x][y]);
            }
            if (x - 1 >= 0 && m[x][y] > m[x - 1][y]) {
                depth[x][y] = max(dfs(x - 1, y, m, depth) + 1, depth[x][y]);
            }
            if (y - 1 >= 0 && m[x][y] > m[x][y - 1]) {
                depth[x][y] = max(dfs(x, y - 1, m, depth) + 1, depth[x][y]);
            }
            return depth[x][y];
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        u = matrix.size();
        v = matrix[0].size();
        vector<vector<int>> depth(u, vector<int>(v, 0));
        int ans = 0;
        for (int i = 0; i < u; i++) {
            for(int j = 0; j < v; j++) {
                if (depth[i][j] != 0) continue;
                ans = max(ans, dfs(i, j, matrix, depth));
            }
        }

        return ans;
    }
};

#endif //LEETCODE_LEETCODE_329_H
