//
// Created by panrenhua on 3/5/21.
//

#ifndef LEETCODE_LEETCODE_452_H
#define LEETCODE_LEETCODE_452_H
#include "allheaders.h"
/** 452. 用最少数量的箭引爆气球
 * */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {return a[0] < b[0];}
            return a[1] < b[1];
        });
        int count = 0;
        vector<int> p;
        for (auto& point : points) {
            if (p.size() == 0) {
                p = point;
                count++;
            }else {
                if (point[0] > p[1]) {
                    p = point;
                    count++;
                }else {
                    p[0] = point[0];
                    p[1] = min(p[1], point[1]);
                }
            }
        }

        return count;
    }
};
#endif //LEETCODE_LEETCODE_452_H
