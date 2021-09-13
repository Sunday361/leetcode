//
// Created by panrenhua on 2021/9/13.
//

#ifndef LEETCODE_LEETCODE_447_H
#define LEETCODE_LEETCODE_447_H
#include "allheaders.h"
/**
 * 447. 回旋镖的数量
 * */
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> m(n, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<int, int> dist;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (m[i][j] == -1) {
                    m[i][j] = m[j][i] = (points[j][1] - points[i][1]) * (points[j][1] - points[i][1])
                                        + (points[j][0] - points[i][0]) * (points[j][0] - points[i][0]);
                }

                dist[m[i][j]]++;
            }

            for (auto& [_, v] : dist) {
                ans += v * (v - 1);
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_447_H
