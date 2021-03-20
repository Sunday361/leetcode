//
// Created by panrenhua on 3/20/21.
//

#ifndef LEETCODE_LEETCODE_403_H
#define LEETCODE_LEETCODE_403_H
#include "allheaders.h"
/** 403. 青蛙过河
 * dp[i][k] 代表上一步跳了k格
 * */
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1));
        dp[0][0] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int k = stones[i] - stones[j];

                if (k <= i) {
                    dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];

                    if (i == n - 1 && dp[i][k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
#endif //LEETCODE_LEETCODE_403_H
