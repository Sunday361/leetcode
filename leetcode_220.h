//
// Created by panrenhua on 1/9/21.
//

#ifndef LEETCODE_LEETCODE_220_H
#define LEETCODE_LEETCODE_220_H

#include "allheaders.h"
/** 220. 存在重复元素 III
 * */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto pos = s.lower_bound(long(nums[i]) - t);
            if (pos != s.end() && *pos <= long(nums[i]) + t) {
                return true;
            }
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};


#endif //LEETCODE_LEETCODE_220_H
