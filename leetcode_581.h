//
// Created by panrenhua on 5/7/21.
//

#ifndef LEETCODE_LEETCODE_581_H
#define LEETCODE_LEETCODE_581_H
#include "allheaders.h"
/** 581. 最短无序连续子数组
 * */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        int l = n, r = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                r = max(r, s.top());
                s.pop();
            }
            s.push(i);
        }

        return r - l > 0 ? r - l + 1: 0;
    }
};
#endif //LEETCODE_LEETCODE_581_H
