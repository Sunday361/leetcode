//
// Created by panrenhua on 2/1/21.
//

#ifndef LEETCODE_LEETCODE_888_H
#define LEETCODE_LEETCODE_888_H

#include "allheaders.h"
/** 888. 公平的糖果棒交换
 *  双指针
 * */
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0;
        for (auto& a: A) {
            sumA += a;
        }
        for (auto& b : B) {
            sumB += b;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        int c = (sumB - sumA) / 2;

        while(i < A.size() && j < B.size()) {
            if (B[j] - A[i] == c) {
                return {A[i], B[j]};
            }else if (B[j] - A[i] > c) {
                i++;
            }else {
                j++;
            }
        }
        return {0, 0};
    }
};

#endif //LEETCODE_LEETCODE_888_H
