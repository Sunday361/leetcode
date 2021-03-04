//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_15_H
#define LEETCODE_LEETCODE_15_H

#include "allheaders.h"
/** 15. 三数之和
 * */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {continue;}
            int k = i + 1, j = nums.size() - 1;

            while(k < j) {
                if (nums[k] + nums[j] > -nums[i]) {
                    j--;
                }else if (nums[k] + nums[j] < -nums[i]) {
                    k++;
                }else {
                    ans.push_back({nums[i], nums[k], nums[j]});
                    k++; j--;
                    while (k < j && nums[k] == nums[k - 1]) {
                        k++;
                    }
                    while (k < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_15_H
