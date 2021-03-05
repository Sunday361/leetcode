//
// Created by panrenhua on 3/5/21.
//

#ifndef LEETCODE_LEETCODE_200_H
#define LEETCODE_LEETCODE_200_H
#include "allheaders.h"
/**
 * */
class Solution {
public:
    class UnionFind{
    public:
        vector<int> v;
        UnionFind(int n) {
            v.resize(n);
            for (int i = 0; i < n; i++) {
                v[i] = i;
            }
        }
        int findRoot(int k) {
            return (v[k] == k) ? k : v[k] = findRoot(v[k]);
        }
        void Union(int s1, int s2) {
            int r1 = findRoot(s1);
            int r2 = findRoot(s2);

            if (r1 != r2) {
                v[r1] = r2;
            }
        }
        int countRoot() {
            int count = 0;
            for (int i = 0; i < v.size(); i++) {
                count += (v[i] == i);
            }
            return count;
        }
    };
    vector<vector<int>> d{{-1, 0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    count++;
                    continue;
                }
                int nx, ny;
                for (int k = 0; k < 2; k++){
                    nx = i + d[k][0];
                    ny = j + d[k][1];
                    if (nx >= 0 && ny >= 0 && grid[nx][ny] == '1') {
                        uf.Union(n * i + j, n * nx + ny);
                    }
                }
            }
        }

        return uf.countRoot() - count;
    }
};
#endif //LEETCODE_LEETCODE_200_H
