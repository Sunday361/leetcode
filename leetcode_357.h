//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_357_H
#define LEETCODE_LEETCODE_357_H
#include "allheaders.h"
/** 357. 计算各个位数不同的数字个数
 * */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 9;
        for (int i = 2; i <= n && i <= 11; i++) {
            dp[i] = dp[i - 1] * (11 - i);
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_357_H
