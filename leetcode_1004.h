//
// Created by panrenhua on 2/19/21.
//

#ifndef LEETCODE_LEETCODE_1004_H
#define LEETCODE_LEETCODE_1004_H

#include "allheaders.h"
/** 1004. 最大连续1的个数 III
 * */
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0;
        int count = 0;
        int ans = 0;
        while (right < A.size()) {
            if (A[right] == 0) {
                count++;
                if (count > K) {
                    while (left <= right && A[left] == 1) {
                        left++;
                    }
                    if (A[left] == 0 && left <= right) {
                        count--;
                        left++;
                    }
                }
            }
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_1004_H
