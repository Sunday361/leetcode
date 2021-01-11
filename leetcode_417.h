//
// Created by panrenhua on 1/11/21.
//

#ifndef LEETCODE_LEETCODE_417_H
#define LEETCODE_LEETCODE_417_H

#include "allheaders.h"
/** 417. 太平洋大西洋水流问题
 *
 * 两遍dfs 写死个人
 * */
#define CONDITION1 (f == 1 && x == 0) || (f == 2 && x == m - 1)
#define CONDITION2 (f == 1 && y == 0) || (f == 2 && y == n - 1)
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> ans;
    void dfs(int x, int y, int f, vector<vector<int>>& matrix, vector<vector<int>>& flag) {
        if (flag[x][y] == f) {
            return;
        }else {
            if (f == 2 && flag[x][y] == 1) {
                ans.push_back({x, y});
            }
            flag[x][y] = f;
            if (x + 1 < m && (matrix[x + 1][y] >= matrix[x][y] || CONDITION2)) {
                dfs(x + 1, y, f, matrix, flag);
            }
            if (y + 1 < n && (matrix[x][y + 1] >= matrix[x][y] || CONDITION1)) {
                dfs(x, y + 1, f, matrix, flag);
            }
            if (x - 1 >= 0 && (matrix[x - 1][y] >= matrix[x][y] || CONDITION2)) {
                dfs(x - 1, y, f, matrix, flag);
            }
            if (y - 1 >= 0 && (matrix[x][y - 1] >= matrix[x][y] || CONDITION1)) {
                dfs(x, y - 1, f, matrix, flag);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return ans;
        m = matrix.size(); n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dfs(0, 0, 1, matrix, dp);
        dfs(m - 1, n - 1, 2, matrix, dp);
        return ans;
    }
};


#endif //LEETCODE_LEETCODE_417_H
