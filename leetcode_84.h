//
// Created by panrenhua on 2020/12/26.
//

#ifndef LEETCODE_LEETCODE_84_H
#define LEETCODE_LEETCODE_84_H

#include "allheaders.h"
/** 84. 柱状图中最大的矩形
 * 对于每个矩形 i, 用left[i], right[i] 存储其左右可以到达的范围
 * 用 单调栈保存 当前矩形之前的矩形, 单调栈是一个递增的单调栈
 * */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> stack;
        for (int i = 0; i < n; ++i) {
            while(stack.size() != 0 && heights[i] <= heights[stack.back()]) {
                right[stack.back()] = i;
                stack.pop_back();
            }
            left[i] = stack.size() == 0 ? -1 : stack.back();
            stack.push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_84_H
