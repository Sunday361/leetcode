//
// Created by panrenhua on 2/18/21.
//

#ifndef LEETCODE_LEETCODE_995_H
#define LEETCODE_LEETCODE_995_H
#include "allheaders.h"
/** 995. K 连续位的最小翻转次数
 * 差分数组
 * 732. 我的日程安排表 III
 * 1094. 拼车
 * 1109. 航班预订统计
 * 1589. 所有排列中的最大和
 * 1674. 使数组互补的最少操作次数
 * */

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size();
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= K && A[i - K] > 1) {
                revCnt ^= 1;
                A[i - K] -= 2; // 复原数组元素，若允许修改数组 A，则可以省略
            }
            if (A[i] == revCnt) {
                if (i + K > n) {
                    return -1;
                }
                ++ans;
                revCnt ^= 1;
                A[i] += 2;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_995_H
