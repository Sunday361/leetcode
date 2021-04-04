//
// Created by panrenhua on 4/1/21.
//

#ifndef LEETCODE_LEETCODE_1326_H
#define LEETCODE_LEETCODE_1326_H
#include "allheaders.h"
/** 1326. 灌溉花园的最少水龙头数目
 * */
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> dis;
        for (int i = 0; i <= n; i++) {
            int begin = i - ranges[i] >= 0 ? i - ranges[i] : 0;
            int end = i + ranges[i] <= n ? i + ranges[i] : n;
            dis.push_back({begin, end});
        }

        sort(dis.begin(), dis.end(), [&](vector<int>& a, vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int ans = 0;
        int end = -1;
        int maxPos = 0;
        for (int i = 0; i <= n; i++) {
            if (dis[i][0] > maxPos) return -1;
            if (dis[i][0] > end) {
                end = maxPos;
                ans++;
            }
            maxPos = max(dis[i][1], maxPos);
            if (maxPos >= n) break;
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_1326_H
