//
// Created by panrenhua on 2/21/21.
//

#ifndef LEETCODE_LEETCODE_1438_H
#define LEETCODE_LEETCODE_1438_H

#include "allheaders.h"
/** 1438. 绝对差不超过限制的最长连续子数组
 *
 * 用两个单调队列来维护最大和最小值, left -> right 之间最大和最小的差值
 * */
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        deque<int> min_que, max_que;
        int left = 0, right = 0, ans = 0;
        while(right < nums.size())
        {
            // 维护窗口内的单调队列的单调性
            while(!min_que.empty() && min_que.back() > nums[right])
                min_que.pop_back();
            min_que.push_back(nums[right]);

            while(!max_que.empty() && max_que.back() < nums[right])
                max_que.pop_back();
            max_que.push_back(nums[right]);
            right++;
            // 对 max - min > limit 情况处理, 当遇到在队列的元素就删除
            while(max_que.front() - min_que.front() > limit)
            {
                if(nums[left] == min_que.front())
                    min_que.pop_front();
                if(nums[left] == max_que.front())
                    max_que.pop_front();
                left++;
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_1438_H
