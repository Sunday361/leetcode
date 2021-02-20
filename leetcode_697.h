//
// Created by panrenhua on 2/20/21.
//

#ifndef LEETCODE_LEETCODE_697_H
#define LEETCODE_LEETCODE_697_H

#include "allheaders.h"
/** 697. 数组的度
 * */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        int count = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            m2[nums[i]]++;
            if (m1.count(nums[i]) == 0) {
                m1[nums[i]] = i;
                if (m2[nums[i]] > count)
                    ans = 1;
            }else {
                if (m2[nums[i]] > count) {
                    count = m2[nums[i]];
                    ans = i - m1[nums[i]] + 1;
                }else if (m2[nums[i]] == count && i - m1[nums[i]] + 1 < ans) {
                    ans = i - m1[nums[i]] + 1;
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_697_H
