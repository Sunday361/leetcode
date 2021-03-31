//
// Created by panrenhua on 3/31/21.
//

#ifndef LEETCODE_LEETCODE_90_H
#define LEETCODE_LEETCODE_90_H
#include "allheaders.h"
/** 90. 子集 II
 * */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;

    void dfs(vector<int>& nums, int k) {
        ans.push_back(v);

        if (k == nums.size()) {
            return;
        }

        for (int i = k; i < nums.size(); i++) {
            if (i > k && nums[i] == nums[i - 1]) {
                continue;
            }
            v.push_back(nums[i]);
            dfs(nums, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        dfs(nums, 0);
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_90_H
