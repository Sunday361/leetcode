//
// Created by panrenhua on 2020/11/25.
//

#ifndef CPP_LEETCODE_239_H
#define CPP_LEETCODE_239_H
#include "allheaders.h"

/** 239. 滑动窗口最大值
 * */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        deque<int> deque;

        for (int i = 0; i < nums.size(); i++) {

            if (!deque.empty() && deque.front() == i-k) deque.pop_front();

            while (!deque.empty() && nums[i] > nums[deque.back()]) deque.pop_back();

            deque.push_back(i);

            if (i >= k-1) res.push_back(nums[deque.front()]);
        }

        return res;
    }
};
#endif //CPP_LEETCODE_239_H
