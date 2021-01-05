//
// Created by panrenhua on 1/5/21.
//

#ifndef LEETCODE_LEETCODE_40_H
#define LEETCODE_LEETCODE_40_H

#include "allheaders.h"
/** 40. 组合总和 II
 *
 * 还有一种先排序 然后在循环中通过判断 该层递归中 数字不与 之前的的数字相同 达到去重
 * if (candidates[i] == candidates[i - 1]) continue;
 * */
class Solution {
public:
    unordered_map<int, int> m;
    vector<vector<int>> combinationSum(unordered_map<int, int>& m, int target, unordered_map<int,int>::iterator iter) {
        vector<vector<int>> ans;
        if (target == 0) return {{}};
        if (iter == m.end() || target < 0) return ans;

        int len = iter->second;
        int num = iter->first;
        auto next = ++iter;
        for (int i = 0; i <= len; i++) {
            auto res = combinationSum(m, target - i * num, next);

            for (auto& r : res) {
                for (int u = 0; u < i; u++) {
                    r.push_back(num);
                }
                ans.push_back(r);
            }
        }
        return ans;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto& c : candidates) {
            m[c]++;
        }
        return combinationSum(m, target, m.begin());
    }
};
#endif //LEETCODE_LEETCODE_40_H
