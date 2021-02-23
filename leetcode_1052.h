//
// Created by panrenhua on 2/23/21.
//

#ifndef LEETCODE_LEETCODE_1052_H
#define LEETCODE_LEETCODE_1052_H

#include "allheaders.h"
/** 1052. 爱生气的书店老板
 * */
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0;
        int n = customers.size();
        int count = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (grumpy[i - 1] == 1) grumpy[i - 1] = 0;
            else grumpy[i - 1] = 1;
            dp[i] = dp[i - 1] + customers[i - 1] * grumpy[i - 1];
        }

        for (int i = 0; i < X; i++) {
            ans += customers[i];
        }
        count = ans;
        ans += (dp[n] - dp[X]);
        for (int i = X; i < customers.size(); i++) {
            count += (customers[i] - customers[i - X]);
            int temp = count + (dp[n] - dp[i + 1] + dp[i - X + 1]);

            ans = max(ans, temp);
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_1052_H
