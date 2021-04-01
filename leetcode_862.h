//
// Created by panrenhua on 3/25/21.
//

#ifndef LEETCODE_LEETCODE_862_H
#define LEETCODE_LEETCODE_862_H
#include "allheaders.h"
/** 862. 和至少为 K 的最短子数组
 *
 * 用一个双端队列保存 前缀和, 当队尾元素不满足条件时, pop_back
 * 从队头元素开始, 依次遍历满足条件的位置, 然后pop_front
 * */
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + A[i];
        }

        deque<int> dq;
        int ans = INT32_MAX;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && preSum[i] <= preSum[dq.back()]) {
                dq.pop_back();
            }

            while (!dq.empty() && preSum[i] - preSum[dq.front()] >= K) {
                int l = i - dq.front();
                if (l < ans) {
                    ans = l;
                }
                dq.pop_front();
            }

            dq.push_back(i);
        }
        return ans == INT32_MAX ? -1 : ans;
    }
};
#endif //LEETCODE_LEETCODE_862_H
