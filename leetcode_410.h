//
// Created by panrenhua on 1/29/21.
//

#ifndef LEETCODE_LEETCODE_410_H
#define LEETCODE_LEETCODE_410_H

#include "allheaders.h"
/** 410. 分割数组的最大值
 *  tips: 是分割成连续的非空子数组
 *  最小的最大值
 *  left = max(nums[i]), right = sum(nums)
 *  二分查找 找到满足条件的值
 * */
class Solution {
public:
    long long right = 0, left = 0;
    /// 检查将 nums 分割成值不超过 mid 的 n个子数组是否成立
    bool check(vector<int>& nums, int mid, int n) {
        int count = 1;
        int sum = 0;
        for (auto& num : nums) {
            if (num + sum > mid) {
                count++;
                sum = num;
            }else {
                sum += num;
            }
        }
        return count <= n;
    }
    int splitArray(vector<int>& nums, int m) {
        for (auto& num : nums) {
            right += num;
            left = left < num ? num : left;
        }
        while(left < right) {
            long long mid = left + (right - left) / 2;

            if (check(nums, mid, m)) {
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};
#endif //LEETCODE_LEETCODE_410_H
