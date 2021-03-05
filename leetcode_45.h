//
// Created by panrenhua on 3/5/21.
//

#ifndef LEETCODE_LEETCODE_45_H
#define LEETCODE_LEETCODE_45_H

#include "allheaders.h"
/** 45. 跳跃游戏 II
 * */
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int ans = 0;
        int end = 0;
        int maxPos = 0; // 跳ans次可以到达的最远点
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // 在 [end + 1, maxPos] 之间的所有的点 都是通过前一个区间跳ans次
            // 到达的
            maxPos = max(nums[i] + i, maxPos);
            if (i == end)
            {
                end = maxPos;
                ans++;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_45_H
