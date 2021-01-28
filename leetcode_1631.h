//
// Created by panrenhua on 1/29/21.
//

#ifndef LEETCODE_LEETCODE_1631_H
#define LEETCODE_LEETCODE_1631_H

#include "allheaders.h"
/** 1631. 最小体力消耗路径
 * sol1 : 用并查集构建最小生成树
 * sol2 : 二分查找 最小的路径
 * sol3 : dijkstra算法求单源最短路径
 * */
class Solution {
public:
    class UniFind {
    public:
        vector<int> v;
        vector<int> sz;

        UniFind(int n) {
            v.resize(n, 0);
            sz.resize(n, 0);

            for (int i = 0; i < n; i++) {
                v[i] = i;
            }
        }
        int findRoot(int x) {
            return x == v[x] ? x : (v[x] = findRoot(v[x]));
        }
        bool isConnect(int x, int y) {
            return findRoot(x) == findRoot(y);
        }
        bool Union(int x, int y){
            int rx = findRoot(x);
            int ry = findRoot(y);

            if (rx != ry) {
                v[rx] = ry;
                return true;
            }
            return false;
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        struct e{
            int x, y;
            int l;
        };
        UniFind uf(r * c);
        vector<struct e> edges;
        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c; j++) {
                edges.push_back({i * c + j, (i + 1) * c + j, abs(heights[i + 1][j] - heights[i][j])});
            }
        }

        for (int i = 0; i < c - 1; i++) {
            for (int j = 0; j < r; j++) {
                edges.push_back({j * c + i, j * c + i + 1, abs(heights[j][i + 1] - heights[j][i])});
            }
        }

        sort(edges.begin(), edges.end(), [&](e& e1, e& e2){
            return e1.l < e2.l;
        });

        for (auto& e : edges) {
            //cout << e.x << e.y << e.l << endl;
            uf.Union(e.x, e.y);
            if (uf.isConnect(0, r * c - 1)) {
                return e.l;
            }
        }
        return 0;
    }
};

#endif //LEETCODE_LEETCODE_1631_H
