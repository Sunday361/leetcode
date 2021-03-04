//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_77_H
#define LEETCODE_LEETCODE_77_H

#include "allheaders.h"
/** 77. 组合
 * */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k) return {{}};
        if (n == k) {
            vector<vector<int>> ans(1);
            for (int i = 1; i <= n; i++) {
                ans[0].push_back(i);
            }
            return ans;
        }
        if (k == 1) {
            vector<vector<int>> ans;
            for (int i = 1; i <= n; i++) {
                ans.push_back({i});
            }
            return ans;
        }else {
            auto ans = combine(n - 1, k);
            auto b = combine(n - 1, k - 1);

            for (auto& v : b) {
                v.push_back(n);
            }
            ans.insert(ans.end(), b.begin(), b.end());
            return ans;
        }
    }
};
#endif //LEETCODE_LEETCODE_77_H
