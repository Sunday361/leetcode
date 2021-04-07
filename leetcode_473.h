//
// Created by panrenhua on 4/7/21.
//

#ifndef LEETCODE_LEETCODE_473_H
#define LEETCODE_LEETCODE_473_H
#include "allheaders.h"
/** 473. 火柴拼正方形
 * 状态压缩,
 * dp[i] 代表 i 对应的二进制数, 比如 26 对应 1 1010 代表取了 第 0, 1, 3 个之后, 当前多余的数量
 * if (!(mask & (1 << i)) && dp[mask] + nums[i] <= target) {
 *      dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
 * }
 * 应当注意, 桶中的剩余数量不可能大于target 因为属性并不可分
 * 以及 第i个元素不应该被取过
 * * */
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }

        if (sum % 4 != 0) return false;
        int target = sum / 4;
        int n = nums.size();
        vector<int> dp((1 << n) + 2, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) && dp[mask] + nums[i] <= target) {
                    dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
                }
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};
#endif //LEETCODE_LEETCODE_473_H
