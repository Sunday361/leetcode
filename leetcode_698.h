//
// Created by panrenhua on 3/15/21.
//

#ifndef LEETCODE_LEETCODE_698_H
#define LEETCODE_LEETCODE_698_H
#include "allheaders.h"
/** 698. 划分为k个相等的子集
 * 状态压缩dp
 * */
class Solution {
    int dp[(1 << 16) + 2];
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        fill(dp,dp+(1<<16)+2,-1);
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        if (sum % k != 0) return false;
        int target = sum / k;
        dp[0] = 0;
        for(int mask = 0; mask < (1 << n);mask++){
            if(dp[mask] == -1) continue;
            for(int i = 0;i < n;i++){
                if(!(mask & (1 << i)) && dp[mask] + nums[i] <= target) /// 选取的nums[i] 和现在已有的加起来组合成一个未满的数组
                /// 且这个数组的数之和不可以超过target, 否则是不满足条件的
                    dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target; //能否刚好为0
            }
        }
        return dp[(1 << n) - 1] == 0; //  所有书取到
    }
};
#endif //LEETCODE_LEETCODE_698_H
