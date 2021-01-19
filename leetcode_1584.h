//
// Created by panrenhua on 1/19/21.
//

#ifndef LEETCODE_LEETCODE_1584_H
#define LEETCODE_LEETCODE_1584_H

#include "allheaders.h"
/** 1584. 连接所有点的最小费用
 * 最小生成树算法
 * */
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int m = points.size();
        vector<vector<int>> edges(m, vector<int>(m));

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                edges[i][j] = edges[j][i] = (abs(points[j][1] - points[i][1]) + abs(points[j][0] - points[i][0]));
            }
        }
        vector<int> dist(m, INT32_MAX);
        vector<int> flags(m, 0);
        int ans = 0;
        dist[0] = 0;
        while (1) {
            int u = -1;
            int max = INT32_MAX;
            for (int j = 0; j < m; j++) {
                if (flags[j] == 0 && dist[j] < max) {
                    max = dist[j];
                    u = j;
                }
            }
            if (u == -1) break;
            ans += dist[u];
            flags[u] = 1;

            for (int i = 0; i < m; i++) {
                if (edges[i][u] < dist[i] && flags[i] == 0) {
                    dist[i] = edges[i][u];
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_1584_H
