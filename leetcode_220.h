//
// Created by panrenhua on 1/9/21.
//

#ifndef LEETCODE_LEETCODE_220_H
#define LEETCODE_LEETCODE_220_H

#include "allheaders.h"
/** 220. 存在重复元素 III
 * 每个桶放 [x - t, x + t] 的元素
 * */
class Solution {
public:
    int getId(int num, long t) {
        return num >= 0 ? num / t : (num + 1LL) / t - 1;
    }
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            long x = nums[i];
            int id = getId(x, t + 1LL);

            if (mp.count(id)) {
                return true;
            }

            if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) {
                return true;
            }

            if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) {
                return true;
            }

            mp[id] = x;
            if (i >= k) {
                mp.erase(getId(nums[i - k], t + 1LL));
            }
        }
        return false;
    }
};


#endif //LEETCODE_LEETCODE_220_H
