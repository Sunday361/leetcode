//
// Created by panrenhua on 1/5/21.
//

#ifndef LEETCODE_LEETCODE_39_H
#define LEETCODE_LEETCODE_39_H

#include "allheaders.h"
/** 39. 组合总和
 *
 * 对于 candidates[x] 有 0 - len 种 可能
 * 以此以此来递归
 * */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int index) {
        vector<vector<int>> ans;
        if (target == 0) return {{}};
        if (index == candidates.size()) return ans;

        int len = target / candidates[index];
        for (int j = 0; j <= len; j++) {
            vector<vector<int>> temp = combinationSum(candidates, target - j * candidates[index], index + 1);

            for (auto& v : temp) {
                for (int u = 0; u < j; u++) {
                    v.push_back(candidates[index]);
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSum(candidates, target, 0);
    }
};

#endif //LEETCODE_LEETCODE_39_H
