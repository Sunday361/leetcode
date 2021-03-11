//
// Created by panrenhua on 3/11/21.
//

#ifndef LEETCODE_LEETCODE_673_H
#define LEETCODE_LEETCODE_673_H

#include "allheaders.h"
/** 673. 最长递增子序列的个数
 * */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);  // 以当前字符结尾的最长子序列的个数
        vector<int> Lis(n, 1); // 以当前字符结尾的最长子序列
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (Lis[j] + 1 > Lis[i]) {
                        Lis[i] = Lis[j] + 1;
                        dp[i] = dp[j];
                    }else if (Lis[j] + 1 == Lis[i]){
                        dp[i] += dp[j];
                    }
                }
            }
        }
        int mxl = 1, count = 0;
        for (int i = 0; i < n; i++) {
            if (Lis[i] > mxl) {
                mxl = Lis[i];
                count = dp[i];
            }else if (Lis[i] == mxl){
                count += dp[i];
            }
        }
        return count;
    }
};
#endif //LEETCODE_LEETCODE_673_H
