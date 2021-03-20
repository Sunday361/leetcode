//
// Created by panrenhua on 3/20/21.
//

#ifndef LEETCODE_LEETCODE_695_H
#define LEETCODE_LEETCODE_695_H
#include "allheaders.h"
/** 695. 岛屿的最大面积
 * */
class Solution {
public:
    vector<vector<int>> dir{{0,1},{1,0}};
    class UnionFind{
    public:
        vector<int> f;
        vector<int> sz;

        UnionFind(int x) {
            f.resize(x);
            for (int i = 0; i < x; i++) {
                f[i] = i;
            }
            sz.resize(x, 0);
        }

        void Union(int x, int y) {
            int rx = findRoot(x);
            int ry = findRoot(y);

            if (rx != ry) {
                f[rx] = ry;
                sz[ry] += sz[rx];
            }
        }

        int findRoot(int x) {
            return x == f[x] ? x : f[x] = findRoot(f[x]);
        }
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                uf.sz[i * n + j] = (uf.sz[i * n + j] == 0 ? 1 : uf.sz[i * n + j]);
                for (int k = 0; k < 2; k++) {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];

                    if (nx < m && ny < n && grid[nx][ny] == 1) {
                        uf.sz[nx * n + ny] = (uf.sz[nx * n + ny] == 0 ? 1 : uf.sz[nx * n + ny]);
                        uf.Union(i * n + j, nx * n + ny);
                    }
                }
            }
        }
        int ans = 0;
        for (auto& num : uf.sz) {
            ans = max(ans, num);
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_695_H
