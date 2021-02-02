//
// Created by panrenhua on 2/2/21.
//

#ifndef LEETCODE_LEETCODE_209_H
#define LEETCODE_LEETCODE_209_H

#include "allheaders.h"
/** 209. 长度最小的子数组
 * */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int cnt = nums.size() + 1;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum >= s && l <= r) {
                cnt = min(cnt, r - l + 1);
                sum -= nums[l];
                l++;
            }
            if (l > r) r = l;
            else {
                r++;
            }
        }
        return cnt == nums.size() + 1 ? 0 : cnt;
    }
};
#endif //LEETCODE_LEETCODE_209_H
