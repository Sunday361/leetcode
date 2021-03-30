//
// Created by panrenhua on 3/30/21.
//

#ifndef LEETCODE_LEETCODE_871_H
#define LEETCODE_LEETCODE_871_H
#include "allheaders.h"
/** 871. 最低加油次数
 * */
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<long long> dp(stations.size() + 1);

        dp[0] = startFuel;

        for (int i = 0; i < stations.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }

        for (int i = 0; i <= stations.size(); i++) {
            if (dp[i] >= target) return i;
        }
        return -1;


    }
    /// 堆做法
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        int tank = startFuel;
        int pos = 0;
        for (auto& s : stations) {
            tank -= ()
        }
    }
};
#endif //LEETCODE_LEETCODE_871_H
