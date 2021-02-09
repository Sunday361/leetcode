//
// Created by panrenhua on 2/9/21.
//

#ifndef LEETCODE_LEETCODE_992_H
#define LEETCODE_LEETCODE_992_H

#include "allheaders.h"
/** 992. K 个不同整数的子数组
 *  恰好有 K 个不同的子数组 可以理解为 至多 K 个子数组 - 至多 K - 1 个子数组
 *
 *  至多K个子数组 可以考虑在 右端点固定的情况下 最左端点 与右端点的距离
 * */
class Solution {
public:
    int maxSubArraysWithDistinct(vector<int>& A, int k) {
        map<int, int> m;
        int cnt = 0;
        int ans = 0;
        int left = 0, right = 0;
        while (right < A.size()) {
            if (m[A[right]] == 0) {
                cnt++;
            }
            m[A[right]]++;
            right++;
            while (cnt > k) {
                m[A[left]]--;
                if (m[A[left]] == 0) {
                    cnt--;
                }
                left++;
            }

            ans += right - left;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return maxSubArraysWithDistinct(A, K) - maxSubArraysWithDistinct(A, K - 1);
    }
};
#endif //LEETCODE_LEETCODE_992_H
