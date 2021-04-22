//
// Created by panrenhua on 4/22/21.
//

#ifndef LEETCODE_LEETCODE_363_H
#define LEETCODE_LEETCODE_363_H
#include "allheaders.h"
/** 363. 矩形区域不超过 K 的最大数值和
 * 一维数组 区间和 不大于 K 的方法, 用一个 set 记录 已有的区间和的值, 然后lower_bound二分查找, 找出大于等于 目标值 - 当前值 的
 * 区间, 每次比较大小, 即可以计算出最后的值
 * */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i][j - 1] + preSum[i - 1][j] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        auto sum = [&](int r1, int c1, int r2, int c2) {
            return preSum[r1][c1] - preSum[r1][c2] - preSum[r2][c1] + preSum[r2][c2];
        };

        int ans = INT32_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                set<int> st;
                st.insert(0);

                for (int u = 1; u <= m; u++) {
                    int s = sum(0, i, u, j);
                    auto it = st.lower_bound(s - k);
                    if (it != st.end()) {
                        ans = max(ans, s - *it);
                    }
                    st.insert(s);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_363_H
