//
// Created by panrenhua on 2/4/21.
//

#ifndef LEETCODE_LEETCODE_162_H
#define LEETCODE_LEETCODE_162_H

#include "allheaders.h"
/** 162. 寻找峰值
 * 判断 mid - 1, mid, mid + 1 的关系
 * */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        int left = 0, right = n;
        while(left < right) {
            int mid = (left + right) / 2;
            if (mid == 0 && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid == n && nums[mid] > nums[mid - 1]) {
                return mid;
            }
            if (mid > 0 && mid < n && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[mid] > nums[mid + 1]) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};

#endif //LEETCODE_LEETCODE_162_H
