//
// Created by panrenhua on 4/23/21.
//

#ifndef LEETCODE_LEETCODE_368_H
#define LEETCODE_LEETCODE_368_H
#include "allheaders.h"
/** 368. 最大整除子集
 * dp 然后 通过前趋节点, 向前回溯, 找到完整的序列
 * 转移方程是   dp[i] = max(dp[i], dp[j] + 1) (0 <= j < i - 1)
 * */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pre(n, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        int p = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] > dp[p]) {
                p = i;
            }
        }
        int index = p;
        vector<int> ans;
        while (pre[index] != index) {
            // cout << index <<" " << pre[index] << endl;
            ans.push_back(nums[index]);
            index = pre[index];
        }
        ans.push_back(nums[index]);
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_368_H
