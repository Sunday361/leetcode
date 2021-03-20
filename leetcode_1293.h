//
// Created by panrenhua on 3/19/21.
//

#ifndef LEETCODE_LEETCODE_1293_H
#define LEETCODE_LEETCODE_1293_H
#include "allheaders.h"
/** 1293. 网格中的最短路径
 * flags,设置成 k + 1的 数组来记录访问位,对应访问该点时所剩的可消除次数
 * */
class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        queue<vector<int>> q;
        vector<vector<int>> flags(m * n, vector<int>(k + 1, -1));
        q.push({0,0,k});
        flags[0][k] = 1;
        int level = 0;
        while (!q.empty()) {
            int l = q.size();
            for (int j = 0; j < l; j++) {
                vector<int> f = q.front();
                q.pop();
                if (f[0] == m - 1 && f[1] == n - 1) return level;
                for (int i = 0; i < 4; i++) {
                    int nx = f[0] + dir[i][0];
                    int ny = f[1] + dir[i][1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (grid[nx][ny] == 1 && f[2] == 0) {
                            continue;
                        }
                        if (grid[nx][ny] == 1 && flags[nx * n + ny][f[2] - 1] == -1) {
                            q.push({nx, ny, f[2] - 1});
                            flags[nx * n + ny][f[2] - 1] = 1;
                        }else if (grid[nx][ny] == 0 && flags[nx * n + ny][f[2]] == -1){
                            q.push({nx, ny, f[2]});
                            flags[nx * n + ny][f[2]] = 1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
#endif //LEETCODE_LEETCODE_1293_H
