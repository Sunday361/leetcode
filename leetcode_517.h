//
// Created by panrenhua on 2021/9/29.
//

#ifndef LEETCODE_LEETCODE_571_H
#define LEETCODE_LEETCODE_571_H

#include "allheaders.h"

/** 517. 超级洗衣机
  * */

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = 0;
        for (auto& machine: machines) {
            total += machine;
        }
        int n = machines.size();
        if (total % n != 0) return -1;
        int avg = total / n;
        vector<int> helper(n);
        for (int i = 0; i < n; i++) {
            helper[i] = machines[i] - avg;
        }
        int ans = INT32_MIN;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, abs(helper[i]));
            ans = max(ans, helper[i + 1]);
            helper[i + 1] += helper[i];
        }
        return max(ans, helper[n - 1]);
    }
};
#endif //LEETCODE_LEETCODE_571_H
