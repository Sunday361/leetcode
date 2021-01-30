//
// Created by panrenhua on 1/29/21.
//

#ifndef LEETCODE_LEETCODE_778_H
#define LEETCODE_LEETCODE_778_H

#include "allheaders.h"
/** 778. 水位上升的泳池中游泳
 * 最短路径 dijkstra
 * */
class Solution {
public:
    vector<vector<int>> direction{{1,0},{-1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dist(n * n, INT32_MAX);
        vector<int> flag(n * n, 0);
        dist[0] = grid[0][0];
        for (int i = 0; i < n * n; i++) {
            int min = INT32_MAX;
            int t = -1;
            for (int u = 0; u < n * n; u++) {
                if (dist[u] < min && flag[u] == 0) {
                    min = dist[u];
                    t = u;
                }
            }
            if (t == -1) break;
            flag[t] = 1;
            int x = t / n, y = t % n;
            for (int u = 0; u < 4; u++) {
                int nx = direction[u][0] + x, ny = direction[u][1] + y;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && flag[nx * n + ny] == 0) {
                    dist[nx * n + ny] = dist[t] >= grid[nx][ny] ? dist[t] : grid[nx][ny];
                }
            }
            if (flag[n * n - 1] == 1) return dist[n * n - 1];
        }
        return 0;
    }
};
// 二分查找
class Solution2 {
public:
    vector<vector<int>> direction{{1,0},{-1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = grid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                right = max(right, grid[i][j]);
            }
        }
        while(left < right) {
            int mid = (left + right) >> 1;
            vector<int> flag(n * n, 0);
            queue<vector<int>> q;
            q.push({0, 0});
            while(!q.empty()) {
                auto f = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = direction[i][0] + f[0];
                    int ny = direction[i][1] + f[1];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && flag[nx * n + ny] != 1 && grid[nx][ny] <= mid) {
                        q.push({nx, ny});
                        flag[nx * n + ny] = 1;
                    }
                }
                if (flag[n * n - 1] == 1) {
                    right = mid;
                    break;
                }
            }
            if (flag[n * n - 1] == 0) {
                left = mid + 1;
            }
        }
        return right;
    }
};
#endif //LEETCODE_LEETCODE_778_H
